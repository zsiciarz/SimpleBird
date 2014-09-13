/**
 * @file WaveFileData.cpp
 *
 * Klasa danych wykresu nagrania - implementacja.
 *
 * @author Zbigniew Siciarz
 * @date 2009-2010
 * @version 0.8.2
 * @since 0.2.1
 */

#include "WaveFileData.h"

/**
 * Tworzy obiekt danych.
 *
 * Inicjalizuje referencję do źródła danych oraz długość nagrania.
 *
 * @param wavefile obiekt pliku .wav
 */
WaveFileData::WaveFileData(Aquila::WaveFile* wavefile):
    wav(wavefile), source(wavefile->getDataVector()),
    audioLength(wavefile->getAudioLength()), sourceSize(source.size())
{
}

/**
 * Klonuje obiekt danych.
 *
 * @return kopia danych utworzona na stercie
 */
WaveFileData* WaveFileData::copy() const
{
    return new WaveFileData(wav);
}

/**
 * Zwraca rozmiar źródła danych.
 *
 * @return liczba próbek w nagraniu
 */
size_t WaveFileData::size() const
{
    return source.size();
}

/**
 * Zwraca x-ową współrzędną danego punktu (czas w milisekundach).
 *
 * @param i numer punktu danych
 * @return czas w ms
 */
double WaveFileData::x(size_t i) const
{
    return audioLength * static_cast<double>(i) / sourceSize;
}

/**
 * Zwraca y-ową współrzędną danego punktu (wartość próbki).
 *
 * @return wartość próbki
 */
double WaveFileData::y(size_t i) const
{
    return static_cast<double>(source[i]);
}
