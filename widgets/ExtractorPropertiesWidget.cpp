/**
 * @file ExtractorPropertiesWidget.cpp
 *
 * Kontrolka informacji o obiekcie cech - implementacja.
 *
 * @author Zbigniew Siciarz
 * @date 2009-2010
 * @version 0.8.2
 * @since 0.6.0
 */

#include "ExtractorPropertiesWidget.h"

#include <QDateTime>
#include <QFileInfo>
#include <QHeaderView>
#include <QMessageBox>
#include <QStringList>


/**
 * Tworzy kontrolkę i inicjalizuje tabelę.
 *
 * @param parent obiekt rodzica
 */
ExtractorPropertiesWidget::ExtractorPropertiesWidget(QWidget* parent):
    QTableWidget(8, 1, parent)
{
    // row labels
    QStringList labels;
    labels << tr("Filename") << tr("Full path") << tr("Original wave filename") <<
            tr("Type") << tr("Frame length") << tr("Frames count") <<
            tr("Params per frame") << tr("Calculated at");
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
 * Ustawia obiekt ekstraktora cech i wyświetla jego właściwości w tabeli.
 *
 * @param filename nazwa pliku ekstraktora
 * @param extractor wskaźnik do obiektu ekstraktora
 */
void ExtractorPropertiesWidget::setExtractor(QString filename, Aquila::Extractor* extractor)
{
    QFileInfo fi(filename);
    setItem(0, 0, new QTableWidgetItem(fi.fileName()));
    setItem(1, 0, new QTableWidgetItem(filename));
    setItem(2, 0, new QTableWidgetItem(QString::fromStdString(extractor->getWaveFilename())));
    setItem(3, 0, new QTableWidgetItem(QString::fromStdString(extractor->getType())));
    setItem(4, 0, new QTableWidgetItem(tr("%1 ms").arg(extractor->getFrameLength())));
    setItem(5, 0, new QTableWidgetItem(tr("%1 frames").arg(extractor->getFramesCount())));
    setItem(6, 0, new QTableWidgetItem(tr("%1 params").arg(extractor->getParamsPerFrame())));
    setItem(7, 0, new QTableWidgetItem(QDateTime::fromTime_t(extractor->getTimestamp()).toString()));

    setEnabled(true);
}
