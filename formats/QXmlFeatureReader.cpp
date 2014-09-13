/**
 * @file QXmlFeatureReader.cpp
 *
 * Odczyt tablicy cech z pliku XML za pomocą Qt - implementacja.
 *
 * @author Zbigniew Siciarz
 * @date 2009-2010
 * @version 0.8.2
 * @since 0.3.0
 */

#include "QXmlFeatureReader.h"

#include "aquila/Exceptions.h"
#include <QtCore>


namespace Aquila
{
    bool QXmlFeatureReader::readHeader(FeatureHeader& hdr)
    {
        QFile file(m_filename.c_str());
        if (!file.open(QIODevice::ReadOnly | QFile::Text))
        {
            throw FormatException(qPrintable(file.errorString()));
        }

        QTextStream in(&file);
        in.setCodec("UTF-8");

        QString line;
        QRegExp rxType("<type>(\\w+)</type>");
        QRegExp rxFrameLength("<frameLength>(\\d+)</frameLength>");
        QRegExp rxParamsPerFrame("<paramsPerFrame>(\\d+)</paramsPerFrame>");
        QRegExp rxEndHeader("</header>");
        do
        {
            line = in.readLine();
            if (rxType.indexIn(line) != -1)
                hdr.type = rxType.cap(1).toStdString();
            if (rxFrameLength.indexIn(line) != -1)
                hdr.frameLength = rxFrameLength.cap(1).toUInt();
            if (rxParamsPerFrame.indexIn(line) != -1)
                hdr.paramsPerFrame = rxParamsPerFrame.cap(1).toUInt();

            if (rxEndHeader.indexIn(line) != -1)
                break;
        }
        while (!line.isNull());
        file.close();

        return true;
    }

    bool QXmlFeatureReader::read(FeatureHeader& hdr,
        Extractor::featureArrayType& featureArray)
    {
        QFile file(m_filename.c_str());
        if (!file.open(QIODevice::ReadOnly | QFile::Text))
        {
            throw FormatException(qPrintable(file.errorString()));
        }

        ptrHdr = &hdr;
        ptrFeatureArray = &featureArray;
        reader.setDevice(&file);
        reader.readNext();
        while (!reader.atEnd())
        {
            if (reader.isStartElement())
            {
                if (reader.name() == "featureFile")
                {
                    readFeatureFileElement();
                }
                else
                {
                    reader.raiseError(QObject::tr("Not a feature file!"));
                }
            }
            else
            {
                reader.readNext();
            }
        }

        file.close();
        if (reader.hasError())
        {
            QString msg = QObject::tr("Parse error at line %1: %2").
                arg(reader.lineNumber()).
                arg(reader.errorString());
            throw FormatException(msg.toStdString());
        }

        return true;
    }

    void QXmlFeatureReader::readFeatureFileElement()
    {
        reader.readNext();
        while (!reader.atEnd())
        {
            if (reader.isEndElement())
            {
                reader.readNext();
                break;
            }
            if (reader.isStartElement())
            {
                if (reader.name() == "header")
                {
                    readHeaderElement();
                }
                else if (reader.name() == "frames")
                {
                    readFramesElement();
                }
                else
                {
                    skipUnknownElement();
                }
            }
            else
            {
                reader.readNext();
            }
        }
    }

