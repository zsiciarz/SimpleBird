/**
 * @file WorkspaceDirModel.cpp
 *
 * Model katalogu przestrzeni roboczej - implementacja.
 *
 * @author Zbigniew Siciarz
 * @date 2009-2010
 * @version 0.8.2
 * @since 0.4.0
 */

#include "WorkspaceDirModel.h"

/**
 * Tworzy model katalogu przestrzeni roboczej.
 *
 * @param parent obiekt rodzica
 */
WorkspaceDirModel::WorkspaceDirModel(QObject* parent):
    QDirModel(parent)
{
}

/**
 * Zwraca dane odpowiadające konkretnemu indeksowi i roli.
 *
 * Metoda nadpisana z klasy nadrzędnej w celu umożliwienia kolorowania
 * nazw plików w zależności od ich rozszerzeń. Mapowanie kolorów jest
 * przypisane za pomocą metody setColorMap(). Katalogi nie są kolorowane,
 * natomiast pliki o rozszerzeniach nie zarejestrowanych w mapowaniu
 * są kolorowane na szaro.
 *
 * @param index indeks elementu modelu
 * @param role rola danych
 * @return dane odpowiadające indeksowi i roli
 */
QVariant WorkspaceDirModel::data(const QModelIndex& index, int role) const
{
    if (Qt::ForegroundRole == role && fileInfo(index).isFile())
    {
        QString extension = fileInfo(index).suffix();
        return colorMap.value(extension.toUpper(), QColor(Qt::gray));
    }
    else
    {
        return QDirModel::data(index, role);
    }
}
