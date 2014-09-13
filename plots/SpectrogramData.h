/**
 * @file SpectrogramData.h
 *
 * Klasa danych spektrogramu - nagłówek.
 *
 * @author Zbigniew Siciarz
 * @date 2009-2010
 * @version 0.8.2
 * @since 0.1.0
 */

#ifndef SPECTROGRAMDATA_H_
#define SPECTROGRAMDATA_H_

#include "aquila/global.h"
#include "aquila/WaveFile.h"
#include <qwt_raster_data.h>
#include <QString>
#include <QVector>

/**
 * Klasa opisująca punkty spektrogramu.
 */
class SpectrogramData : public QwtRasterData
{
public:
    SpectrogramData(Aquila::WaveFile* wavefile);
    ~SpectrogramData();
    QwtRasterData* copy() const;
    QwtDoubleInterval range() const;
    double value(double x, double y) const;

    /**
     * Zwraca opis szczegółów transformacji FFT.
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
    SpectrogramData(QVector<Aquila::spectrumType> spectra, double maxFFT);

    /**
     * Tablica widm każdej ramki.
     */
    QVector<Aquila::spectrumType> frameSpectra;

    /**
     * Liczba ramek w nagraniu.
     */
    unsigned int framesCount;

    /**
     * Długość widma.
     */
    unsigned int spectrumSize;

    /**
     * Maksymalna wartość występująca w widmach wszystkich ramek.
     */
    double maxSpectrum;

    /**
     * Logarytm maksymalnej wartości widma.
     */
    double logMaxSpectrum;

    /**
     * Czy zatrzymano obliczenia?
     */
    bool canceled;

    /**
     * Informacja o rodzaju spektrogramu.
     */
    QString info;
};

#endif /* SPECTROGRAMDATA_H_ */
