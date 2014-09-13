/**
 * @file FilesWidget.cpp
 *
 * Kontrolka zarządzająca aktualnie otwartymi plikami - implementacja.
 *
 * @author Zbigniew Siciarz
 * @date 2009-2010
 * @version 0.8.2
 * @since 0.6.0
 */

#include "FilesWidget.h"

#include "ui_FilesWidget.h"
#include "aquila/Exceptions.h"
#include "aquila/feature/ExtractorFactory.h"
#include "formats/FormatFactory.h"
#include "SimpleBirdSettings.h"
#include <QFileInfo>
#include <QtAlgorithms>


/**
 * Tworzy kontrolkę plików, łączy zdarzenia przycisków i listy.
 *
 * @param parent obiekt rodzica
 */
FilesWidget::FilesWidget(QWidget *parent):
    QWidget(parent),
    ui(new Ui::FilesWidget), unsavedCount(0)
{
    ui->setupUi(this);

    connect(ui->listFiles, SIGNAL(currentItemChanged(QListWidgetItem*, QListWidgetItem*)),
            SLOT(currentItemChanged(QListWidgetItem*, QListWidgetItem*)));
    connect(ui->listFiles, SIGNAL(doubleClicked(QModelIndex)), SLOT(doubleClicked(QModelIndex)));

    connect(ui->btnWaveform, SIGNAL(clicked()), SLOT(waveformClicked()));
    connect(ui->btnDrawSpectrogram, SIGNAL(clicked()), SLOT(spectrogramClicked()));
    connect(ui->btnDrawFeatureChart, SIGNAL(clicked()), SLOT(featureChartClicked()));
    connect(ui->btnDrawDtwChart, SIGNAL(clicked()), SLOT(dtwChartClicked()));
    connect(ui->btnCloseFile, SIGNAL(clicked()), SLOT(closeCurrentFile()));

    updateUi();
}

/**
 * Usuwa obiekt interfejsu, oraz wszystkie aktualnie otwarte obiekty plików dźwiekowych i cech.
 */
FilesWidget::~FilesWidget()
{
    delete ui;
    qDeleteAll(wavefiles);
    qDeleteAll(extractors);
}

/**
 * Zwraca nazwę aktualnie zaznaczonego pliku, lub pusty łańcuch znaków.
 *
 * @return nazwa pliku lub pusty QString, gdy nic nie zaznaczono
 */
QString FilesWidget::currentFile() const
{
    QListWidgetItem* item = ui->listFiles->currentItem();
    if (!item)
        return QString();

    return item->data(Qt::UserRole).toString();
}

/**
 * Zwraca typ aktualnie zaznaczonego pliku.
 *
 * @return jedna z wartości wyliczenia FileType
 */
FilesWidget::FileType FilesWidget::currentFileType() const
{
    QFileInfo fi(currentFile());
    QString extension = fi.suffix().toUpper();
    if ("WAV" == extension)
        return Wave;
    else if ("BIR" == extension || "XML" == extension)
        return Feature;

    if (currentFile().startsWith(tr("Unsaved")))
        return Feature;

    return Unknown;
}

/**
 * Sprawdza, czy plik o podanej nazwie jest obecnie wczytany.
 *
 * @param filename pełna nazwa pliku
 * @return true jeśli taki plik został wczytany
 */
bool FilesWidget::hasFile(QString filename)
{
    return loadedFiles.contains(filename, Qt::CaseInsensitive);
}

/**
 * Zwraca aktualny obiekt pliku dźwiękowego.
 *
 * @return wskaźnik do obiektu lub wartość zerowa, gdy bieżący plik to nie wave
 */
Aquila::WaveFile* FilesWidget::currentWaveFile() const
{
    if (currentFileType() != Wave)
        return 0;

    return wavefiles[currentFile()];
}

/**
 * Rozkazuje "przeliczyć się" wszystkim otwartym obiektom nagrań.
 *
 * @param frameLength długość ramki w milisekundach
 * @param overlap wartość nakładki
 */
