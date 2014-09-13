/**
 * @file Recognizer.h
 *
 * Klasa bazowa dla obiektów rozpoznawania - nagłówek.
 *
 * @author Zbigniew Siciarz
 * @date 2009-2010
 * @version 0.8.2
 * @since 0.7.0
 */

#ifndef RECOGNIZER_H
#define RECOGNIZER_H

#include "Dictionary.h"
#include <QColor>
#include <QObject>
#include <QString>

/**
 * Struktura opisująca wynik rozpoznawania.
 */
struct RecognizingResult
{
    QString label;
    double distance;
};

class Classifier;

/**
 * Klasa bazowa dla obiektów rozpoznawania.
 */
class Recognizer : public QObject
{
    Q_OBJECT

public:
    Recognizer(Dictionary* dict = 0, QObject *parent = 0);
    virtual ~Recognizer();

    /**
     * Przypisuje obiekt klasyfikatora.
     *
     * @param classifier wskaźnik do obiektu klasyfikatora
     */
    void setClassifier(Classifier* classifier) { m_classifier = classifier; }

    /**
     * Przypisuje obiekt słownika wzorców.
     *
     * @param dict wskaźnik do obiektu słownika
     */
    void setDictionary(Dictionary* dict) { m_dict = dict; }

public slots:
    virtual RecognizingResult recognizeFile(QString filename) = 0;

signals:
    /**
     * Sygnał emitowany przy zmianie zakresu postępu, określonego dość abstrakcyjnie.
     */
    void progressRangeChanged(int min, int max);

    /**
     * Sygnał emitowany w chwili zmiany postępu.
     */
    void progressChanged(int progress);

    /**
     * Sygnał emitowany jako wiadomość na zewnątrz.
     */
    void sendMessage(QString msg, QColor color = Qt::black);

protected:
    /**
     * Obiekt klasyfikatora.
     */
    Classifier* m_classifier;

    /**
     * Obiekt słownika.
     */
    Dictionary* m_dict;
};

#endif // RECOGNIZER_H
