/**
 * @file WavePropertiesWidget.cpp
 *
 * Kontrolka informacji o nagraniu - implementacja.
 *
 * @author Zbigniew Siciarz
 * @date 2009-2010
 * @version 0.8.2
 * @since 0.2.1
 */

#include "WavePropertiesWidget.h"

#include <QFileInfo>
#include <QHeaderView>
#include <QMessageBox>
#include <QStringList>


/**
 * Tworzy kontrolkę i inicjalizuje tabelę.
 *
 * @param parent obiekt rodzica
 */
WavePropertiesWidget::WavePropertiesWidget(QWidget* parent):
    QTableWidget(11, 1, parent)
{
    // row labels
    QStringList labels;
    labels << tr("Filename") << tr("Full path") << tr("Length") <<
            tr("Channels") << tr("Bits per sample") << tr("Sample frequency") <<
            tr("Bytes per sample") << tr("Bytes per sec") << tr("Frames count") <<
            tr("Samples per frame") << tr("Samples per frame (ZP)");
    setVerticalHeaderLabels(labels);

    setAlternatingRowColors(true);
    setEditTriggers(QAbstractItemView::NoEditTriggers);
    setSelectionMode(QAbstractItemView::SingleSelection);

    QHeaderView* header =  horizontalHeader();
    header->setStretchLastSection(true);
    header->hide();

    setEnabled(false);
}

/**
 * Ustawia obiekt pliku dźwiękowego i wyświetla jego właściwości w tabeli.
 *
 * @param wav wskaźnik do obiektu reprezentującego nagranie
 */
void WavePropertiesWidget::setWaveFile(Aquila::WaveFile* wav)
{
    QString path = QString::fromStdString(wav->getFilename());
    QFileInfo fi(path);
    setItem(0, 0, new QTableWidgetItem(fi.fileName()));
    setItem(1, 0, new QTableWidgetItem(path));
    setItem(2, 0, new QTableWidgetItem(tr("%1 ms").arg(wav->getAudioLength())));
    QString channels = wav->getChannelsNum() == 2 ? tr("2 (stereo)") : tr("1 (mono)");
    setItem(3, 0, new QTableWidgetItem(channels));
    setItem(4, 0, new QTableWidgetItem(tr("%1").arg(wav->getBitsPerSamp())));
    setItem(5, 0, new QTableWidgetItem(tr("%1 Hz").arg(wav->getSampleFrequency())));
    setItem(6, 0, new QTableWidgetItem(tr("%1").arg(wav->getBytesPerSamp())));
    setItem(7, 0, new QTableWidgetItem(tr("%1").arg(wav->getBytesPerSec())));
    setItem(8, 0, new QTableWidgetItem(tr("%1").arg(wav->getFramesCount())));
    setItem(9, 0, new QTableWidgetItem(tr("%1").arg(wav->getSamplesPerFrame())));
    setItem(10, 0, new QTableWidgetItem(tr("%1").arg(wav->getSamplesPerFrameZP())));

    setEnabled(true);
}

