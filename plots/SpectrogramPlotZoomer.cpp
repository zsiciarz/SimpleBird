/**
 * @file SpectrogramPlotZoomer.cpp
 *
 * Zoomowanie spektrogramu - implementacja.
 *
 * @author Zbigniew Siciarz
 * @date 2009-2010
 * @version 0.8.2
 * @since 0.2.2
 */

#include "SpectrogramPlotZoomer.h"

#include "aquila/Tools.h"
#include "SpectrogramPlot.h"


SpectrogramPlotZoomer::SpectrogramPlotZoomer(QwtPlotCanvas* canvas):
    PlotZoomer(canvas, Qt::blue)
{
}

/**
 * Przelicza pozycję kursora na jednostki częstotliwości i czasu.
 *
 * @param pos punkt w którym znajduje się kursor
 * @return tekst na półprzezroczystym tle
 */
QwtText SpectrogramPlotZoomer::trackerText(const QwtDoublePoint& pos) const
{
    QwtText text = PlotZoomer::trackerText(pos);

    double ms = Aquila::Tools::frameNumToMs(pos.x(), frameLength, frameOverlap);
    double frequency = Aquila::Tools::spectrumPeakToHz(pos.y(), sampleFrequency, N);
    const SpectrogramPlot* plot =static_cast<const SpectrogramPlot*>(canvas()->plot());
    double intensity = plot->getIntensity(pos);

    text.setText(QString("%1 ms \n%2 Hz \n%3 dB").arg(ms, 0, 'f', 0).
                 arg(frequency, 0, 'f', 0).arg(intensity, 0, 'f', 2));

    return text;
}
