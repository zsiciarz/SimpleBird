/**
 * @file FrequencyScaleDraw.h
 *
 * Skala osi w jednostkach częstotliwości - nagłówek.
 *
 * @author Zbigniew Siciarz
 * @date 2009-2010
 * @version 0.8.2
 * @since 0.2.1
 */

#ifndef FREQUENCYSCALEDRAW_H
#define FREQUENCYSCALEDRAW_H

#include <qwt_scale_draw.h>
#include <qwt_text.h>

/**
 * Skala osi w jednostkach częstotliwości.
 */
class FrequencyScaleDraw : public QwtScaleDraw
{
public:
    FrequencyScaleDraw(double freq = 44100.0, unsigned int samplesCount = 1024);

    QwtText label(double v) const;

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
     * Częstotliwość próbkowania w Hz.
     */
    double sampleFrequency;

    /**
     * Liczba prążków widma.
     */
    unsigned int N;
};

#endif // FREQUENCYSCALEDRAW_H
