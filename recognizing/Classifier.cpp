/**
 * @file Classifier.cpp
 *
 * Abstrakcyjna klasa klasyfikatora - implementacja.
 *
 * @author Zbigniew Siciarz
 * @date 2009-2010
 * @version 0.8.2
 * @since 0.7.1
 */

#include "Classifier.h"

/**
 * Konstruktor - tworzy obiekt klasyfikatora.
 *
 * @param parent obiekt rodzica
 */
Classifier::Classifier(QObject *parent):
    QObject(parent)
{
}

/**
 * Destruktor - nie robi nic.
 */
Classifier::~Classifier()
{
}
