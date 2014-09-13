/**
 * @file ChartsWidget.cpp
 *
 * Kontrolka zarządzania wykresami - implementacja.
 *
 * @author Zbigniew Siciarz
 * @date 2009-2010
 * @version 0.8.2
 * @since 0.4.0
 */

#include "ChartsWidget.h"

#include "ui_ChartsWidget.h"
#include "formats/FormatFactory.h"
#include "plots/WaveformPlot.h"
#include "plots/SpectrogramPlot.h"
#include "plots/DurationScaleDraw.h"
#include "plots/FrequencyScaleDraw.h"
#include "plots/SpectrogramPlotZoomer.h"
#include "plots/SpectrogramData.h"
#include "plots/DtwData.h"
#include "plots/FeatureData.h"
#include "SimpleBirdSettings.h"
#include <qwt_plot_marker.h>
#include <qwt_scale_widget.h>
#include <QDesktopServices>
#include <QFileDialog>
#include <QFileInfo>
#include <QFontMetrics>
#include <QList>
#include <QPainter>
#include <QPrinter>
#include <QPrintDialog>


/**
 * Konstruktor - tworzy kontrolkę wykresów.
 *
 * @param parent obiekt rodzica
 */
ChartsWidget::ChartsWidget(QWidget *parent):
    QWidget(parent),
    ui(new Ui::ChartsWidget), chartsCount(0)
{
    ui->setupUi(this);

    menu = new QMenu(tr("Charts"), this);
    menu->addAction(ui->actionSave);
    menu->addAction(ui->actionRefresh);
    menu->addAction(ui->actionPrint);
    menu->addAction(ui->actionCloseAll);

    connect(ui->tabCharts, SIGNAL(tabCloseRequested(int)), SLOT(closeChart(int)));
    connect(ui->btnGoToWorkspace, SIGNAL(clicked()), SLOT(goToWorkspace()));

    connect(ui->actionSave, SIGNAL(triggered()), SLOT(saveChart()));
    ui->btnSave->setDefaultAction(ui->actionSave);
    connect(ui->actionRefresh, SIGNAL(triggered()), SLOT(refresh()));
    ui->btnRefresh->setDefaultAction(ui->actionRefresh);
    connect(ui->actionPrint, SIGNAL(triggered()), SLOT(print()));
    ui->btnPrint->setDefaultAction(ui->actionPrint);
    connect(ui->actionCloseAll, SIGNAL(triggered()), SLOT(closeAllCharts()));
    ui->btnCloseAll->setDefaultAction(ui->actionCloseAll);
    updateUi();
}

/**
 * Usuwa obiekt interfejsu użytkownika.
 */
ChartsWidget::~ChartsWidget()
{
    delete ui;
}

/**
 * Przechwytuje zdarzenie naciśnięcia klawisza.
 *
 * Reaguje na kombinację Ctrl+W - zamyka bieżącą kartę.
 *
 * @param event obiekt informacji o zdarzeniu
 */
void ChartsWidget::keyPressEvent(QKeyEvent* event)
{
    if (event->modifiers() & Qt::ControlModifier)
    {
        switch (event->key())
        {
        case Qt::Key_W:
            closeChart(ui->tabCharts->currentIndex());
            return;
        }
    }

    QWidget::keyPressEvent(event);
}

/**
 * Rysuje przebieg nagrania z obiektu typu WaveFile.
 *
 * @param wavefile wskaźnik do obiektu nagrania
 */
void ChartsWidget::drawWaveform(Aquila::WaveFile* wavefile)
{
    WaveformPlot* plotWaveform = new WaveformPlot(this);
    SimpleBirdSettings settings;
    plotWaveform->setColor(settings.getWaveformColor());
    plotWaveform->setWaveFile(wavefile);

    QFileInfo info(QString::fromStdString(wavefile->getFilename()));
    addPlot(plotWaveform, tr("%1 - waveform").arg(info.fileName()));
    emit sendMessage(tr("Drawn waveform: %1").arg(info.fileName()));
}

/**
 * Rysuje spektrogram z obiektu typu WaveFile.
 *
 * @param wavefile wskaźnik do obiektu nagrania
 */
