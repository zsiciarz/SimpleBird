/**
 * @file WaveformPlot.h
 *
 * Wykres przebiegu czasowego nagrania - nagłówek.
 *
 * @author Zbigniew Siciarz
 * @date 2009-2010
 * @version 0.8.2
 * @since 0.2.1
 */

#ifndef WAVEFORMPLOT_H
#define WAVEFORMPLOT_H

#include "aquila/WaveFile.h"
#include "PlotZoomer.h"
#include <qwt_plot.h>
#include <qwt_plot_curve.h>
#include <qwt_plot_panner.h>
#include <QColor>


/**
 * Wykres przebiegu czasowego nagrania.
 */
class WaveformPlot : public QwtPlot
{
    Q_OBJECT

public:
    WaveformPlot(QWidget* parent = 0);
    ~WaveformPlot() {}

    void setWaveFile(Aquila::WaveFile* wavefile);

    void setColor(QColor color);

private:
    /**
     * Krzywa obrazująca przebieg nagrania.
     */
    QwtPlotCurve* waveformCurve;

    /**
     * Obiekt umożliwiający powiększanie fragmentów wykresu.
     */
    PlotZoomer* zoomer;

    /**
     * Obiekt odpowiedzialny za przeciąganie wykresu.
     */
    QwtPlotPanner* panner;

    /**
     * Obiekt pliku dźwiękowego.
     */
    Aquila::WaveFile* wav;
};

#endif // WAVEFORMPLOT_H
