/**
 * @file DtwData.cpp
 *
 * Klasa danych diagramu DTW - implementacja.
 *
 * @author Zbigniew Siciarz
 * @date 2009-2010
 * @version 0.8.2
 * @since 0.6.3
 */

#include "DtwData.h"

#include "SimpleBirdSettings.h"
#include <QDebug>
#include <algorithm>


DtwData::DtwData(Aquila::Extractor* extractor, Aquila::Extractor* pattern):
    QwtRasterData(QwtDoubleRect(0, 0, extractor->getFramesCount(), pattern->getFramesCount())),
    dtw(0), maxDistance(0.0), drawAccumulated(true), ownsDtw(false)
{
    dtw = new Aquila::Dtw(extractor);

    SimpleBirdSettings settings;
    int distanceType = settings.getDtwDistanceType();
    dtw->setDistanceFunction(distanceType);
    dtw->setPassType(settings.getDtwPassType());

    dtw->getDistance(pattern);
    points = dtw->getPoints();
    signalSize = extractor->getFramesCount();
    patternSize = pattern->getFramesCount();
    path = dtw->getPath();

    drawAccumulated = settings.value("charts/drawDtwAccumulated").toBool();

    double distance = 0.0;
    for (unsigned int i = 0; i < signalSize; ++i)
    {
        for (unsigned int j = 0; j < patternSize; ++j)
        {
            distance = drawAccumulated ? points[i][j].dAccumulated : points[i][j].dLocal;
            if (distance > maxDistance)
                maxDistance = distance;
        }
    }

    info = QObject::tr("signal: %1 frames, pattern: %2 frames, distance type: %3").
        arg(signalSize).arg(patternSize).arg(distanceType);
}

DtwData::DtwData(Aquila::Dtw *dtwObject):
    dtw(dtwObject)
{
}

DtwData::~DtwData()
{
    if (ownsDtw)
        delete dtw;
}

/**
 * Klonuje obiekt danych.
 *
 * @return kopia obiektu danych utworzona na stercie
 */
QwtRasterData* DtwData::copy() const
{
    DtwData* data = new DtwData(dtw);
    data->points = dtw->getPoints();
    data->path = path;
    data->maxDistance = maxDistance;
    data->signalSize = signalSize;
    data->patternSize = patternSize;
    data->setBoundingRect(QwtDoubleRect(0, 0, signalSize, patternSize));
    data->drawAccumulated = drawAccumulated;
    data->ownsDtw = true;
    data->info = info;
    return data;
}

/**
 * Zwraca zakres wartości wykresu DTW.
 *
 * @return przedział od minimalnej do maksymalnej wartości parametru
 */
QwtDoubleInterval DtwData::range() const
{
    return QwtDoubleInterval(0.0, maxDistance);
}

/**
 * Zwraca wartość wykresu DTW w danym punkcie.
 *
 * @param x współrzędna pozioma
 * @param y współrzędna pionowa
 * @return wartość w punkcie (x, y)
 */
double DtwData::value(double x, double y) const
{
    unsigned int signalFrame = qBound(0u, static_cast<unsigned int>(x), signalSize - 1);
    unsigned int patternFrame = qBound(0u, static_cast<unsigned int>(y), patternSize - 1);

    Aquila::DtwPathPoint p = std::make_pair(signalFrame, patternFrame);
    if (std::find(path.begin(), path.end(), p) != path.end())
        return maxDistance;

    return drawAccumulated ? points[signalFrame][patternFrame].dAccumulated :
                             points[signalFrame][patternFrame].dLocal;
}