void ChartsWidget::drawSpectrogram(Aquila::WaveFile* wavefile)
{
    SpectrogramData data(wavefile);
    if (data.isCanceled())
    {
        emit sendMessage(tr("Spectrogram canceled"));
        return;
    }

    SpectrogramPlot* plot = new SpectrogramPlot(this);
    // w przypadku tradycyjnego spektrogramu, na lewej osi częstotliwość
    FrequencyScaleDraw* freqSD = new FrequencyScaleDraw();
    freqSD->setSampleFrequency(wavefile->getSampleFrequency());
    freqSD->setSpectrumSize(wavefile->getSamplesPerFrameZP());
    plot->setAxisScaleDraw(QwtPlot::yLeft, freqSD);
    // minimalna szerokość lewej osi, żeby wykres nie skakał
    const QFontMetrics fm(plot->axisWidget(QwtPlot::yLeft)->font());
    freqSD->setMinimumExtent(fm.width("10000000 Hz"));
    // przypisanie danych
    plot->setSpectrogramData(data);
    // skalowanie osi intensywności
    plot->setAxisScale(QwtPlot::yRight, data.range().minValue(), data.range().maxValue());
    // zoomer musi być utworzony po przypisaniu danych
    SpectrogramPlotZoomer* zoomer = new SpectrogramPlotZoomer(plot->canvas());
    SimpleBirdSettings settings;
    zoomer->setFrameLength(settings.getFrameLength());
    zoomer->setFrameOverlap(settings.getOverlap());
    zoomer->setSampleFrequency(wavefile->getSampleFrequency());
    zoomer->setSpectrumSize(wavefile->getSamplesPerFrameZP());

    plot->setTitle(tr("File: %1").arg(wavefile->getFilename().c_str()));

    QFileInfo info(QString::fromStdString(wavefile->getFilename()));
    QString spectrogramInfo = tr("%1 (%2)").arg(info.fileName()).arg(data.getInfo());

    // add a detailed overlay, but only when requested in settings
    if (settings.addOverlay())
    {
        plot->setExtraCaption(spectrogramInfo, 0, wavefile->getSamplesPerFrameZP()/2);
    }

    addPlot(plot, tr("%1 - spectrogram").arg(info.fileName()));
    emit sendMessage(tr("Drawn spectrogram: %1").arg(spectrogramInfo));
}

/**
 * Rysuje "spektrogram" cech obliczonych przez podany ekstraktor.
 *
 * Ekstraktor już nie wykonuje obliczeń, zakładamy że dane są już gotowe.
 * Jedyne obliczenia wykonywane są w klasie FeatureData, która szuka maksimum
 * i minimum potrzebnego do wyskalowania spektrogramu.
 *
 * @param extractor obiekt ekstraktora cech
 */
void ChartsWidget::drawFeatureChart(Aquila::Extractor* extractor)
{
    FeatureData data(extractor);
    if (data.isCanceled())
    {
        emit sendMessage(tr("Feature chart canceled"));
        return;
    }

    SpectrogramPlot* plot = new SpectrogramPlot(this);
    // minimalna szerokość lewej osi, żeby wykres nie skakał
    const QFontMetrics fm(plot->axisWidget(QwtPlot::yLeft)->font());
    plot->axisScaleDraw(QwtPlot::yLeft)->setMinimumExtent(fm.width("100"));
    // przypisanie danych
    plot->setSpectrogramData(data);
    // skalowanie osi intensywności
    plot->setAxisScale(QwtPlot::yRight, data.getMinParam(), data.getMaxParam());

    plot->setTitle(tr("File: %1, feature type: %2").
        arg(extractor->getWaveFilename().c_str()).
        arg(extractor->getType().c_str()));
    QFileInfo info(QString::fromStdString(extractor->getWaveFilename()));
    QString featureInfo = tr("%1 (%2)").arg(info.fileName()).arg(data.getInfo());

    // add a detailed overlay, but only when requested in settings
    SimpleBirdSettings settings;
    if (settings.addOverlay())
    {
        plot->setExtraCaption(featureInfo, 0, extractor->getParamsPerFrame());
    }

    addPlot(plot, tr("%1 - feature chart").arg(info.fileName()));
    emit sendMessage(tr("Drawn feature chart: %1").arg(featureInfo));
}

/**
 * Rysuje diagram DTW.
 *
 * Ekstraktor już nie wykonuje obliczeń, zakładamy że dane są już gotowe.
 * Funkcja dobiera sobie drugi obiekt ekstraktora.
 *
 * @param extractor obiekt ekstraktora cech
 */
void ChartsWidget::drawDtwChart(Aquila::Extractor* extractor)
{
    QString patternFile = QFileDialog::getOpenFileName(this, tr("Choose pattern file"),
        "L:\\_ptaki", FormatFactory::getFeatureFormatsFilter());
    if (patternFile.isEmpty())
        return;

    Aquila::Extractor* pattern = FormatFactory::readIntoExtractor(patternFile);
    if (!extractor->isCompatible(pattern))
    {
        emit sendMessage(tr("Feature files are incompatible with each other!"));
        delete pattern;
        return;
    }
    DtwData data(extractor, pattern);

    SpectrogramPlot* plot = new SpectrogramPlot(this);

    // skalowanie lewej osi w jednostkach czasu
    DurationScaleDraw* dsd = new DurationScaleDraw();
    dsd->setFrameLength(pattern->getFrameLength());
    dsd->setFrameOverlap(0.66); // FIXME
    plot->setAxisScaleDraw(QwtPlot::yLeft, dsd);
    // minimalna szerokość lewej osi, żeby wykres nie skakał
    const QFontMetrics fm(plot->axisWidget(QwtPlot::yLeft)->font());
    plot->axisScaleDraw(QwtPlot::yLeft)->setMinimumExtent(fm.width("10000 ms"));

    plot->setSpectrogramData(data);
    // skalowanie osi odległości
    plot->axisWidget(QwtPlot::yRight)->setTitle(tr("Distance"));
    plot->setAxisScale(QwtPlot::yRight, data.range().minValue(), data.range().maxValue());

    plot->setTitle(tr("DTW chart: %1 against %2").
        arg(QFileInfo(extractor->getWaveFilename().c_str()).fileName()).
        arg(QFileInfo(pattern->getWaveFilename().c_str()).fileName()));

    QString dtwInfo = data.getInfo();
    SimpleBirdSettings settings;
    // add a detailed overlay, but only when requested in settings
    if (settings.addOverlay())
    {
        plot->setExtraCaption(dtwInfo, 0, pattern->getFramesCount());
    }

    delete pattern;

    addPlot(plot, tr("DTW chart"));
    emit sendMessage(tr("Drawn DTW chart: %1").arg(dtwInfo));
}

