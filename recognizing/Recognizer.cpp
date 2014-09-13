/**
 * @file Recognizer.cpp
 *
 * Klasa bazowa dla obiektów rozpoznawania - implementacja.
 *
 * @author Zbigniew Siciarz
 * @date 2009-2010
 * @version 0.8.2
 * @since 0.7.0
 */

#include "Recognizer.h"

#include "Classifier.h"


/**
 * Tworzy obiekt rozpoznawania, opcjonalnie przypisując słownik i rodzica.
 *
 * @param dict obiekt słownika wzorców
 * @param parent obiekt rodzica
 */
Recognizer::Recognizer(Dictionary *dict, QObject *parent):
    QObject(parent), m_classifier(0), m_dict(dict)
{
}

/**
 * Niszczy obiekt rozpoznawania.
 */
Recognizer::~Recognizer()
{
}
