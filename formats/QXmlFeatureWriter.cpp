/**
 * @file QXmlFeatureWriter.cpp
 *
 * Zapis tablicy cech do pliku XML za pomocą Qt - implementacja.
 *
 * @author Zbigniew Siciarz
 * @date 2009-2010
 * @version 0.8.2
 * @since 0.3.0
 */

#include "QXmlFeatureWriter.h"

#include "aquila/global.h"
#include "aquila/Exceptions.h"
#include <QtCore>
#include <QXmlStreamWriter>

namespace Aquila
{
    bool QXmlFeatureWriter::write(const FeatureHeader& hdr,
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

        QXmlStreamWriter writer(&file);
        writer.setAutoFormatting(true);
        writer.writeStartDocument();
        writer.writeStartElement("featureFile");
        writer.writeAttribute("version", QString::fromStdString(VERSION));

        // header
        writer.writeStartElement("header");
        writer.writeTextElement("type", QString::fromStdString(hdr.type));
        writer.writeTextElement("frameLength", QString::number(hdr.frameLength));
        writer.writeTextElement("paramsPerFrame", QString::number(hdr.paramsPerFrame));
        writer.writeTextElement("framesCount", QString::number(featureArray.size()));
        writer.writeTextElement("wavFilename", QString::fromStdString(hdr.wavFilename));
        QDateTime dt;
        dt.setTime_t(hdr.timestamp);
        writer.writeTextElement("saveDateTime", dt.toString(Qt::ISODate));
        writer.writeEndElement();

        // frames data
        writer.writeStartElement("frames");
        for (unsigned int i = 0, size = featureArray.size(); i < size; ++i)
        {
            writer.writeStartElement("frame");
            writer.writeAttribute("number", QString::number(i));
            for (unsigned int j = 0; j < hdr.paramsPerFrame; ++j)
            {
                writer.writeTextElement("param", QString::number(featureArray[i][j], 'f', 12));
            }
            writer.writeEndElement();
        }
        writer.writeEndElement();

        writer.writeEndDocument();
        file.close();

        return true;
    }
}
