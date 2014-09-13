/**
 * @file NeighborClassifier.cpp
 *
 * Klasa klasyfikacji metodą najbliższych sąsiadów - implementacja.
 *
 * @author Zbigniew Siciarz
 * @date 2009-2010
 * @version 0.8.2
 * @since 0.7.1
 */

#ifndef NEIGHBORCLASSIFIER_H
#define NEIGHBORCLASSIFIER_H

#include "Classifier.h"
#include "Recognizer.h"
#include <QMap>


/**
 * Klasa klasyfikacji metodą najbliższych sąsiadów.
*/
class NeighborClassifier : public Classifier
{
Q_OBJECT

public:
    NeighborClassifier(QObject *parent = 0);

public slots:
    virtual void addEntry(double distance, QString label);
    virtual void clear();
    virtual RecognizingResult classify();

private:
    QMap<double, QString> entries;
};

#endif // NEIGHBORCLASSIFIER_H
