/**
 * @file QXmlFeatureWriter.h
 *
 * Zapis tablicy cech do pliku XML za pomocą Qt - nagłówek.
 *
 * @author Zbigniew Siciarz
 * @date 2009-2010
 * @version 0.8.2
 * @since 0.3.0
 */

#ifndef QXMLFEATUREWRITER_H
#define QXMLFEATUREWRITER_H

#include "aquila/feature/FeatureWriter.h"

namespace Aquila
{
    /**
     * Klasa zapisu tablicy cech do pliku XML.
     */
    class QXmlFeatureWriter : public FeatureWriter
    {
    public:
        QXmlFeatureWriter(const std::string& filename):
            FeatureWriter(filename)
        {
        }

        virtual ~QXmlFeatureWriter()
        {
        }

        virtual bool write(const FeatureHeader& hdr,
            const Extractor::featureArrayType& featureArray);
    };
}

#endif // QXMLFEATUREWRITER_H
