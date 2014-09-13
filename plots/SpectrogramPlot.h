/**
 * @file SpectrogramPlot.h
 *
 * Wykres spektrogramu - nagłówek.
 *
 * @author Zbigniew Siciarz
 * @date 2009-2010
 * @version 0.8.2
 * @since 0.2.1
 */

#ifndef SPECTROGRAMPLOT_H
#define SPECTROGRAMPLOT_H

#include <qwt_plot.h>
#include <qwt_plot_spectrogram.h>
#include <qwt_raster_data.h>
#include <QString>
#include <QVector>


/**
 * Wykres spektrogramu.
 */
class SpectrogramPlot : public QwtPlot
{
    Q_OBJECT

public:
    SpectrogramPlot(QWidget* parent = 0);
    ~SpectrogramPlot() { delete spectrogram; }

    void setSpectrogramData(const QwtRasterData& data);

    void setExtraCaption(QString caption, double x, double y);

    double getIntensity(const QwtDoublePoint& pos) const;

private:
    /**
     * Obiekt spektrogramu, który będzie rysowany na wykresie.
     */
    QwtPlotSpectrogram* spectrogram;
};

#endif // SPECTROGRAMPLOT_H
