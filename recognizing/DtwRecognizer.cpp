/**
 * @file DtwRecognizer.cpp
 *
 * Rozpoznawanie i klasyfikacja metodą DTW - implementacja.
 *
 * @author Zbigniew Siciarz
 * @date 2009-2010
 * @version 0.8.2
 * @since 0.7.0
 */

#include "DtwRecognizer.h"

#include "aquila/WaveFile.h"
#include "aquila/dtw/Dtw.h"
#include "formats/FormatFactory.h"
#include "NeighborClassifier.h"
#include "SimpleBirdSettings.h"
#include <QApplication>
#include <QDateTime>
#include <QFile>


DtwRecognizer::DtwRecognizer(Dictionary* dict, QObject *parent) :
    Recognizer(dict, parent)
{
}

RecognizingResult DtwRecognizer::recognizeFile(QString filename)
{
    SimpleBirdSettings settings;
    int verbosity = settings.getVerbosity();

    emit sendMessage(tr("Recognizing file: %1").arg(filename), Qt::darkGreen);
    QDateTime start = QDateTime::currentDateTime();
    emit sendMessage(tr("Started at %1").arg(start.toString()));

    int total = m_dict->countEntries();
    emit progressRangeChanged(0, total-1);

    if (!m_classifier)
        m_classifier = new NeighborClassifier(this);
    m_classifier->clear();

    emit sendMessage(tr("Calculating features for recognized signal..."));
    Aquila::Extractor* signal = FormatFactory::loadWavefileAndGetExtractor(filename);
    emit sendMessage(tr("Signal feature information: %1, frames count: %2, params per frame: %3").
        arg(signal->getType().c_str()).arg(signal->getFramesCount()).
        arg(signal->getParamsPerFrame()));
    emit sendMessage(tr("Preprocessing done, starting recognition..."));

    Aquila::Dtw* dtw = new Aquila::Dtw(signal);
    Aquila::Dtw::NormalizationType normalization = settings.getDtwNormalizationType();
    dtw->setDistanceFunction(settings.getDtwDistanceType());
    dtw->setPassType(settings.getDtwPassType());

    unsigned int minPatternLength = static_cast<unsigned int>(
        settings.value("recognizing/minPatternSize").toDouble() * signal->getFramesCount());
    unsigned int maxPatternLength = static_cast<unsigned int>(
        settings.value("recognizing/maxPatternSize").toDouble() * signal->getFramesCount());

    Dictionary::entryMap entries = m_dict->entries();
    Dictionary::entryMapIterator it(entries);
    int i = 0, correct = 0, skipped = 0;
    while (it.hasNext())
    {
        it.next();
        QString patternFile = m_dict->getCorrespondingFeatureFilename(it.key());

        if (verbosity > 0)
            emit sendMessage(tr("Loading pattern file %1 (%2 of %3)...").
                arg(patternFile).arg(i + 1).arg(total), Qt::darkYellow);

        if (!QFile::exists(patternFile))
        {
            if (verbosity > 0)
                emit sendMessage(tr("***File not found, skipping"), Qt::red);
            skipped++;
            i++;
            continue;
        }

        Aquila::Extractor* pattern = FormatFactory::readIntoExtractor(patternFile);
        if (verbosity > 1)
        {
            emit sendMessage(tr("Pattern feature information: %1, frames count: %2, params per frame: %3").
               arg(pattern->getType().c_str()).arg(pattern->getFramesCount()).
               arg(pattern->getParamsPerFrame()));
            emit sendMessage(tr("Labeled as: %1").arg(it.value()));
        }

        unsigned int patternLength = pattern->getFramesCount();
        if (patternLength < minPatternLength || patternLength > maxPatternLength)
        {
            if (verbosity > 0)
                emit sendMessage(tr("***Pattern too long or too short, skipping"), Qt::red);
            delete pattern;
            skipped++;
            i++;
            continue;
        }

        if (!signal->isCompatible(pattern))
        {
            if (verbosity > 0)
                emit sendMessage(tr("***Pattern incompatible, skipping"), Qt::red);
            delete pattern;
            skipped++;
            i++;
            continue;
        }

        if (verbosity > 1)
            emit sendMessage(tr("Pattern compatible, calculating distance..."));
        correct++;
        double distance = dtw->getDistance(pattern, normalization);
        m_classifier->addEntry(distance, it.value());
        if (verbosity > 1)
            emit sendMessage(tr("Distance: %1").arg(distance, 0, 'f', 4), Qt::darkGreen);

        delete pattern;
        qApp->processEvents();
        emit progressChanged(i++);
    }

    emit sendMessage(tr("Recognizing finished, classifying..."), Qt::darkGreen);

    RecognizingResult result = m_classifier->classify();
    emit sendMessage(tr("Classifying finished, result: <b>%1</b> (distance: %2)").
        arg(result.label).arg(result.distance, 0, 'f', 4), Qt::darkGreen);
    emit sendMessage(tr("Correct patterns: %1, skipped: %2").arg(correct).arg(skipped));
    QDateTime stop = QDateTime::currentDateTime();
    emit sendMessage(tr("Finished at %1").arg(stop.toString()));
    double duration = start.time().msecsTo(stop.time()) / 1000.0;
    emit sendMessage(tr("Total time: %1 seconds").arg(duration, 0, 'f', 2));

    delete dtw;
    delete signal;

    return result;
}