/**
 * Zapisuje aktualnie wyświetlony wykres do pliku.
 */
void ChartsWidget::saveChart()
{
    QString filter = "PNG image (*.png);;JPG Image (*.jpg);;Bitmap (*.bmp)";
    QString directory = QDesktopServices::storageLocation(QDesktopServices::PicturesLocation);

    //QFileInfo info(QString::fromStdString(wav->getFilename()));
    QString imageFilename = "chart";//info.baseName();
    imageFilename.append(".png");
    QString file = QFileDialog::getSaveFileName(this,
        tr("Save chart"), directory + "/" + imageFilename, filter);
    if (file.isEmpty())
        return;

    QPixmap::grabWidget(ui->tabCharts->currentWidget()).save(file);
    emit sendMessage(tr("Chart saved to %1").arg(file));
}

/**
 * Odświeża bieżący wykres.
 */
void ChartsWidget::refresh()
{
    QwtPlot* plot = static_cast<QwtPlot*>(ui->tabCharts->currentWidget());
    plot->replot();
    emit sendMessage(tr("Chart refreshed"));
}

/**
 * Drukuje bieżący wykres.
 */
void ChartsWidget::print()
{
    QPrinter printer;
    printer.setPaperSize(QPrinter::A4);
    QWidget* plot = ui->tabCharts->currentWidget();
    if (plot->width() > plot->height())
        printer.setOrientation(QPrinter::Landscape);
    else
        printer.setOrientation(QPrinter::Portrait);

    QPrintDialog* dlg = new QPrintDialog(&printer, this);
    if (dlg->exec() == QDialog::Accepted)
    {
        emit sendMessage(tr("Printing..."));
        QPainter p(&printer);
        p.drawPixmap(0, 0, QPixmap::grabWidget(plot));
    }
}

/**
 * Dodaje nowy wykres do kontrolki.
 *
 * Sprawdza, ile jest aktualnie wyświetlonych wykresów. Jeśli więcej niż 0,
 * chowa kartę początkową.
 *
 * @param plot wskaźnik do wykresu
 * @param tabLabel tytuł zakładki na pasku
 */
void ChartsWidget::addPlot(QwtPlot* plot, QString tabLabel)
{
    int index = ui->tabCharts->addTab(plot, tabLabel);
    plot->replot();
    ui->tabCharts->setCurrentIndex(index);
    emit chartAdded(index);

    chartsCount++;
    updateUi();
    if (chartsCount > 0)
        ui->tabCharts->removeTab(ui->tabCharts->indexOf(ui->tabInitial));
}

/**
 * Zamyka kartę o podanym indeksie.
 *
 * Jeśli liczba wykresów spadła do zera, przywraca kartę początkową.
 *
 * @param index indeks karty
 */
void ChartsWidget::closeChart(int index)
{
    QWidget* tab = ui->tabCharts->widget(index);
    // cannot close the initial page
    if (tab == ui->tabInitial)
        return;

    ui->tabCharts->removeTab(index);
    delete tab;
    emit chartRemoved(index);

    chartsCount--;
    updateUi();
    if (chartsCount <= 0)
        ui->tabCharts->addTab(ui->tabInitial, tr("No charts"));
}

/**
 * Zamyka wszystkie wykresy.
 */
void ChartsWidget::closeAllCharts()
{
    QList<QWidget*> tabs = ui->tabCharts->findChildren<QWidget*>();
    foreach(QWidget* tab, tabs)
    {
        closeChart(ui->tabCharts->indexOf(tab));
    }
    chartsCount = 0;
    updateUi();
}

/**
 * Wysyła żądanie przejścia do przestrzeni roboczej.
 */
void ChartsWidget::goToWorkspace()
{
    emit goToWorkspaceRequested();
}

/**
 * Aktualizuje interfejs zależnie od stanu kontrolki.
 */
void ChartsWidget::updateUi()
{
    ui->actionSave->setEnabled(chartsCount > 0);
    ui->actionRefresh->setEnabled(chartsCount > 0);
    ui->actionPrint->setEnabled(chartsCount > 0);
    ui->actionCloseAll->setEnabled(chartsCount > 0);
}
