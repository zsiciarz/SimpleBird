/**
 * @file QBinaryFeatureReader.cpp
 *
 * Odczyt tablicy cech z pliku binarnego za pomocą Qt - implementacja.
 *
 * @author Zbigniew Siciarz
 * @date 2009-2010
 * @version 0.8.2
 * @since 0.3.0
 */

#include "QBinaryFeatureReader.h"

#include "QBinaryFeatureWriter.h" // for magic numbers
#include "aquila/Exceptions.h"
#include <QtCore>
#include <ctime>

namespace Aquila
{
    bool QBinaryFeatureReader::readHeader(FeatureHeader& hdr)
    {
        QFile file(m_filename.c_str());
        if (!file.open(QIODevice::ReadOnly))
        {
            throw FormatException(qPrintable(file.errorString()));
        }

        QDataStream in(&file);
        in.setVersion(QDataStream::Qt_4_5);
        quint32 magic;
        in >> magic;
        if (magic != QBinaryFeatureWriter::MAGIC_NUMBER)
        {
            throw FormatException("Invalid file type!");
        }

        // reading header parameters
        QString type, wavFilename;
        quint16 frameLength;
        quint16 paramsPerFrame;
        quint32 framesCount;
        quint64 timestamp;
        in >> type >> frameLength >> paramsPerFrame >> framesCount >> wavFilename >> timestamp;
        hdr.type = type.toStdString();
        hdr.frameLength = (unsigned int)frameLength;
        hdr.paramsPerFrame = (unsigned int)paramsPerFrame;
        hdr.wavFilename = wavFilename.toStdString();
        hdr.timestamp = (std::time_t)timestamp;

        file.close();

        return true;
    }

    /**
     * The read function assumes that hdr and featureArray are empty!
     */
    bool QBinaryFeatureReader::read(FeatureHeader& hdr,
        Extractor::featureArrayType& featureArray)
    {
        QFile file(m_filename.c_str());
        if (!file.open(QIODevice::ReadOnly))
        {
            throw FormatException(qPrintable(file.errorString()));
        }

        QDataStream in(&file);
        in.setVersion(QDataStream::Qt_4_5);
        quint32 magic;
        in >> magic;
        if (magic != QBinaryFeatureWriter::MAGIC_NUMBER)
        {
            throw FormatException("Invalid file type!");
        }

        // reading header parameters
        QString type, wavFilename;
        quint16 frameLength;
        quint16 paramsPerFrame;
        quint32 framesCount;
        quint64 timestamp;
        in >> type >> frameLength >> paramsPerFrame >> framesCount >> wavFilename >> timestamp;
        hdr.type = type.toStdString();
        hdr.frameLength = (unsigned int)frameLength;
        hdr.paramsPerFrame = (unsigned int)paramsPerFrame;
        hdr.wavFilename = wavFilename.toStdString();
        hdr.timestamp = (std::time_t)timestamp;
        featureArray.resize(framesCount);

        // reading frames data
        qreal value;
        quint32 delimiter = 0;
        for (unsigned int i = 0; i < framesCount; ++i)
        {

            featureArray[i].resize(hdr.paramsPerFrame);
            for (unsigned int j = 0; j < hdr.paramsPerFrame; ++j)
            {
                in >> value;
                featureArray[i][j] = (double)value;
            }
            // safety check!
            delimiter = 0;
            in >> delimiter;
            if (delimiter != QBinaryFeatureWriter::FRAME_DELIMITER)
            {
                return false;
            }
        }
        return in.status() == QDataStream::Ok;
    }
}
