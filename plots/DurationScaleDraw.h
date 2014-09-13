/**
 * @file DurationScaleDraw.h
 *
 * Skala osi w jednostkach czasu - nagłówek.
 *
 * @author Zbigniew Siciarz
 * @date 2009-2010
 * @version 0.8.2
 * @since 0.2.1
 */

#ifndef DURATIONSCALEDRAW_H
#define DURATIONSCALEDRAW_H

#include <qwt_scale_draw.h>
#include <qwt_text.h>

/**
 * Skala osi (typowo poziomej) wyskalowana w jednostkach czasu.
 */
class DurationScaleDraw : public QwtScaleDraw
{
public:
    DurationScaleDraw();

    QwtText label(double v) const;

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

private:
    /**
     * Długość ramki w milisekundach.
     */
    int frameLength;

    /**
     * Wartość zakładki - liczba z przedziału 0.0-1.0.
     */
    double frameOverlap;
};

#endif // DURATIONSCALEDRAW_H
