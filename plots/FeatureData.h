/**
 * @file FeatureData.h
 *
 * Klasa danych wykresu cech - nagłówek.
 *
 * @author Zbigniew Siciarz
 * @date 2009-2010
 * @version 0.8.2
 * @since 0.5.0
 */

#ifndef FEATUREDATA_H
#define FEATUREDATA_H

#include "aquila/feature/Extractor.h"
#include <qwt_raster_data.h>
#include <QString>
#include <QVector>

/**
 * Klasa opisująca punkty wykresu cech.
 */
class FeatureData : public QwtRasterData
{
public:
    FeatureData(Aquila::Extractor* extractor);
    ~FeatureData();
    QwtRasterData* copy() const;
    QwtDoubleInterval range() const;
    double value(double x, double y) const;

    /**
     * Zwraca minimalną wartość cech dla danego nagrania.
     */
    double getMinParam() const { return minParam; }

    /**
     * Zwraca maksymalną wartość cech dla danego nagrania.
     */
    double getMaxParam() const { return maxParam; }

    /**
     * Zwraca opis szczegółów ekstraktora.
     */
    QString getInfo() const { return info; }

    /**
     * Zwraca prawdę, jeśli zostało zatrzymane przetwarzanie danych.
     */
    bool isCanceled() const { return canceled; }

private:
    /**
     * Prywatny konstruktor, wykorzystywany tylko do szybkiego kopiowania.
     */
    FeatureData(double** params, double min, double max);

    /**
     * Tablica cech odczytanych z ekstraktora.
     */
    double** paramsArray;

    /**
     * Liczba ramek w nagraniu.
     */
    unsigned int framesCount;

    /**
     * Liczba parametrów na ramkę.
     */
    unsigned int paramsPerFrame;

    /**
     * Minimalna wartość parametru.
     */
    double minParam;

    /**
     * Maksymalna wartość parametru.
     */
    double maxParam;

    /**
     * Czy zatrzymano obliczenia?
     */
    bool canceled;

    /**
     * Włącza/wyłącza usuwanie tablicy danych w destruktorze.
     */
    bool ownsArray;

    /**
     * Informacja o rodzaju cech.
     */
    QString info;
};

#endif // FEATUREDATA_H
