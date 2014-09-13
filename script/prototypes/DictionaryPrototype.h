/**
 * @file DictionaryPrototype.h
 *
 * Prototyp klasy skryptowej dla obiektu słownika - nagłówek.
 *
 * @author Zbigniew Siciarz
 * @date 2009-2010
 * @version 0.8.2
 * @since 0.8.1
 */

#ifndef DICTIONARYPROTOTYPE_H
#define DICTIONARYPROTOTYPE_H

#include "recognizing/Dictionary.h"
#include <QMetaType>
#include <QObject>
#include <QScriptable>
#include <QScriptContext>
#include <QScriptEngine>
#include <QScriptValue>


class DictionaryPrototype : public QObject, public QScriptable
{
    Q_OBJECT
    Q_PROPERTY(int entriesCount READ countEntries)

public:
    explicit DictionaryPrototype(QObject *parent = 0);

public slots:
    /**
     * Zwraca liczbę wpisów w słowniku.
     *
     * @return liczba rekordów w tabeli słownika
     */
    int countEntries() const { return dict->countEntries(); }

    /**
     * Zwraca listę plików dźwiękowych w słowniku.
     *
     * @return lista wszystkich plików dźwiękowych w słowniku
     */
    QScriptValue getFiles() const { return qScriptValueFromSequence(engine(), dict->entries().keys()); }

    /**
     * Zwraca etykietkę odpowiadającą danej nazwie pliku.
     */
    QString findLabel(QString filename) const { return dict->findLabel(filename); }

    void rebuild(bool useMultithreading = false);

signals:
    /**
     * Sygnał emitowany przez metodę rebuild(), informuje o stanie przetwarzania.
     */
    void sendMessage(QString message);

private:
    /**
     * Wskaźnik do opakowanego obiektu słownika.
     */
    Dictionary* dict;
};


QScriptValue constructDictionary(QScriptContext* context, QScriptEngine* engine);

Q_DECLARE_METATYPE(DictionaryPrototype*)

#endif // DICTIONARYPROTOTYPE_H
