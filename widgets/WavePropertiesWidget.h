/**
 * @file WavePropertiesWidget.h
 *
 * Kontrolka informacji o nagraniu - nagłówek.
 *
 * @author Zbigniew Siciarz
 * @date 2009-2010
 * @version 0.8.2
 * @since 0.2.1
 */

#ifndef WAVEPROPERTIESWIDGET_H
#define WAVEPROPERTIESWIDGET_H

#include "aquila/WaveFile.h"
#include <QTableWidget>

/**
 * Kontrolka prezentująca tabelę właściwości nagrania z pliku WAV.
 */
class WavePropertiesWidget : public QTableWidget
{
    Q_OBJECT

public:
    WavePropertiesWidget(QWidget* parent = 0);

    void setWaveFile(Aquila::WaveFile* wav);
};

#endif // WAVEPROPERTIESWIDGET_H
