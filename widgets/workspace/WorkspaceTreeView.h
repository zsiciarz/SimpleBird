/**
 * @file WorkspaceTreeView.h
 *
 * Widok drzewa katalogu przestrzeni roboczej - nagłówek.
 *
 * @author Zbigniew Siciarz
 * @date 2009-2010
 * @version 0.8.2
 * @since 0.4.0
 */

#ifndef WORKSPACETREEVIEW_H
#define WORKSPACETREEVIEW_H

#include <QAction>
#include <QContextMenuEvent>
#include <QKeyEvent>
#include <QTreeView>

/**
 * Klasa widoku drzewa katalogu przestrzeni roboczej.
 *
 * Zapewnia integrację z modelem katalogu, udostępnia menu kontekstowe.
 */
class WorkspaceTreeView : public QTreeView
{
    Q_OBJECT

public:
    WorkspaceTreeView(QWidget* parent = 0);

signals:
    /**
     * Sygnał emitowany po wybraniu polecenia "Usuń" z menu kontekstowego.
     */
    void removeRequested();

    /**
     * Sygnał emitowany po wybraniu polecenia "Odśwież" z menu kontekstowego.
     */
    void refreshRequested();

protected:
    void keyPressEvent(QKeyEvent* event);
    void contextMenuEvent(QContextMenuEvent* event);

private slots:
    void expandOrCollapse();
    void load();

private:
    /**
     * Akcja zwijająca bądź rozwijająca gałąź podkatalogu.
     */
    QAction* actionExpandOrCollapse;

    /**
     * Akcja wczytująca plik z przestrzeni roboczej.
     */
    QAction* actionLoad;

    /**
     * Akcja usuwająca plik z przestrzeni roboczej.
     */
    QAction* actionRemove;

    /**
     * Akcja odświeżająca widok przestrzeni roboczej.
     */
    QAction* actionRefresh;
};

#endif // WORKSPACETREEVIEW_H
