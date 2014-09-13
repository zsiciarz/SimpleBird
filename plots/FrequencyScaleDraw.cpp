/**
 * @file FrequencyScaleDraw.cpp
 *
 * Skala osi w jednostkach częstotliwości - nagłówek.
 *
 * @author Zbigniew Siciarz
 * @date 2009-2010
 * @version 0.8.2
 * @since 0.2.1
 */

#include "FrequencyScaleDraw.h"

#include "aquila/Tools.h"


/**
 * Tworzy skalę osi, ustawia domyślne wartości parametrów.
 *
 * @param freq częstotliwość próbkowania w Hz (domyślnie 44100 Hz)
 * @param samplesCount liczba prążków widma (domyślnie 1024)
 */
FrequencyScaleDraw::FrequencyScaleDraw(double freq, unsigned int samplesCount):
    sampleFrequency(freq), N(samplesCount)
{
}

/**
 * Zwraca tekst znacznika osi odpowiadający danej wartości.
 *
 * @param v wartość na osi - w tym wypadku jest to numer prążka widma
 */
QwtText FrequencyScaleDraw::label(double v) const
{
    return QString("%1 Hz").
        arg(Aquila::Tools::spectrumPeakToHz(v, sampleFrequency, N), 0, 'f', 0);
}