void FilesWidget::recalculateWaveFiles(unsigned int frameLength, double overlap)
{
    foreach (Aquila::WaveFile* wav, wavefiles)
    {
        wav->recalculate(frameLength, overlap);
    }
}

/**
 * Zwraca aktualny obiekt ekstraktora.
 *
 * @return wskaźnik do obiektu lub wartość zerowa, gdy bieżący plik nie jest plikiem cech
 */
Aquila::Extractor* FilesWidget::currentExtractor() const
{
    if (currentFileType() != Feature)
        return 0;

    return extractors[currentFile()];
}

/**
 * Wczytuje plik o podanej nazwie.
 *
 * Sprawdza rozszerzenie pliku, deleguje odczyt do wyspecjalizowanej metody,
 * na koniec dodaje nowy element do listy.
 *
 * @param filename pełna ścieżka do pliku
 */
void FilesWidget::addFile(QString filename)
{
    QFileInfo fi(filename);
    QString extension = fi.suffix().toUpper();
    try
    {
        if ("WAV" == extension)
        {
            loadWaveFile(filename);
        }
        else if ("BIR" == extension || "XML" == extension)
        {
            loadFeatureFile(filename, extension);
        }
    }
    catch (Aquila::Exception& e)
    {
        emit sendMessage(QString::fromStdString(e.what()));
        return;
    }

    QListWidgetItem* item = new QListWidgetItem(fi.fileName());
    item->setData(Qt::UserRole, filename);
    item->setIcon(QIcon(":/icons/page.png"));
    ui->listFiles->addItem(item);
    ui->listFiles->setCurrentItem(item);
    loadedFiles.append(filename);
}

void FilesWidget::addExtractor(Aquila::Extractor *extractor)
{
    QString filename = tr("Unsaved %1").arg(++unsavedCount);
    extractors[filename] = extractor;
    
    QListWidgetItem* item = new QListWidgetItem(filename);
    item->setData(Qt::UserRole, filename);
    item->setIcon(QIcon(":/icons/page.png"));
    ui->listFiles->addItem(item);
    ui->listFiles->setCurrentItem(item);
    loadedFiles.append(filename);
}

/**
 * Ładuje plik WAVE o podanej nazwie.
 *
 * @param filename nazwa pliku
 */
void FilesWidget::loadWaveFile(const QString& filename)
{
    SimpleBirdSettings settings;
    unsigned int frameLength = settings.getFrameLength();
    double overlap = settings.getOverlap();

    Aquila::WaveFile* wav = new Aquila::WaveFile(frameLength, overlap);
    wav->load(filename.toStdString());
    wavefiles[filename] = wav;
    emit waveformRequested(wav);

    emit sendMessage(tr("Wave file %1 loaded successfully").arg(filename));
}

/**
 * Wczytuje plik cech.
 *
 * @param filename nazwa pliku
 * @param format format pliku - podpowiedź na podstawie rozszerzenia
 */
void FilesWidget::loadFeatureFile(const QString& filename, const QString& format)
{
    Aquila::Extractor* extractor = FormatFactory::readIntoExtractor(filename, format);
    extractors[filename] = extractor;

    emit sendMessage(tr("Reading with settings: %1, %2 ms, %3 params per frame, %4 frames").
        arg(extractor->getType().c_str()).arg(extractor->getFrameLength()).
        arg(extractor->getParamsPerFrame()).arg(extractor->getFramesCount()));

    emit sendMessage(tr("Feature file %1 loaded successfully").arg(filename));
}

/**
 * Zamyka aktualnie wybrany plik.
 *
 * Usuwa obiekt nagrania/ekstraktora!
 */
