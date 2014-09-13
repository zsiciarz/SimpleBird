/**
 * @file SpectrogramPlot.cpp
 *
 * Wykres spektrogramu - implementacja.
 *
 * @author Zbigniew Siciarz
 * @date 2009-2010
 * @version 0.8.2
 * @since 0.2.1
 */

#include "SpectrogramPlot.h"

#include "SpectrogramData.h"
#include "FrequencyScaleDraw.h"
#include "DurationScaleDraw.h"
#include "SimpleBirdSettings.h"
#include <qwt_color_map.h>
#include <qwt_plot_marker.h>
#include <qwt_plot_panner.h>
#include <qwt_scale_widget.h>
#include <QColor>
#include <QFont>
#include <QFontMetrics>


/**
 * Tworzy wykres spektrogramu.
 *
 * Przygotowuje mapowanie kolorów, skale osi we właściwych jednostkach itp.
 *
 * @param parent obiekt rodzica
 */
SpectrogramPlot::SpectrogramPlot(QWidget* parent):
    QwtPlot(tr("Wave file not loaded"), parent)
{
    spectrogram = new QwtPlotSpectrogram();
    QwtLinearColorMap colorMap(Qt::black, Qt::red);
    colorMap.addColorStop(0.3, Qt::darkBlue);
    colorMap.addColorStop(0.4, Qt::blue);
    colorMap.addColorStop(0.65, Qt::green);
    colorMap.addColorStop(0.85, Qt::yellow);
    spectrogram->setColorMap(colorMap);

    // kolorowa prawa oś
    QwtScaleWidget *rightAxis = axisWidget(yRight);
    rightAxis->setTitle(tr("Intensity [dB]"));
    rightAxis->setColorBarEnabled(true);
    enableAxis(yRight);
    spectrogram->attach(this);
    const QFontMetrics fmRight(rightAxis->font());
    int intensityWidth = rightAxis->colorBarWidth() + fmRight.width("888 888");
    axisScaleDraw(yRight)->setMinimumExtent(intensityWidth);

    QwtPlotPanner *panner = new QwtPlotPanner(canvas());
    panner->setAxisEnabled(QwtPlot::yRight, false);
    panner->setMouseButton(Qt::MidButton);

    // dolna oś
    setAxisScaleDraw(xBottom, new DurationScaleDraw());
}

/**
 * Przypisuje obiekt danych do spektrogramu.
 *
 * Dane mogą zawierać zarówno typowy spektrogram, czyli dla każdej ramki
 * jej widmo, lub też "spektrogram cech", gdzie dla każdej ramki tablica
 * wartości zawiera cechy tej ramki.
 *
 * @param data obiekt danych
 */
void SpectrogramPlot::setSpectrogramData(const QwtRasterData& data)
{
    // skala osi czasu
    DurationScaleDraw* durSD = (DurationScaleDraw*)axisScaleDraw(xBottom);
    SimpleBirdSettings settings;
    durSD->setFrameLength(settings.getFrameLength());
    durSD->setFrameOverlap(settings.getOverlap());

    // przypisanie danych do spektrogramu
    spectrogram->setData(data);

    // skalowanie osi intensywności
    QwtScaleWidget *rightAxis = axisWidget(yRight);
    rightAxis->setColorMap(data.range(), spectrogram->colorMap());
}

/**
 * Dodaje dodatkowy opis wykresu.
 *
 * @param caption opis wykresu
 * @param x pozycja na wykresie w skali czasu
 * @param y pozycja na wykresie w skali pionowej (np. częstotliwości)
 */
void SpectrogramPlot::setExtraCaption(QString caption, double x, double y)
{
    QwtPlotMarker* marker = new QwtPlotMarker();
    QwtText label(caption);
    label.setColor(QColor::fromRgba(0x88FFFFFF));
    label.setFont(QFont("Arial", 10, QFont::Bold));
    marker->setLabel(label);
    marker->setLineStyle(QwtPlotMarker::NoLine);
    marker->setValue(x, y);
    marker->setLabelAlignment(Qt::AlignRight | Qt::AlignBottom);
    marker->attach(this);
}

/**
 * Zwraca "intensywność" spektrogramu w danym punkcie.
 *
 * W przypadku klasycznego spektrogramu jest to wartość danego prążka widma.
 *
 * @param pos punkt w którym pobieramy wartość
 * @return intensywność
 */
double SpectrogramPlot::getIntensity(const QwtDoublePoint& pos) const
{
    return spectrogram->data().value(pos.x(), pos.y());
}
