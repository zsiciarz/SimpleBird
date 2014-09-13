/**
 * @file SimpleBirdSettings.cpp
 * Ustawienia aplikacji - implementacja.
 *
 * @author Zbigniew Siciarz
 * @date 2009-2010
 * @version 0.8.2
 * @since 0.6.4
 */

#include "SimpleBirdSettings.h"

#include "aquila/global.h"
#include <QDesktopServices>
#include <QMapIterator>


QMap<QString, QVariant> SimpleBirdSettings::defaults;

/**
 * Tworzy obiekt ustawień aplikacji.
 *
 * Jeśli jest to pierwsze wywołanie ustawień, inicjalizuje domyślne wartości.
 */
SimpleBirdSettings::SimpleBirdSettings():
    QSettings()
{
    if (defaults.isEmpty())
        initDefaults();
}

/**
 * Zwraca wartość ustawień odpowiadającą danemu kluczowi.
 *
 * @param key klucz ustawień
 * @return wartość ustawień, lub wartość domyślna (zdefiniowana w tej klasie!)
 */
QVariant SimpleBirdSettings::value(QString key) const
{
    return QSettings::value(key, getDefaultValue(key));
}

/**
 * Przywraca domyślne wartości dla wszystkich opcji.
 */
void SimpleBirdSettings::restoreDefaults()
{
    QMapIterator<QString, QVariant> i(defaults);

    while (i.hasNext())
    {
        i.next();
        setValue(i.key(), i.value());
    }
}

/**
 * Zwraca wartość domyślną odpowiadającą danemu kluczowi.
 *
 * @param key klucz w ustawieniach (może być z grupą lub bez)
 * @return wartość domyślna lub nieprawidłowy QVariant dla nieistniejącego klucza
 */
QVariant SimpleBirdSettings::getDefaultValue(QString key) const
{
    if (!group().isEmpty())
        key = group() + "/" + key;

    return defaults.value(key);
}

/**
 * Inicjalizuje mapę wartości domyślnych.
 */
void SimpleBirdSettings::initDefaults()
{
    defaults["firstRun"]                    = true;
    defaults["general/defaultDirectory"]    = QDesktopServices::storageLocation(QDesktopServices::DocumentsLocation);
    defaults["general/verbosity"]           = 1;
    defaults["sound/frameLength"]           = 20;
    defaults["sound/frameOverlap"]          = 0.66;
    defaults["sound/windowType"]            = "Rectangular";
    defaults["sound/windowTypeIndex"]       = 0; // rectangular
    defaults["sound/preemphasis"]           = 0.9375;
    defaults["sound/paramsPerFrame"]        = 10;
    defaults["sound/enabledFilters"]        = QBitArray(Aquila::MELFILTERS, true);
    defaults["dtw/distanceType"]            = 0; // euclidean
    defaults["dtw/normalizationType"]       = 1; // diagonal
    defaults["dtw/passType"]                = 0; // neighbors
    defaults["recognizing/minPatternSize"]  = 0.6; // 60%
    defaults["recognizing/maxPatternSize"]  = 1.4; // 140%
    defaults["charts/addOverlay"]           = true;
    defaults["charts/defaultImageFormat"]   = ".png";
    defaults["charts/drawDtwAccumulated"]   = false;
    defaults["appearance/useStylesheet"]    = true;
    defaults["appearance/stylesheet"]       = "default";
    defaults["appearance/waveformColor"]    = QColor(Qt::red);
}
