/**
 * @file Benchmark.cpp
 *
 * Testowanie wydajności programu i bibliotek - implementacja.
 *
 * @author Zbigniew Siciarz
 * @date 2009-2010
 * @version 0.8.2
 * @since 0.6.2
 */

#include "Benchmark.h"

#include "BenchmarkDialog.h"
#include "aquila/feature/MfccExtractor.h"
#include "aquila/dtw/Dtw.h"
#include "aquila/Transform.h"
#include "aquila/WaveFile.h"
#include "SimpleBirdApplication.h"
#include "formats/FormatFactory.h"
#include <QApplication>
#include <QTime>
#include <algorithm>
#include <numeric>

Benchmark::Benchmark():
    ITERATIONS(100)
{
    std::srand(std::time(0));
}

void Benchmark::run()
{
    qApp->processEvents();
    BenchmarkDialog dlg;
    if (!dlg.exec())
        return;

    qApp->setOverrideCursor(Qt::WaitCursor);
    emit sendMessage(tr("Benchmarking, please wait..."));

    ITERATIONS = dlg.getIterationsCount();

    if (dlg.enableFft())
        testFft();
    if (dlg.enableDct())
        testDct();
    if (dlg.enableWave())
        testWavefile();
    if (dlg.enableEnergy())
        testEnergy();
    if (dlg.enableMfcc())
        testMfcc();
    if (dlg.enableDtw())
        testDtw();

    qApp->restoreOverrideCursor();

    double result = std::accumulate(durations.begin(), durations.end(), 0.0);
    emit sendMessage(tr("Benchmarking finished."));
    emit sendMessage(tr("Total result: %1").arg(result, 0, 'f', 2));
}

void Benchmark::testFft()
{
    startTime = clock();

    const int TEST_DATA_SIZE = 65536;
    std::vector<double> testData(TEST_DATA_SIZE);
    Aquila::spectrumType spectrum(TEST_DATA_SIZE);
    Aquila::Transform transform(0);
    for (int i = 0; i < ITERATIONS; ++i)
    {
        std::generate(testData.begin(), testData.end(), generateRandomDouble);
        transform.fft(testData, spectrum);
    }

    double duration = clock() - startTime;
    durations.push_back(duration);
    emit sendMessage(tr("FFT: %1").arg(duration));
    qApp->processEvents();
}

void Benchmark::testDct()
{
    startTime = clock();

    const int TEST_DATA_SIZE = 128, DCT_SIZE = 12;
    std::vector<double> testData(TEST_DATA_SIZE), dctOutput(DCT_SIZE);
    Aquila::Transform transform(0);
    for (int i = 0; i < ITERATIONS; ++i)
    {
        std::generate(testData.begin(), testData.end(), generateRandomDouble);
        transform.dct(testData, dctOutput);
    }

    double duration = clock() - startTime;
    durations.push_back(duration);
    emit sendMessage(tr("DCT: %1").arg(duration));
    qApp->processEvents();
}

void Benchmark::testWavefile()
{
    startTime = clock();

    Aquila::WaveFile* wav = new Aquila::WaveFile(20, 0.66);
    QString filename = SimpleBirdApplication::directoryOf("samples") + "/test.wav";
    for (int i = 0; i < ITERATIONS; ++i)
    {
        wav->load(filename.toStdString());
    }

    delete wav;
    double duration = clock() - startTime;
    durations.push_back(duration);
    emit sendMessage(tr("Wave file: %1").arg(duration));
    qApp->processEvents();
}

void Benchmark::testEnergy()
{
    startTime = clock();

    Aquila::WaveFile* wav = new Aquila::WaveFile(20, 0.66);
    QString filename = SimpleBirdApplication::directoryOf("samples") + "/test.wav";
    wav->load(filename.toStdString());

    Aquila::Transform transform(0);
    double energy;
    for (int i = 0; i < ITERATIONS; ++i)
    {
        for (unsigned int j = 0; j < wav->getFramesCount(); ++j)
        {
            energy = transform.frameLogEnergy(wav->frames[j]);
        }
    }

    delete wav;
    double duration = clock() - startTime;
    durations.push_back(duration);
    emit sendMessage(tr("Energy: %1").arg(duration));
    qApp->processEvents();
}

void Benchmark::testMfcc()
{
    startTime = clock();

    Aquila::WaveFile* wav = new Aquila::WaveFile(20, 0.66);
    QString filename = SimpleBirdApplication::directoryOf("samples") + "/test.wav";
    Aquila::MfccExtractor* extractor = new Aquila::MfccExtractor(20, 10);

    wav->load(filename.toStdString());

    Aquila::TransformOptions options;
    options.preemphasisFactor = 0.9375;
    options.windowType = Aquila::WIN_HAMMING;
    options.zeroPaddedLength = wav->getSamplesPerFrameZP();

    extractor->process(wav, options);

    delete wav;
    delete extractor;
    double duration = clock() - startTime;
    durations.push_back(duration);
    emit sendMessage(tr("MFCC: %1").arg(duration));
    qApp->processEvents();
}

void Benchmark::testDtw()
{
    startTime = clock();

    QString fromFile = SimpleBirdApplication::directoryOf("samples") + "/from.bir";
    QString toFile = SimpleBirdApplication::directoryOf("samples") + "/to.bir";
    Aquila::Extractor* from = FormatFactory::readIntoExtractor(fromFile);
    Aquila::Extractor* to = FormatFactory::readIntoExtractor(toFile);
    Aquila::Dtw* dtw = new Aquila::Dtw(from);

    double distance;
    for (int i = 0; i < ITERATIONS; ++i)
    {
        distance = dtw->getDistance(to);
    }

    delete dtw;
    delete to;
    delete from;

    double duration = clock() - startTime;
    durations.push_back(duration);
    emit sendMessage(tr("DTW: %1").arg(duration));
    qApp->processEvents();
}


double Benchmark::clock()
{
    QTime t = QTime::currentTime();
    return t.msec() + 1000.0 * t.second() + 60 * 1000.0 * t.minute() + 24 * 60 * 1000.0 * t.hour();
}


double generateRandomDouble()
{
    return 255.0 * std::rand() / double(RAND_MAX);
}
