/**
 * @file FormatFactory.cpp
 *
 * Klasa fabryki produkującej różne interfejsy zapisu/odczytu - implementacja.
 *
 * @author Zbigniew Siciarz
 * @date 2009-2010
 * @version 0.8.2
 * @since 0.4.0
 */

#include "FormatFactory.h"

#include "aquila/global.h"
#include "aquila/Exceptions.h"
#include "aquila/feature/ExtractorFactory.h"
#include "aquila/feature/MfccExtractor.h"
#include "aquila/feature/TextFeatureWriter.h"
#include "QBinaryFeatureReader.h"
#include "QBinaryFeatureWriter.h"
#include "QXmlFeatureReader.h"
#include "QXmlFeatureWriter.h"
#include "../SimpleBirdSettings.h"
#include <QBitArray>
#include <QFileInfo>


/**
 * Zwraca listę obsługiwanych formatów plików cech.
 *
 * @return lista obsługiwanych rozszerzeń (wielkie litery!)
 */
QStringList FormatFactory::getFeatureFormats()
{
    return QStringList() << "BIR" << "XML";
}

/**
 * Zwraca ciąg znaków odpowiedni do podania do QFileDialog.
 *
 * @return filtr formatów
 */
QString FormatFactory::getFeatureFormatsFilter()
{
    return QObject::tr("Binary feature files (*.bir);;XML feature files (*.xml)");
}

/**
 * Zwraca obiekt odczytujący cechy odpowiadający danemu formatowi.
 *
 * Gdy nie podano formatu, funkcja próbuje go zgadnąć na podstawie rozszerzenia.
 *
 * @param filename pełna ścieżka do pliku cech
 * @param format format pliku, można pominąć
 * @return wskaźnik do obiektu czytnika, utworzony na stercie
 */
Aquila::FeatureReader* FormatFactory::getFeatureReader(QString filename, QString format)
{
    if (format.isEmpty())
        format = getExtension(filename);

    format = format.toUpper();

    if ("BIR" == format)
    {
        return new Aquila::QBinaryFeatureReader(filename.toStdString());
    }
    else if ("XML" == format)
    {
        return new Aquila::QXmlFeatureReader(filename.toStdString());
    }
    else
    {
        throw Aquila::FormatException("Cannot read from file in format: " + format.toStdString());
    }
}

/**
 * Zwraca obiekt zapisujący cechy odpowiadający danemu formatowi.
 *
 * Gdy nie podano formatu, funkcja próbuje go zgadnąć na podstawie rozszerzenia.
 *
 * @param filename pełna ścieżka do pliku cech
 * @param format format pliku, można pominąć
 * @return wskaźnik do obiektu zapisującego, utworzony na stercie
 */
Aquila::FeatureWriter* FormatFactory::getFeatureWriter(QString filename, QString format)
{
    if (format.isEmpty())
        format = getExtension(filename);

    format = format.toUpper();
    if ("BIR" == format)
    {
        return new Aquila::QBinaryFeatureWriter(filename.toStdString());
    }
    else if ("XML" == format)
    {
        return new Aquila::QXmlFeatureWriter(filename.toStdString());
    }
    else if ("TXT" == format)
    {
        return new Aquila::TextFeatureWriter(filename.toStdString());
    }
    else
    {
        throw Aquila::FormatException("Cannot write to file in format: " + format.toStdString());
    }
}

/**
 * Wczytuje plik cech i zwraca obiekt ekstraktora.
 *
 * Funkcja upraszcza najczęściej wykonywane zadanie, czyli odczyt pliku do
 * obiektu ekstraktora.
 *
 * @param filename pełna ścieżka do pliku cech
 * @param format format pliku, można pominąć
 * @return wskaźnik do obiektu ekstraktora, utworzony na stercie
 */
Aquila::Extractor* FormatFactory::readIntoExtractor(QString filename, QString format)
{
    Aquila::FeatureReader* reader = getFeatureReader(filename, format);
    Aquila::FeatureHeader hdr;
    reader->readHeader(hdr);
    Aquila::Extractor* extractor = Aquila::ExtractorFactory::getExtractor(hdr);
    extractor->read(*reader);
    delete reader;

    return extractor;
}

/**
 * Tworzy obiekt ekstraktora cech z aktualnymi ustawieniami.
 *
 * @param featureType typ cech
 * @return wskaźnik do obiektu ekstraktora, utworzonego na stercie
 */
Aquila::Extractor* FormatFactory::getExtractor(QString featureType)
{
    SimpleBirdSettings settings;

    Aquila::Extractor* extractor = Aquila::ExtractorFactory::getExtractor(
        featureType.toStdString(),
        settings.getFrameLength(),
        settings.getParamsPerFrame());

    if ("MFCC" == featureType || "HFCC" == featureType)
    {
        QBitArray enabledFilters = settings.getEnabledFilters();
        bool enabled[Aquila::MELFILTERS];
        for (unsigned int i = 0; i < Aquila::MELFILTERS; ++i)
            enabled[i] = enabledFilters.testBit(i);

        ((Aquila::MfccExtractor*)extractor)->setEnabledMelFilters(enabled);
    }

    return extractor;
}

/**
 * Przelicza cechy (w sposób blokujący!) i zwraca gotowy ekstraktor.
 *
 * @param filename pełna ścieżka do pliku
 * @param featureType typ cech (domyślnie MFCC)
 */
Aquila::Extractor* FormatFactory::loadWavefileAndGetExtractor(QString filename, QString featureType)
{
    SimpleBirdSettings settings;
    Aquila::WaveFile* wav = new Aquila::WaveFile(settings.getFrameLength(), settings.getOverlap());
    wav->load(filename.toStdString());

    Aquila::TransformOptions options;
    options.windowType = settings.getWindowType();
    options.zeroPaddedLength = wav->getSamplesPerFrameZP();
    options.preemphasisFactor = settings.getPreemphasis();

    Aquila::Extractor* extractor = getExtractor(featureType);
    extractor->process(wav, options);

    delete wav;

    return extractor;
}

/**
 * Zwraca rozszerzenie dla danej nazwy pliku.
 *
 * @param filename pełna ścieżka do pliku
 * @return rozszerzenie pliku
 */
QString FormatFactory::getExtension(QString filename)
{
    return QFileInfo(filename).completeSuffix();
}
