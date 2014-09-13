/**
 * @file DictionaryPrototype.cpp
 *
 * Prototyp klasy skryptowej dla obiektu słownika - implementacja.
 *
 * @author Zbigniew Siciarz
 * @date 2009-2010
 * @version 0.8.2
 * @since 0.8.1
 */

#include "DictionaryPrototype.h"

#include "SimpleBirdApplication.h"
#include <QString>


/**
 * Konstruktor - tworzy obiekt słownika z domyślnej lokalizacji.
 *
 * Nie trzeba usuwać w destruktorze - przekazujemy słownikowi rodzica.
 *
 * @param parent obiekt rodzica
 */
DictionaryPrototype::DictionaryPrototype(QObject *parent):
    QObject(parent)
{
    QString dbfile = SimpleBirdApplication::directoryOf("data") + "/dictionary.db";
    dict = new Dictionary(dbfile, this);
    connect(dict, SIGNAL(sendMessage(QString)), this, SIGNAL(sendMessage(QString)));
}

/**
 * Przebudowuje słownik.
 *
 * @param useMultithreading włącza przetwarzanie wielowątkowe (domyślnie wyłączone)
 */
void DictionaryPrototype::rebuild(bool useMultithreading)
{
    dict->rebuild(useMultithreading);
}



/**
 * Reprezentuje konstruktor słownika w skrypcie.
 *
 * @param context kontekst wykonania skryptu
 * @param engine interpreter
 * @return obiekt słownika w skrypcie
 */
QScriptValue constructDictionary(QScriptContext* context, QScriptEngine* engine)
{
    Q_UNUSED(context);

    return engine->newQObject(new DictionaryPrototype());
}
