/**
 * @file FeatureData.h
 *
 * Klasa danych wykresu cech - implementacja.
 *
 * @author Zbigniew Siciarz
 * @date 2009-2010
 * @version 0.8.2
 * @since 0.5.0
 */

#include "FeatureData.h"

#include <limits>
#include <QApplication>
#include <QProgressDialog>


/**
 * Tworzy obiekt danych, szuka zakresu wartości i kopiuje cechy z ekstraktora.
 *
 * @param extractor obiekt ekstraktora
 */
FeatureData::FeatureData(Aquila::Extractor* extractor):
    QwtRasterData(QwtDoubleRect(0, 0, extractor->getFramesCount(), extractor->getParamsPerFrame())),
    framesCount(extractor->getFramesCount()), paramsPerFrame(extractor->getParamsPerFrame()),
    canceled(false), ownsArray(false)
{
    maxParam = std::numeric_limits<double>().min();
    minParam = std::numeric_limits<double>().max();
    paramsArray = new double*[framesCount];

    QProgressDialog progress(QObject::tr("Generating feature chart..."),
        QObject::tr("Cancel"), 0, framesCount);
    progress.setMinimumDuration(0);
    progress.setWindowModality(Qt::WindowModal);

    for (unsigned int i = 0; i < framesCount; ++i)
    {
        if (progress.wasCanceled())
        {
            canceled = true;
            break; // TODO: potential memory leak?
        }

        paramsArray[i] = new double[paramsPerFrame];
        for (unsigned int j = 0; j < paramsPerFrame; ++j)
        {
            double value = extractor->getParam(i, j);
            if (value < minParam)
                minParam = value;
            if (value > maxParam)
                maxParam = value;
            paramsArray[i][j] = value;

            progress.setValue(i);
            qApp->processEvents();
        }
    }

    info = QObject::tr("%3, %1 frames, %2 params per frame").arg(framesCount).
        arg(paramsPerFrame).arg(extractor->getType().c_str());
}

/**
 * Jeśli obiekt jest właścicielem tablicy wartości, to ją usuwa.
 */
FeatureData::~FeatureData()
{
    if (ownsArray)
    {
        for (unsigned int i = 0; i < framesCount; ++i)
            delete [] paramsArray[i];

        delete [] paramsArray;
    }
}

FeatureData::FeatureData(double** params, double min, double max):
    paramsArray(params), minParam(min), maxParam(max)
{
}

/**
 * Klonuje obiekt danych.
 *
 * @return kopia obiektu danych utworzona na stercie
 */
QwtRasterData* FeatureData::copy() const
{
    FeatureData* data = new FeatureData(paramsArray, minParam, maxParam);
    data->framesCount = framesCount;
    data->paramsPerFrame = paramsPerFrame;
    data->info = info;
    data->ownsArray = true;
    data->setBoundingRect(QwtDoubleRect(0, 0, framesCount, paramsPerFrame));
    return data;
}

/**
 * Zwraca zakres wartości wykresu cech.
 *
 * @return przedział od minimalnej do maksymalnej wartości parametru
 */
QwtDoubleInterval FeatureData::range() const
{
    return QwtDoubleInterval(minParam, maxParam);
}

/**
 * Zwraca wartość spektrogramu cech w danym punkcie.
 *
 * @param x współrzędna pozioma
 * @param y współrzędna pionowa
 * @return wartość w punkcie (x, y)
 */
double FeatureData::value(double x, double y) const
{
    unsigned int frame = qBound(0u, static_cast<unsigned int>(x), framesCount - 1);
    unsigned int param = qBound(0u, static_cast<unsigned int>(y), paramsPerFrame - 1);

    return paramsArray[frame][param];
}
