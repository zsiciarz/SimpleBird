/**
 * @file Benchmark.h
 *
 * Testowanie wydajności programu i bibliotek - nagłówek.
 *
 * @author Zbigniew Siciarz
 * @date 2009-2010
 * @version 0.8.2
 * @since 0.6.2
 */

#ifndef BENCHMARK_H
#define BENCHMARK_H

#include <QObject>
#include <QString>
#include <vector>

class Benchmark : public QObject
{
    Q_OBJECT

public:
    Benchmark();
    void run();

signals:
    void sendMessage(QString msg);

private:
    void testFft();
    void testDct();
    void testWavefile();
    void testEnergy();
    void testMfcc();
    void testDtw();

    double clock();

    int ITERATIONS;

    double startTime;

    std::vector<double> durations;
};

double generateRandomDouble();

#endif // BENCHMARK_H
