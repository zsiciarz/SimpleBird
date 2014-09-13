/**
 * @file RecognizerPrototype.h
 *
 * Prototyp klasy skryptowej dla obiektu rozpoznawania - nagłówek.
 *
 * @author Zbigniew Siciarz
 * @date 2009-2010
 * @version 0.8.2
 * @since 0.8.2
 */

#ifndef RECOGNIZERPROTOTYPE_H
#define RECOGNIZERPROTOTYPE_H

#include "recognizing/Dictionary.h"
#include "recognizing/Recognizer.h"
#include <QMetaType>
#include <QObject>
#include <QScriptable>
#include <QScriptContext>
#include <QScriptEngine>
#include <QScriptValue>
#include <QString>


class RecognizerPrototype : public QObject, public QScriptable
{
Q_OBJECT
public:
    explicit RecognizerPrototype(QObject *parent = 0);

signals:
    void sendMessage(QString message);

public slots:
    void recognizeFile(QString filename);

    void recognizeFiles(QString directory = QString(), QString expectedLabel = QString());

private:
    Dictionary* dict;

    Recognizer* recognizer;
};

QScriptValue constructRecognizer(QScriptContext* context, QScriptEngine* engine);

Q_DECLARE_METATYPE(RecognizerPrototype*)

#endif // RECOGNIZERPROTOTYPE_H
