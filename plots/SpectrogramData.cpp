/**
 * @file SpectrogramData.h
 *
 * Klasa danych spektrogramu - implementacja.
 *
 * @author Zbigniew Siciarz
 * @date 2009-2010
 * @version 0.8.2
 * @since 0.1.0
 */

#include "SpectrogramData.h"

#include "aquila/Transform.h"
#include "SimpleBirdSettings.h"
#include <QApplication>
#include <QProgressDialog>


/**
 * Konstruktor - przypisuje parametry nagrania i widm.
 *
 * @param wavefile wskaźnik do obiektu nagrania
 */
SpectrogramData::SpectrogramData(Aquila::WaveFile* wavefile):
    QwtRasterData(), framesCount(0), maxSpectrum(0.0), canceled(false)
{
    unsigned int framesCount = wavefile->getFramesCount();
    spectrumSize = wavefile->getSamplesPerFrameZP();

    SimpleBirdSettings settings;
    QString windowString = settings.value("sound/windowType").toString();
    Aquila::WindowType window = settings.getWindowType();
    double preemphasis = settings.getPreemphasis();

    Aquila::Transform transform(spectrumSize, window, preemphasis);

    QProgressDialog progress(QObject::tr("Generating spectrogram..."),
        QObject::tr("Cancel"), 0, framesCount);
    progress.setMinimumDuration(0);
    progress.setWindowModality(Qt::WindowModal);

    double maxFFT = 0.0;
    for (unsigned int i = 0; i < framesCount; ++i)
    {
        if (progress.wasCanceled())
        {
            canceled = true;
            break;
        }

        Aquila::spectrumType spectrum;
        spectrum.resize(spectrumSize);
        maxFFT = transform.fft(wavefile->frames[i], spectrum);
        if (maxFFT > maxSpectrum)
            maxSpectrum = maxFFT;
        frameSpectra.append(spectrum);
        progress.setValue(i);
        qApp->processEvents();
    }
    logMaxSpectrum = 20.0 * std::log10(maxSpectrum);
    setBoundingRect(QwtDoubleRect(0, 0, framesCount, spectrumSize/2));
    info = QObject::tr("window: %1, preemphasis: %2, spectrum size: %3").
        arg(windowString).arg(preemphasis, 0, 'f', 4).arg(spectrumSize);
}

/**
 * Konstruktor prywatny - przypisuje parametry nagrania i widm.
 *
 * @param spectra tablica widm wszystkich ramek
 * @param maxFFT największa wartość modułu widma w całym nagraniu
 */
SpectrogramData::SpectrogramData(QVector<Aquila::spectrumType> spectra, double maxFFT):
    QwtRasterData(QwtDoubleRect(0, 0, spectra.size(), spectra[0].size()/2)),
    framesCount(spectra.size()), spectrumSize(spectra[0].size()/2), maxSpectrum(maxFFT)
{
    logMaxSpectrum = 20.0 * std::log10(maxSpectrum);
    frameSpectra = spectra;
}

/**
 * Destruktor - nie robi nic.
 */
SpectrogramData::~SpectrogramData()
{
}

/**
 * Klonuje obiekt danych.
 *
 * @return kopia obiektu danych utworzona na stercie
 */
QwtRasterData* SpectrogramData::copy() const
{
    SpectrogramData* data = new SpectrogramData(frameSpectra, maxSpectrum);
    data->info = info;
    return data;
}

/**
 * Zwraca zakres wartości spektrogramu.
 *
 * @return przedział od zera do maksymalnej wartości widma
 */
QwtDoubleInterval SpectrogramData::range() const
{
    return QwtDoubleInterval(-logMaxSpectrum, 0.0);
}

/**
 * Zwraca wartość spektrogramu w danym punkcie.
 *
 * @param x współrzędna pozioma
 * @param y współrzędna pionowa
 * @return wartość w punkcie (x, y)
 */
double SpectrogramData::value(double x, double y) const
{
    unsigned int frame = qBound(0u, static_cast<unsigned int>(x), framesCount - 1);
    unsigned int peak = qBound(0u, static_cast<unsigned int>(y), spectrumSize - 1);

    return 20.0 * std::log10(std::abs(frameSpectra[frame][peak])) - logMaxSpectrum;
}
