/**
 * @file WorkspaceDirModel.h
 *
 * Model katalogu przestrzeni roboczej - nagłówek.
 *
 * @author Zbigniew Siciarz
 * @date 2009-2010
 * @version 0.8.2
 * @since 0.4.0
 */

#ifndef WORKSPACEDIRMODEL_H
#define WORKSPACEDIRMODEL_H

#include <QColor>
#include <QDirModel>
#include <QMap>
#include <QString>

/**
 * Model katalogu przestrzeni roboczej.
 */
class WorkspaceDirModel : public QDirModel
{
    Q_OBJECT

public:
    WorkspaceDirModel(QObject* parent = 0);

    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const;

    /**
     * Przypisuje mapowanie kolorów odpowiadających typom plików.
     *
     * Argumentem jest odwzorowanie postaci rozszerzenie -> kolor, gdzie
     * rozszerzenie nie zawiera kropki i jest pisane wielkimi literami.
     *
     * @param map odwzorowanie rozszerzeń na kolory
     */
    void setColorMap(QMap<QString, QColor> map) { colorMap = map; }

private:
    /**
     * Mapowanie kolorów odpowiadających typom plików.
     */
    QMap<QString, QColor> colorMap;
};

#endif // WORKSPACEDIRMODEL_H
