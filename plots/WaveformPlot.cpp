/**
 * @file WaveformPlot.cpp
 *
 * Wykres przebiegu czasowego nagrania - implementacja.
 *
 * @author Zbigniew Siciarz
 * @date 2009-2010
 * @version 0.8.2
 * @since 0.2.1
 */

#include "WaveformPlot.h"

#include "WaveFileData.h"
#include <qwt_plot_grid.h>
#include <QColor>
#include <QPen>

/**
 * Tworzy wykres nagrania.
 *
 * Inicjalizuje osie współrzędnych oraz krzywą przebiegu.
 *
 * @param parent obiekt rodzica
 */
WaveformPlot::WaveformPlot(QWidget* parent):
    QwtPlot(tr("Wave file not loaded"), parent), zoomer(0), panner(0), wav(0)
{
    setAxisTitle(yLeft, tr("sample value"));
    setAxisTitle(xBottom, tr("time [ms]"));

    QwtPlotGrid* plotGrid = new QwtPlotGrid();
    QPen penGrid;
    penGrid.setColor(Qt::gray);
    penGrid.setStyle(Qt::DotLine);
    plotGrid->setPen(penGrid);
    plotGrid->attach(this);

    waveformCurve = new QwtPlotCurve(tr("Waveform"));
    QPen penCurve;
    penCurve.setColor(Qt::red);
    waveformCurve->setPen(penCurve);
    waveformCurve->attach(this);
}

/**
 * Przygotowuje do narysowania przebieg z podanego pliku.
 *
 * @param wavefile obiekt pliku nagrania
 */
void WaveformPlot::setWaveFile(Aquila::WaveFile* wavefile)
{
    wav = wavefile;
    setTitle(tr("File: %1").arg(wav->getFilename().c_str()));

    WaveFileData data(wav);
    waveformCurve->setData(data);

    delete zoomer;
    zoomer = new PlotZoomer(canvas(), Qt::red);

    delete panner;
    panner = new QwtPlotPanner(canvas());
    panner->setAxisEnabled(yRight, false);
    panner->setMouseButton(Qt::MidButton);
}

/**
 * Ustawia kolor, jakim będzie rysowana krzywa przebiegu.
 */
void WaveformPlot::setColor(QColor color)
{
    QPen penCurve;
    penCurve.setColor(color);
    waveformCurve->setPen(penCurve);
}
