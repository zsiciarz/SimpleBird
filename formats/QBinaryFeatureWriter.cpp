/**
 * @file QBinaryFeatureWriter.cpp
 *
 * Zapis tablicy cech do pliku binarnego za pomocą Qt - implementacja.
 *
 * @author Zbigniew Siciarz
 * @date 2009-2010
 * @version 0.8.2
 * @since 0.3.0
 */

#include "QBinaryFeatureWriter.h"

#include "aquila/Exceptions.h"
#include <QtCore>

namespace Aquila
{
    bool QBinaryFeatureWriter::write(const FeatureHeader& hdr,
        const Extractor::featureArrayType& featureArray)
    {
        if (featureArray.empty())
        {
            throw Exception("Empty feature array!");
        }

        QFile file(m_filename.c_str());
        if (!file.open(QIODevice::WriteOnly))
        {
            throw FormatException(qPrintable(file.errorString()));
        }

        QDataStream out(&file);
        out.setVersion(QDataStream::Qt_4_5);
        out << MAGIC_NUMBER;

        // header data
        out << QString::fromStdString(hdr.type) << quint16(hdr.frameLength) <<
               quint16(hdr.paramsPerFrame) << quint32(featureArray.size()) <<
               QString::fromStdString(hdr.wavFilename) << quint64(hdr.timestamp);

        // frames data
        for (unsigned int i = 0, size = featureArray.size(); i < size; ++i)
        {
            for (unsigned int j = 0; j < hdr.paramsPerFrame; ++j)
            {
                out << qreal(featureArray[i][j]);
            }
            out << FRAME_DELIMITER;
        }

        return out.status() == QDataStream::Ok;
    }
}
