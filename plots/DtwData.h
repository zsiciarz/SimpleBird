/**
 * @file DtwData.h
 *
 * Klasa danych diagramu DTW - nagłówek.
 *
 * @author Zbigniew Siciarz
 * @date 2009-2010
 * @version 0.8.2
 * @since 0.6.3
 */

#ifndef DTWDATA_H
#define DTWDATA_H

#include "aquila/feature/Extractor.h"
#include "aquila/dtw/Dtw.h"
#include <qwt_raster_data.h>
#include <QString>
#include <QVector>

/**
 * Klasa danych diagramu DTW.
 */
class DtwData : public QwtRasterData
{
public:
    DtwData(Aquila::Extractor* extractor, Aquila::Extractor* pattern);
    DtwData(Aquila::Dtw* dtwObject);
    ~DtwData();
    QwtRasterData* copy() const;
    QwtDoubleInterval range() const;
    double value(double x, double y) const;

    /**
     * Zwraca opis szczegółów DTW.
     */
    QString getInfo() const { return info; }

private:
    /**
     * Obiekt liczący DTW.
     */
    Aquila::Dtw* dtw;

    /**
     * Tablica punktów DTW.
     */
    Aquila::dtwPointsArray points;

    /**
     * Ścieżka najmniejszego kosztu w tablicy DTW.
     */
    Aquila::DtwPath path;

    /**
     * Liczba ramek sygnału.
     */
    unsigned int signalSize;

    /**
     * Liczba ramek wzorca.
     */
    unsigned int patternSize;

    /**
     * Maksymalna odległość lokalna występująca w DTW.
     */
    double maxDistance;

    /**
     * Czy rysować odległości lokalne czy zakumulowane?
     */
    bool drawAccumulated;

    /**
     * Włącza/wyłącza usuwanie obiektu DTW w destruktorze.
     */
    bool ownsDtw;

    /**
     * Informacja o obiekcie DTW.
     */
    QString info;
};

#endif // DTWDATA_H
