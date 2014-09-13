/**
 * @file QBinaryFeatureWriter.h
 *
 * Zapis tablicy cech do pliku binarnego za pomocą Qt - nagłówek.
 *
 * @author Zbigniew Siciarz
 * @date 2009-2010
 * @version 0.8.2
 * @since 0.3.0
 */

#ifndef QBINARYFEATUREWRITER_H
#define QBINARYFEATUREWRITER_H

#include "aquila/feature/FeatureWriter.h"
#include <QtGlobal>


namespace Aquila
{
    /**
     * Klasa zapisu tablicy cech do pliku binarnego.
     */
    class QBinaryFeatureWriter : public FeatureWriter
    {
    public:
        static const quint32 MAGIC_NUMBER = 0xFEA1004E; // almost like FEATOORE ;)

        static const quint32 FRAME_DELIMITER = 0x00101000;

        QBinaryFeatureWriter(const std::string& filename):
            FeatureWriter(filename)
        {
        }

        virtual ~QBinaryFeatureWriter()
        {
        }

        virtual bool write(const FeatureHeader& hdr,
            const Extractor::featureArrayType& featureArray);
    };
}

#endif // QBINARYFEATUREWRITER_H
