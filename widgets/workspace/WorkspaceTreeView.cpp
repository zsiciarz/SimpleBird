/**
 * @file WorkspaceTreeView.cpp
 *
 * Widok drzewa katalogu przestrzeni roboczej - implementacja.
 *
 * @author Zbigniew Siciarz
 * @date 2009-2010
 * @version 0.8.2
 * @since 0.4.0
 */

#include "WorkspaceTreeView.h"

#include <QDirModel>
#include <QIcon>
#include <QMenu>

/**
 * Tworzy obiekt widoku drzewa katalogu.
 *
 * Tworzy akcje widoku, które będą przypisane do menu kontekstowego.
 *
 * @param parent obiekt rodzica
 */
WorkspaceTreeView::WorkspaceTreeView( QWidget* parent):
    QTreeView(parent)
{
    actionExpandOrCollapse = new QAction(tr("Expand"), this);
    connect(actionExpandOrCollapse, SIGNAL(triggered()), SLOT(expandOrCollapse()));

    actionLoad = new QAction(QIcon(":/icons/page_next.png"),
        tr("Load selected file"), this);
    connect(actionLoad, SIGNAL(triggered()), SLOT(load()));

    actionRemove = new QAction(QIcon(":/icons/page_remove.png"),
        tr("Remove selected"), this);
    connect(actionRemove, SIGNAL(triggered()), this, SIGNAL(removeRequested()));

    actionRefresh = new QAction(QIcon(":/icons/repeat.png"),
        tr("Refresh view"), this);
    connect(actionRefresh, SIGNAL(triggered()), this, SIGNAL(refreshRequested()));
}

/**
 * Przechwytuje zdarzenie naciśnięcia klawisza.
 *
 * Reaguje na naciśnięcie klawiszy Delete i Enter, odpowiednio żądając
 * usunięcia albo załadowania aktualnie zaznaczonego elementu.
 *
 * @param event obiekt informacji o zdarzeniu
 */
void WorkspaceTreeView::keyPressEvent(QKeyEvent* event)
{
    if (event->key() == Qt::Key_Delete)
    {
        emit removeRequested();
    }
    else if (event->key() == Qt::Key_Return)
    {
        emit doubleClicked(currentIndex());
    }

    QTreeView::keyPressEvent(event);
}

/**
 * Przechwytuje zdarzenie wywołania menu kontekstowego.
 *
 * Wyświetla menu kontekstowe z akcjami widoku. Jeśli bieżący element jest
 * katalogiem, pierwsza z akcji menu służy do zwinięcia/rozwinięcia gałęzi
 * drzewa. Jeśli bieżący element jest plikiem, pierwsza akcja wczytuje
 * plik z przestrzeni roboczej.
 *
 * @param event obiekt informacji o zdarzeniu
 */
void WorkspaceTreeView::contextMenuEvent(QContextMenuEvent* event)
{
    QMenu menu(this);

    QDirModel* dirModel = static_cast<QDirModel*>(model());
    if (dirModel->fileInfo(currentIndex()).isDir())
    {
        bool exp = isExpanded(currentIndex());
        actionExpandOrCollapse->setText(exp ? tr("Collapse") : tr("Expand"));
        menu.addAction(actionExpandOrCollapse);
    }
    else
    {
        menu.addAction(actionLoad);
    }

    menu.addAction(actionRemove);
    menu.addSeparator();
    menu.addAction(actionRefresh);
    menu.exec(event->globalPos());
}

/**
 * Slot akcji zwijającej/rozwijającej gałąź podkatalogu.
 */
void WorkspaceTreeView::expandOrCollapse()
{
    setExpanded(currentIndex(), !isExpanded(currentIndex()));
}

/**
 * Slot akcji wczytującej aktualnie zaznaczony plik.
 */
void WorkspaceTreeView::load()
{
    emit doubleClicked(currentIndex());
}
