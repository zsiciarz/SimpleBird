/**
 * @file QBinaryFeatureReader.h
 *
 * Odczyt tablicy cech z pliku binarnego za pomocą Qt - nagłówek.
 *
 * @author Zbigniew Siciarz
 * @date 2009-2010
 * @version 0.8.2
 * @since 0.3.0
 */

#ifndef QBINARYFEATUREREADER_H
#define QBINARYFEATUREREADER_H

#include "aquila/feature/FeatureReader.h"


namespace Aquila
{
    /**
     * Klasa odczytu tablicy cech z pliku binarnego.
     */
    class QBinaryFeatureReader : public FeatureReader
    {
    public:
        QBinaryFeatureReader(const std::string& filename):
            FeatureReader(filename)
        {
        }

        virtual ~QBinaryFeatureReader()
        {
        }

        virtual bool readHeader(FeatureHeader& hdr);

        virtual bool read(FeatureHeader& hdr,
            Extractor::featureArrayType& featureArray);
    };
}

#endif // QBINARYFEATUREREADER_H
