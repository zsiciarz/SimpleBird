/**
 * @file FilesWidget.h
 *
 * Kontrolka zarządzająca aktualnie otwartymi plikami - nagłówek.
 *
 * @author Zbigniew Siciarz
 * @date 2009-2010
 * @version 0.8.2
 * @since 0.6.0
 */

#ifndef FILESWIDGET_H
#define FILESWIDGET_H

#include "aquila/WaveFile.h"
#include "aquila/feature/Extractor.h"
#include <QListWidgetItem>
#include <QMap>
#include <QModelIndex>
#include <QString>
#include <QStringList>
#include <QWidget>

namespace Ui {
    class FilesWidget;
}

/**
 * Kontrolka zarządzająca aktualnie otwartymi plikami.
 */
class FilesWidget : public QWidget
{
    Q_OBJECT

public:
    FilesWidget(QWidget *parent = 0);
    ~FilesWidget();

    /**
     * Typ aktualnie wczytanego pliku.
     */
    enum FileType { Wave, Feature, Unknown };

    QString currentFile() const;

    FileType currentFileType() const;

    bool hasFile(QString filename);

    Aquila::WaveFile* currentWaveFile() const;
    void recalculateWaveFiles(unsigned int frameLength, double overlap);
    Aquila::Extractor* currentExtractor() const;

public slots:
    void addFile(QString filename);

    void addExtractor(Aquila::Extractor* extractor);

    void closeCurrentFile();

signals:
    /**
     * Sygnał emitowany gdy kontrolka wysyła wiadomość na zewnątrz.
     *
     * @param message wiadomość
     */
    void sendMessage(QString message);

    /**
     * Sygnał emitowany w chwili zmiany zaznaczonego pliku.
     */
    void fileChanged(QString filename, FileType type);

    /**
     * Sygnał emitowany, gdy zażądano narysowania dowolnego wykresu.
     */
    void chartRequested();

    /**
     * Sygnał emitowany, gdy zażądano narysowania wykresu przebiegu nagrania.
     */
    void waveformRequested(Aquila::WaveFile* wav);

    /**
     * Sygnał emitowany, gdy zażądano narysowania spektrogramu.
     */
    void spectrogramRequested(Aquila::WaveFile* wav);

    /**
     * Sygnał emitowany, gdy zażądano narysowania wykresu cech.
     */
    void featureChartRequested(Aquila::Extractor* extractor);

    /**
     * Sygnał emitowany, gdy zażądano narysowania wykresu cech dla pliku dźwiękowego.
     */
    void featureCalculationRequested();

    /**
     * Sygnał emitowany, gdy zażądano narysowania diagramu DTW.
     */
    void dtwChartRequested(Aquila::Extractor* extractor);


private slots:
    void currentItemChanged(QListWidgetItem* current, QListWidgetItem* previous);
    void doubleClicked(QModelIndex index);
    void updateUi();
    void waveformClicked();
    void spectrogramClicked();
    void featureChartClicked();
    void dtwChartClicked();

private:
    void loadWaveFile(const QString& filename);
    void loadFeatureFile(const QString& filename, const QString& format);

    /**
     * Obiekt interfejsu wygenerowany przez Designera.
     */
    Ui::FilesWidget *ui;

    /**
     * Lista wszystkich aktualnie wczytanych plików.
     */
    QStringList loadedFiles;

    /**
     * Wczytane pliki dźwiękowe.
     */
    QMap<QString, Aquila::WaveFile*> wavefiles;

    /**
     * Wczytane pliki cech.
     */
    QMap<QString, Aquila::Extractor*> extractors;

    /**
     * Liczba niezapisanych obiektów cech.
     */
    int unsavedCount;
};

#endif // FILESWIDGET_H
