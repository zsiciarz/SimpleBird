/**
 * @file FormatFactory.h
 *
 * Klasa fabryki produkującej różne interfejsy zapisu/odczytu - nagłówek.
 *
 * @author Zbigniew Siciarz
 * @date 2009-2010
 * @version 0.8.2
 * @since 0.4.0
 */

#ifndef FORMATFACTORY_H
#define FORMATFACTORY_H

#include "aquila/feature/Extractor.h"
#include "aquila/feature/FeatureReader.h"
#include "aquila/feature/FeatureWriter.h"
#include <QString>
#include <QStringList>


/**
 * Klasa fabryki produkującej różne interfejsy zapisu/odczytu.
 */
class FormatFactory
{
public:
    static QStringList getFeatureFormats();

    static QString getFeatureFormatsFilter();

    static Aquila::FeatureReader* getFeatureReader(QString filename,
        QString format = QString());

    static Aquila::FeatureWriter* getFeatureWriter(QString filename,
        QString format = QString());

    static Aquila::Extractor* readIntoExtractor(QString filename,
        QString format = QString());

    static Aquila::Extractor* getExtractor(QString featureType);

    static Aquila::Extractor* loadWavefileAndGetExtractor(QString filename,
        QString featureType = "MFCC");

private:
    static QString getExtension(QString filename);
};

#endif // FORMATFACTORY_H
