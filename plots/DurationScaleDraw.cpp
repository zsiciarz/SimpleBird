/**
 * @file DurationScaleDraw.cpp
 *
 * Skala osi w jednostkach czasu - impolementacja.
 *
 * @author Zbigniew Siciarz
 * @date 2009-2010
 * @version 0.8.2
 * @since 0.2.1
 */

#include "DurationScaleDraw.h"

#include "aquila/Tools.h"


/**
 * Tworzy skalę osi - wstępnie zeruje składowe.
 */
DurationScaleDraw::DurationScaleDraw():
    frameLength(0), frameOverlap(0)
{
}

/**
 * Zwraca tekst znacznika osi odpowiadający danej wartości.
 *
 * @param value wartość na osi - w tym wypadku jest to numer ramki
 */
QwtText DurationScaleDraw::label(double value) const
{
    return QString("%2 ms\n(#%1)").arg(value, 0, 'f', 0).
        arg(Aquila::Tools::frameNumToMs(value, frameLength, frameOverlap), 0, 'f', 0);
}
