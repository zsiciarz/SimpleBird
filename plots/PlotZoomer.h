/**
 * @file PlotZoomer.h
 *
 * Zoomowanie wykresu - nagłówek.
 *
 * @author Zbigniew Siciarz
 * @date 2009-2010
 * @version 0.8.2
 * @since 0.2.1
 */

#ifndef PLOTZOOMER_H
#define PLOTZOOMER_H

#include <qwt_plot_canvas.h>
#include <qwt_plot_zoomer.h>
#include <QColor>

/**
 * Pomocnicza klasa - nakładka na zoomowanie.
 */
class PlotZoomer : public QwtPlotZoomer
{
public:
    PlotZoomer(QwtPlotCanvas* canvas, QColor color = Qt::blue);

    virtual QwtText trackerText(const QwtDoublePoint& pos) const;
};

#endif // PLOTZOOMER_H
