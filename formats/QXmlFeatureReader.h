/**
 * @file QXmlFeatureReader.h
 *
 * Odczyt tablicy cech z pliku XML za pomocą Qt - nagłówek.
 *
 * @author Zbigniew Siciarz
 * @date 2009-2010
 * @version 0.8.2
 * @since 0.3.0
 */

#ifndef QXMLFEATUREREADER_H
#define QXMLFEATUREREADER_H

#include "aquila/feature/FeatureReader.h"
#include <QXmlStreamReader>


namespace Aquila
{
    /**
     * Klasa odczytu tablicy cech z pliku XML.
     */
    class QXmlFeatureReader : public FeatureReader
    {
    public:
        QXmlFeatureReader(const std::string& filename):
            FeatureReader(filename), ptrHdr(0), ptrFeatureArray(0), frameNum(0),
            paramNum(0)
        {
        }

        virtual ~QXmlFeatureReader()
        {
        }

        virtual bool readHeader(FeatureHeader& hdr);

        virtual bool read(FeatureHeader& hdr,
            Extractor::featureArrayType& featureArray);

    private:
        void readFeatureFileElement();
        void readHeaderElement();
        void readFramesElement();
        void readFrameElement();
        void readParamElement();
        void skipUnknownElement();

        FeatureHeader* ptrHdr;
        Extractor::featureArrayType* ptrFeatureArray;

        unsigned int frameNum;
        unsigned int paramNum;

        QXmlStreamReader reader;
    };
}

#endif // QXMLFEATUREREADER_H