void FilesWidget::closeCurrentFile()
{
    QString filename = currentFile();
    if (filename.isEmpty())
        return;

    emit sendMessage(tr("Closing file %1...").arg(filename));
    delete ui->listFiles->takeItem(ui->listFiles->currentRow());
    loadedFiles.removeOne(filename);

    switch (currentFileType())
    {
    case Wave:
        delete wavefiles[filename];
        wavefiles.remove(filename);
        break;
    case Feature:
        delete extractors[filename];
        extractors.remove(filename);
        break;
    default:
        break;
    }

    emit sendMessage(tr("File %1 closed successfully").arg(filename));
}

/**
 * Reaguje na zmianę zaznaczenia elementów na liście.
 *
 * @param current aktualnie zaznaczony element
 * @param previous poprzednio zaznaczony element
 */
void FilesWidget::currentItemChanged(QListWidgetItem* current, QListWidgetItem* previous)
{
    emit fileChanged(currentFile(), currentFileType());
    updateUi();
}

/**
 * Zgłasza żądanie narysowania odpowiedniego wykresu po podwójnym kliknięciu pliku.
 *
 * @param index indeks w modelu (nieużywany)
 */
void FilesWidget::doubleClicked(QModelIndex index)
{
    switch (currentFileType())
    {
    case Wave:
        emit chartRequested();
        emit waveformRequested(currentWaveFile());
        break;
    case Feature:
        emit chartRequested();
        emit featureChartRequested(currentExtractor());
        break;
    default:
        break;
    }
}

/**
 * Wysyła żądanie wygenerowania wykresu nagrania dla bieżącego pliku.
 */
void FilesWidget::waveformClicked()
{
    emit chartRequested();
    emit waveformRequested(currentWaveFile());
}

/**
 * Wysyła żądanie wygenerowania spektrogramu dla bieżącego pliku.
 */
void FilesWidget::spectrogramClicked()
{
    emit chartRequested();
    emit spectrogramRequested(currentWaveFile());
}

/**
 * Wysyła żądanie wygenerowania wykresu cech dla bieżącego pliku.
 *
 * W przypadku, gdy aktualnie zaznaczonym plikiem jest plik dźwiękowy,
 * domaga się przeliczenia cech.
 */
void FilesWidget::featureChartClicked()
{
    if (currentFileType() == Wave)
    {
        emit featureCalculationRequested();
        return;
    }

    emit chartRequested();
    emit featureChartRequested(currentExtractor());
}

/**
 * Wysyła żądanie wygenerowania diagramu DTW dla bieżącego pliku.
 *
 * W przypadku, gdy aktualnie zaznaczonym plikiem jest plik dźwiękowy,
 * domaga się przeliczenia cech.
 */
void FilesWidget::dtwChartClicked()
{
    emit chartRequested();
    emit dtwChartRequested(currentExtractor());
}

/**
 * Aktualizuje interfejs w zależności od typu wybranego pliku.
 */
void FilesWidget::updateUi()
{
    if (currentFile().isEmpty())
    {
        ui->btnWaveform->setEnabled(false);
        ui->btnCalculateFeatures->setEnabled(false);
        ui->btnDrawSpectrogram->setEnabled(false);
        ui->btnDrawFeatureChart->setEnabled(false);
        ui->btnDrawDtwChart->setEnabled(false);
        ui->btnCloseFile->setEnabled(false);
        return;
    }

    ui->btnCloseFile->setEnabled(true);
    ui->btnDrawFeatureChart->setEnabled(true);
    switch (currentFileType())
    {
    case Wave:
        ui->btnWaveform->setEnabled(true);
        ui->btnCalculateFeatures->setEnabled(true);
        ui->btnDrawSpectrogram->setEnabled(true);
        ui->btnDrawDtwChart->setEnabled(false);
        break;
    case Feature:
        ui->btnWaveform->setEnabled(false);
        ui->btnCalculateFeatures->setEnabled(false);
        ui->btnDrawSpectrogram->setEnabled(false);
        ui->btnDrawDtwChart->setEnabled(true);
        break;
    default:
        break;
    }
}
