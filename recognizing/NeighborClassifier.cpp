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

#include "NeighborClassifier.h"

#include <limits>


/**
 * Konstruktor - tworzy obiekt klasyfikatora.
 *
 * @param parent obiekt rodzica
 */
NeighborClassifier::NeighborClassifier(QObject *parent):
    Classifier(parent)
{
}

/**
 * Dodaje kolejne dane do klasyfikatora.
 *
 * @param distance odległość danej
 * @param label etykieta związana z tą daną
 */
void NeighborClassifier::addEntry(double distance, QString label)
{
    entries[distance] = label;
}

/**
 * Czyści wszystkie zgromadzone dane.
 */
void NeighborClassifier::clear()
{
    entries.clear();
}

/**
 * Przeprowadza klasyfikację metodą najbliższych sąsiadów.
 *
 * @return wynik klasyfikacji
 */
RecognizingResult NeighborClassifier::classify()
{
    RecognizingResult result;
    result.label = "unknown";
    result.distance = std::numeric_limits<double>::max();

    if (entries.size() == 0)
        return result;

    result.label = entries.begin().value();
    result.distance = entries.begin().key();
    return result;
}
