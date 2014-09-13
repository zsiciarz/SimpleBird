/**
 * @file WorkspaceWidget.h
 *
 * Kontrolka zarządzania przestrzenią roboczą - nagłówek.
 *
 * @author Zbigniew Siciarz
 * @date 2009-2010
 * @version 0.8.2
 * @since 0.4.0
 */

#ifndef WORKSPACEWIDGET_H
#define WORKSPACEWIDGET_H

#include "WorkspaceDirModel.h"
#include <QColor>
#include <QMap>
#include <QModelIndex>
#include <QString>
#include <QStringList>
#include <QWidget>

namespace Ui
{
    class WorkspaceWidget;
}

/**
 * Kontrolka zarządzająca przestrzenią roboczą.
 *
 * Przez "przestrzeń roboczą" rozumiemy katalog w systemie plików. Kontrolka
 * zawiera widok drzewa podkatalogów, oraz przyciski umożliwiające dodawanie
 * i usuwanie plików z przestrzeni roboczej.
 */
class WorkspaceWidget : public QWidget
{
    Q_OBJECT

public:
    WorkspaceWidget(QString initialPath, QWidget *parent = 0);
    ~WorkspaceWidget();

    /**
     * Przypisuje mapowanie kolorów odpowiadających typom plików.
     *
     * Argumentem jest odwzorowanie postaci rozszerzenie -> kolor, gdzie
     * rozszerzenie nie zawiera kropki i jest pisane wielkimi literami.
     *
     * @param map odwzorowanie rozszerzeń na kolory
     */
    void setColorMap(QMap<QString, QColor> map) { dirModel->setColorMap(map); }

public slots:
    void setFileFilters(const QStringList& filters);
    void addDirectory();
    void setDirectory(QString directoryName);
    QString getDirectory();
    void removeSelectedItems();
    void refresh();

signals:
    /**
     * Sygnał emitowany w momencie załadowania pliku z przestrzeni roboczej.
     *
     * @param filename pełna ścieżka pliku
     */
    void fileLoaded(QString filename);

    /**
     * Sygnał emitowany gdy kontrolka przestrzeni roboczej wysyła wiadomość na zewnątrz.
     *
     * @param message wiadomość
     */
    void sendMessage(QString message);

    /**
     * Sygnał emitowany w momencie usunięcia pliku z przestrzeni roboczej.
     *
     * @param filename pełna ścieżka pliku
     */
    void fileRemoved(QString filename);

private slots:
    void loadCurrentItem();
    void loadItem(const QModelIndex& index);

private:
    /**
     * Klasa interfejsu wygenerowana przez Designera.
     */
    Ui::WorkspaceWidget *ui;

    /**
     * Model katalogu przestrzeni roboczej.
     */
    WorkspaceDirModel* dirModel;
};

#endif // WORKSPACEWIDGET_H
