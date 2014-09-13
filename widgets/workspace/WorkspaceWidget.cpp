/**
 * @file WorkspaceWidget.cpp
 *
 * Kontrolka zarządzania przestrzenią roboczą - implementacja.
 *
 * @author Zbigniew Siciarz
 * @date 2009-2010
 * @version 0.8.2
 * @since 0.4.0
 */

#include "WorkspaceWidget.h"

#include "ui_WorkspaceWidget.h"
#include <QDir>
#include <QFileDialog>
#include <QMessageBox>

/**
 * Tworzy kontrolkę przestrzeni roboczej.
 *
 * Tworzy model katalogu i wiąże go z widokiem drzewa, łączy sygnały przycisków
 * i widoku z odpowiednimi slotami.
 *
 * @param initialPath ścieżka do katalogu nadrzędnego przestrzeni roboczej
 * @param parent obiekt rodzica
 */
WorkspaceWidget::WorkspaceWidget(QString initialPath, QWidget *parent)
    : QWidget(parent), ui(new Ui::WorkspaceWidget)
{
    ui->setupUi(this);

    dirModel = new WorkspaceDirModel(this);
    dirModel->setReadOnly(false);
    dirModel->setSorting(QDir::Name | QDir::DirsFirst);
    ui->workspaceTreeView->setModel(dirModel);
    ui->workspaceTreeView->setRootIndex(dirModel->index(initialPath));
    ui->workspaceTreeView->hideColumn(1);
    ui->workspaceTreeView->hideColumn(2);
    ui->workspaceTreeView->hideColumn(3);
    ui->workspaceTreeView->selectionModel()->clearSelection();

    connect(ui->workspaceTreeView, SIGNAL(removeRequested()), SLOT(removeSelectedItems()));
    connect(ui->workspaceTreeView, SIGNAL(refreshRequested()), SLOT(refresh()));

    connect(ui->btnRefresh, SIGNAL(clicked()), SLOT(refresh()));
    connect(ui->btnAddDirectory, SIGNAL(clicked()), SLOT(addDirectory()));
    connect(ui->btnLoadFile, SIGNAL(clicked()), SLOT(loadCurrentItem()));
    connect(ui->btnRemoveFile, SIGNAL(clicked()), SLOT(removeSelectedItems()));

    connect(ui->workspaceTreeView, SIGNAL(doubleClicked(QModelIndex)), SLOT(loadItem(QModelIndex)));
}

/**
 * Usuwa obiekt interfejsu.
 */
WorkspaceWidget::~WorkspaceWidget()
{
    delete ui;
}

/**
 * Przypisuje filtry plików, z których ma korzystać model katalogu.
 *
 * @param filters lista filtrów
 */
void WorkspaceWidget::setFileFilters(const QStringList& filters)
{
    dirModel->setNameFilters(filters);
}

/**
 * Dodaje katalog do przestrzeni roboczej.
 */
void WorkspaceWidget::addDirectory()
{
    QString directoryName = QFileDialog::getExistingDirectory(this,
        tr("Choose folder"), getDirectory());

    if (!directoryName.isEmpty())
        setDirectory(directoryName);
}

/**
 * Ustawia katalog przestrzeni roboczej.
 *
 * @param directoryName ścieżka do katalogu
 */
void WorkspaceWidget::setDirectory(QString directoryName)
{
    ui->workspaceTreeView->setRootIndex(dirModel->index(directoryName));
    emit sendMessage(tr("Workspace directory set to: %1").arg(directoryName));
}

/**
 * Zwraca nazwę aktualnie ustawionego katalogu.
 */
QString WorkspaceWidget::getDirectory()
{
    return dirModel->fileInfo(ui->workspaceTreeView->rootIndex()).canonicalFilePath();
}

/**
 * Usuwa zaznaczone elementy widoku drzewa z modelu oraz z dysku.
 *
 * Po udanym usunięciu emituje sygnał fileRemoved(QString).
 */
void WorkspaceWidget::removeSelectedItems()
{
    QModelIndexList items = ui->workspaceTreeView->selectionModel()->selectedRows(0);
    int rowCount = items.size();
    if (0 == rowCount)
        return;

    QString msg;
    if (rowCount > 1)
        msg = tr("Are you sure you want to remove %1 files?").arg(rowCount);
    else
        msg = tr("Are you sure you want to remove 1 file?");
    if (QMessageBox::question(this, tr("Workspace"), msg,
        QMessageBox::Yes | QMessageBox::No, QMessageBox::No) == QMessageBox::No)
    {
        return;
    }

    foreach (QModelIndex index, items)
    {
        QModelIndex parent = index.parent();
        QString filename = dirModel->fileInfo(index).canonicalFilePath();
        bool ok;
        if (dirModel->fileInfo(index).isDir())
        {
            ok = dirModel->rmdir(index);
        }
        else
        {
            ok = dirModel->remove(index);
        }
        if (ok)
        {
            emit sendMessage(tr("Removing %1").arg(filename));
            emit fileRemoved(filename);
            dirModel->refresh(parent);
        }
        else
        {
            emit sendMessage(tr("Failed to remove %1").arg(filename));
        }
    }
}

/**
 * Odświeża model katalogu, aktualizując o ewentualne zmiany w systemie plików.
 */
void WorkspaceWidget::refresh()
{
    dirModel->refresh();
    emit sendMessage(tr("Workspace refreshed"));
}

/**
 * Wczytuje aktualnie zaznaczony element widoku katalogu.
 */
void WorkspaceWidget::loadCurrentItem()
{
    loadItem(ui->workspaceTreeView->currentIndex());
}

/**
 * Wczytuje element modelu katalogu o podanym indeksie.
 *
 * Jeśli dany element jest katalogiem, odpowiedni element widoku jest
 * rozwijany/zwijany zależnie od bieżącego stanu. Jeśli jest plikiem,
 * emitowany jest sygnał fileLoaded(QString), gdzie parametrem jest pełna
 * ścieżka do wczytanego pliku.
 *
 * @param index indeks danego elementu w modelu
 */
void WorkspaceWidget::loadItem(const QModelIndex& index)
{
    if (dirModel->fileInfo(index).isDir())
    {
        bool isExpanded = ui->workspaceTreeView->isExpanded(index);
        ui->workspaceTreeView->setExpanded(index, !isExpanded);
        return;
    }

    QString filename = dirModel->fileInfo(index).canonicalFilePath();
    emit sendMessage(tr("Loading file %1").arg(filename));
    emit fileLoaded(filename);
}
