/**
 * @file ExtractorPropertiesWidget.h
 *
 * Kontrolka informacji o obiekcie cech - nagłówek.
 *
 * @author Zbigniew Siciarz
 * @date 2009-2010
 * @version 0.8.2
 * @since 0.6.0
 */

#ifndef EXTRACTORPROPERTIESWIDGET_H
#define EXTRACTORPROPERTIESWIDGET_H

#include "aquila/feature/Extractor.h"
#include <QString>
#include <QTableWidget>

/**
 * Kontrolka prezentująca tabelę właściwości obiektu cech.
 */
class ExtractorPropertiesWidget : public QTableWidget
{
    Q_OBJECT

public:
    ExtractorPropertiesWidget(QWidget* parent = 0);

    void setExtractor(QString filename, Aquila::Extractor* extractor);
};

#endif // EXTRACTORPROPERTIESWIDGET_H
