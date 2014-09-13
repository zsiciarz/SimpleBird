/**
 * @file SpectrogramPlotZoomer.h
 *
 * Zoomowanie spektrogramu - nagłówek.
 *
 * @author Zbigniew Siciarz
 * @date 2009-2010
 * @version 0.8.2
 * @since 0.2.2
 */

#ifndef SPECTROGRAMPLOTZOOMER_H
#define SPECTROGRAMPLOTZOOMER_H

#include "PlotZoomer.h"
#include <qwt_plot_canvas.h>


class SpectrogramPlotZoomer : public PlotZoomer
{
public:
    SpectrogramPlotZoomer(QwtPlotCanvas* canvas);

    virtual QwtText trackerText(const QwtDoublePoint& pos) const;

    /**
     * Ustawia długość ramki.
     *
     * @param length długość ramki w milisekundach
     */
    void setFrameLength(int length) { frameLength = length; }

    /**
     * Ustawia wartość "zakładki".
     *
     * @param overlap wartość zakładki - liczba z przedziału 0.0-1.0
     */
    void setFrameOverlap(double overlap) { frameOverlap = overlap; }

    /**
     * Ustawia częstotliwość próbkowania.
     *
     * @param freq częstotliwość próbkowania w Hz
     */
    void setSampleFrequency(const double freq) { sampleFrequency = freq; }

    /**
     * Ustawia długość widma (liczba prążków).
     *
     * @param samplesCount liczba prążków widma
     */
    void setSpectrumSize(const unsigned int samplesCount) { N = samplesCount; }

private:
    /**
     * Długość ramki w milisekundach.
     */
    int frameLength;

    /**
     * Wartość zakładki - liczba z przedziału 0.0-1.0.
     */
    double frameOverlap;

    /**
     * Częstotliwość próbkowania w Hz.
     */
    double sampleFrequency;

    /**
     * Liczba prążków widma.
     */
    unsigned int N;
};

#endif // SPECTROGRAMPLOTZOOMER_H
