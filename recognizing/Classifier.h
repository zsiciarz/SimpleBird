/**
 * @file Classifier.h
 *
 * Abstrakcyjna klasa klasyfikatora - nagłówek.
 *
 * @author Zbigniew Siciarz
 * @date 2009-2010
 * @version 0.8.2
 * @since 0.7.1
 */

#ifndef CLASSIFIER_H
#define CLASSIFIER_H

#include "Recognizer.h"
#include <QObject>
#include <QString>

/**
 * Abstrakcyjna klasa klasyfikatora.
 */
class Classifier : public QObject
{
Q_OBJECT

public:
    Classifier(QObject *parent = 0);
    virtual ~Classifier();

public slots:
    virtual void addEntry(double distance, QString label) = 0;
    virtual void clear() = 0;
    virtual RecognizingResult classify() = 0;
};

#endif // CLASSIFIER_H
