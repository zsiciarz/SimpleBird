/**
 * @file PlotZoomer.cpp
 *
 * Zoomowanie wykresu - implementacja.
 *
 * @author Zbigniew Siciarz
 * @date 2009-2010
 * @version 0.8.2
 * @since 0.2.1
 */

#include "PlotZoomer.h"

#include "aquila/Tools.h"
#include <QColor>
#include <QBrush>

/**
 * Konstruktor - włącza na stałe śledzenie pozycji.
 *
 * @param canvas obiekt "płótna"
 * @param color kolor tekstu i obszaru zoomera
 */
PlotZoomer::PlotZoomer(QwtPlotCanvas* canvas, QColor color):
    QwtPlotZoomer(canvas)
{
    setTrackerMode(AlwaysOn);

    setMousePattern(QwtEventPattern::MouseSelect2, Qt::RightButton, Qt::ControlModifier);
    setMousePattern(QwtEventPattern::MouseSelect3, Qt::RightButton);

    setRubberBandPen(color);
    setTrackerPen(color);
}

/**
 * Ustawia półprzezroczyste tło dla tekstu trackera.
 *
 * @param pos punkt w którym znajduje się kursor
 * @return tekst na półprzezroczystym tle
 */
QwtText PlotZoomer::trackerText(const QwtDoublePoint& pos) const
{
    QColor bg(Qt::white);
    bg.setAlpha(127);
    QwtText text = QwtPlotZoomer::trackerText(pos);
    text.setBackgroundBrush(QBrush(bg));

    return text;
}
