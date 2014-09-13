/**
 * @file WaveFilePrototype.cpp
 *
 * Prototyp klasy skryptowej dla pliku dźwiękowego - implementacja.
 *
 * @author Zbigniew Siciarz
 * @date 2009-2010
 * @version 0.8.2
 * @since 0.8.0
 */

#include "WaveFilePrototype.h"

#include "SimpleBirdSettings.h"
#include <QFile>


/**
 * Konstruktor - tworzy obiekt pliku dźwiękowego z odpowiednimi ustawieniami.
 *
 * @param parent obiekt rodzica
 */
WaveFilePrototype::WaveFilePrototype(QObject *parent):
    QObject(parent)
{
    SimpleBirdSettings settings;
    wav = new Aquila::WaveFile(settings.getFrameLength(), settings.getOverlap());
}

/**
 * Usuwa obiekt pliku dźwiękowego.
 */
WaveFilePrototype::~WaveFilePrototype()
{
    delete wav;
}

/**
 * Wczytuje nagłówek i dane kanałów z pliku dźwiękowego o podanej nazwie.
 *
 * Jeśli mamy do czynienia z sygnałem mono, próbki są zapisywane do lewego kanału.
 *
 * Sprawdza, czy plik istnieje, jeśli nie, rzuca wyjątkiem do skryptu.
 *
 * @param filename nazwa pliku
 */
void WaveFilePrototype::load(QString filename)
{
    if (!QFile::exists(filename))
    {
        context()->throwError(tr("File %1 does not exist!").arg(filename));
        return;
    }

    wav->load(filename.toStdString());
}

/**
 * Przelicza ponownie podział na ramki, uwzględniając nowe ustawienia.
 */
void WaveFilePrototype::recalculate()
{
    SimpleBirdSettings settings;
    wav->recalculate(settings.getFrameLength(), settings.getOverlap());
}

/**
 * Reprezentuje konstruktor pliku dźwiękowego w skrypcie.
 *
 * @param context kontekst wykonania skryptu
 * @param engine interpreter
 * @return obiekt pliku dźwiękowego w skrypcie
 */
QScriptValue constructWaveFile(QScriptContext* context, QScriptEngine* engine)
{
    Q_UNUSED(context);

    return engine->newQObject(new WaveFilePrototype());
}
