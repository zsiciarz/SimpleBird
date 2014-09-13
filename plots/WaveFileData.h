/**
 * @file WaveFileData.h
 *
 * Klasa danych wykresu nagrania - nagłówek.
 *
 * @author Zbigniew Siciarz
 * @date 2009-2010
 * @version 0.8.2
 * @since 0.2.1
 */

#ifndef WAVEFILEDATA_H
#define WAVEFILEDATA_H

#include "aquila/WaveFile.h"
#include <qwt_data.h>


/**
 * Klasa abstrahujaca odczyt próbek z pliku wav w celu narysowania przebiegu.
 */
class WaveFileData : public QwtData
{
public:
    WaveFileData(Aquila::WaveFile* wavefile);
    ~WaveFileData() {}

    WaveFileData* copy() const;

    size_t size() const;

    double x(size_t i) const;

    double y(size_t i) const;

private:
    /**
     * Obiekt pliku .wav.
     */
    Aquila::WaveFile* wav;

    /**
     * Referencja do źródła danych.
     */
    const Aquila::WaveFile::channelType& source;

    /**
     * Długość nagrania w milisekundach.
     */
    unsigned int audioLength;

    /**
     * Rozmiar źródła - liczba próbek.
     */
    size_t sourceSize;
};

#endif // WAVEFILEDATA_H