    void QXmlFeatureReader::readHeaderElement()
    {
        QString value;
        reader.readNext();
        while (!reader.atEnd())
        {
            if (reader.isEndElement())
            {
                reader.readNext();
                break;
            }
            if (reader.isStartElement())
            {
                if (reader.name() == "type")
                {
                    value = reader.readElementText();
                    ptrHdr->type = value.toStdString();
                    if (reader.isEndElement())
                        reader.readNext();
                }
                else if (reader.name() == "frameLength")
                {
                    value = reader.readElementText();
                    bool ok;
                    unsigned int frameLength = value.toUInt(&ok);
                    if (!ok)
                    {
                        reader.raiseError(QObject::tr(
                            "Frame length is not a number, value read: %1").arg(value));
                        return;
                    }

                    ptrHdr->frameLength = frameLength;
                    if (reader.isEndElement())
                        reader.readNext();
                }
                else if (reader.name() == "paramsPerFrame")
                {
                    value = reader.readElementText();
                    bool ok;
                    unsigned int paramsPerFrame = value.toUInt(&ok);
                    if (!ok)
                    {
                        reader.raiseError(QObject::tr(
                            "Params per frame is not a number, value read: %1").arg(value));
                        return;
                    }

                    ptrHdr->paramsPerFrame = paramsPerFrame;
                    if (reader.isEndElement())
                        reader.readNext();
                }
                else if (reader.name() == "framesCount")
                {
                    value = reader.readElementText();
                    bool ok;
                    unsigned int framesCount = value.toUInt(&ok);
                    if (!ok)
                    {
                        reader.raiseError(QObject::tr(
                            "Frames count is not a number, value read: %1").arg(value));
                        return;
                    }

                    ptrFeatureArray->resize(framesCount);
                    if (reader.isEndElement())
                        reader.readNext();
                }
                else if (reader.name() == "wavFilename")
                {
                    value = reader.readElementText();
                    ptrHdr->wavFilename = value.toStdString();
                    if (reader.isEndElement())
                        reader.readNext();
                }
                else if (reader.name() == "saveDateTime")
                {
                    value = reader.readElementText();
                    QDateTime dt = QDateTime::fromString(value, Qt::ISODate);
                    if (!dt.isValid())
                    {
                        reader.raiseError(QObject::tr(
                            "saveDateTimet is not a valid ISO date, value read: %1").arg(value));
                        return;
                    }
                    ptrHdr->timestamp = dt.toTime_t();
                    if (reader.isEndElement())
                        reader.readNext();
                }
                else
                {
                    skipUnknownElement();
                }
            }
            else
            {
                reader.readNext();
            }
        }
    }

    void QXmlFeatureReader::readFramesElement()
    {
        reader.readNext();
        while (!reader.atEnd())
        {
            if (reader.isEndElement())
            {
                reader.readNext();
                break;
            }
            if (reader.isStartElement())
            {
                if (reader.name() == "frame")
                {
                    readFrameElement();
                    frameNum++;
                }
                else
                {
                    skipUnknownElement();
                }
            }
            else
            {
                reader.readNext();
            }
        }
    }

    void QXmlFeatureReader::readFrameElement()
    {
        reader.readNext();
        paramNum = 0;
        if (frameNum >= ptrFeatureArray->size())
        {
            reader.raiseError(QObject::tr("Frames count exceed declared value %1").
                arg(ptrFeatureArray->size()));
            return;
        }
        ptrFeatureArray->at(frameNum).resize(ptrHdr->paramsPerFrame);

        while (!reader.atEnd())
        {
            if (reader.isEndElement())
            {
                reader.readNext();
                break;
            }
            if (reader.isStartElement())
            {
                if (reader.name() == "param")
                {
                    readParamElement();
                    paramNum++;
                }
                else
                {
                    skipUnknownElement();
                }
            }
            else
            {
                reader.readNext();
            }
        }
    }

    void QXmlFeatureReader::readParamElement()
    {
        if (paramNum >= ptrHdr->paramsPerFrame)
        {
            reader.raiseError(QObject::tr("Params per frame count exceed declared value %1").
                arg(ptrHdr->paramsPerFrame));
            return;
        }

        bool ok;
        QString text = reader.readElementText();
        double value = text.toDouble(&ok);
        if (!ok)
        {
            reader.raiseError(QObject::tr(
                "Param is not a number, value read: %1").arg(text));
            return;
        }
        ptrFeatureArray->at(frameNum).at(paramNum) = value;

        if (reader.isEndElement())
            reader.readNext();
    }

    void QXmlFeatureReader::skipUnknownElement()
    {
        reader.readNext();
        while (!reader.atEnd())
        {
            if (reader.isEndElement())
            {
                reader.readNext();
                break;
            }
            if (reader.isStartElement())
            {
                skipUnknownElement();
            }
            else
            {
                reader.readNext();
            }
        }
    }
}
