/**
 * @file WaveFilePrototype.h
 *
 * Prototyp klasy skryptowej dla pliku dźwiękowego - nagłówek.
 *
 * @author Zbigniew Siciarz
 * @date 2009-2010
 * @version 0.8.2
 * @since 0.8.0
 */

#ifndef WAVEFILEPROTOTYPE_H
#define WAVEFILEPROTOTYPE_H

#include "aquila/WaveFile.h"
#include <QMetaType>
#include <QObject>
#include <QScriptable>
#include <QScriptContext>
#include <QScriptEngine>
#include <QScriptValue>

class WaveFilePrototype : public QObject, public QScriptable
{
    Q_OBJECT
    Q_PROPERTY(QString filename READ getFilename)
    Q_PROPERTY(unsigned short channels READ getChannels)
    Q_PROPERTY(unsigned int sampleFrequency READ getSampleFrequency)
    Q_PROPERTY(unsigned int bitsPerSample READ getBitsPerSamp)
    Q_PROPERTY(unsigned int audioLength READ getAudioLength)
    Q_PROPERTY(unsigned int framesCount READ getFramesCount)
    Q_PROPERTY(unsigned int samplesPerFrame READ getSamplesPerFrame)

public:
    explicit WaveFilePrototype(QObject *parent = 0);
    ~WaveFilePrototype();

public slots:
    void load(QString filename);

    /**
     * Zwraca nazwę wczytanego pliku.
     *
     * @return pełna ścieżka do aktualnie załadowanego pliku
     */
    QString getFilename() const { return QString::fromStdString(wav->getFilename()); }

    /**
     * Zwraca liczbę kanałów.
     *
     * @return 1 dla mono, 2 dla stereo, inne rodzaje nieobsługiwane
     */
    unsigned short getChannels() const { return wav->getChannelsNum(); }

    /**
     * Zwraca częstotliwość próbkowania sygnału.
     *
     * @return częstotliwość próbkowania w Hz
     */
    unsigned int getSampleFrequency() const { return wav->getSampleFrequency(); }

    /**
     * Zwraca liczbę bitów na próbkę.
     *
     * @return 8 lub 16
     */
    unsigned int getBitsPerSamp() const { return wav->getBitsPerSamp(); }

    /**
     * Zwraca czas trwania nagrania.
     *
     * @return długość nagrania w milisekundach
     */
    unsigned int getAudioLength() const { return wav->getAudioLength(); }

    /**
     * Zwraca ilość ramek w nagraniu.
     *
     * @return długość wektora wskaźników do ramek
     */
    unsigned int getFramesCount() const { return wav->getFramesCount(); }

    /**
     * Zwraca liczbę próbek w jednej ramce sygnału.
     *
     * @return liczba próbek = liczba bajtów na ramkę / bajty na próbkę
     */
    unsigned int getSamplesPerFrame() const { return wav->getSamplesPerFrame(); }

    void recalculate();

private:
    /**
     * Wskaźnik do opakowanego obiektu pliku dźwiękowego.
     */
    Aquila::WaveFile* wav;
};

QScriptValue constructWaveFile(QScriptContext* context, QScriptEngine* engine);

Q_DECLARE_METATYPE(WaveFilePrototype*)

#endif // WAVEFILEPROTOTYPE_H
