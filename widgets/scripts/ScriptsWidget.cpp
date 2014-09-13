/**
 * @file ScriptsWidget.cpp
 *
 * Kontrolka zarządzająca skryptami - implementacja.
 *
 * @author Zbigniew Siciarz
 * @date 2009-2010
 * @version 0.8.2
 * @since 0.8.0
 */

#include "ScriptsWidget.h"

#include "ui_ScriptsWidget.h"
#include "ScriptIconProvider.h"
#include "script/prototypes/prototypes.h"
#include "script/TextEditConsole.h"
#include <QFile>
#include <QMessageBox>
#include <QScriptValue>
#include <QStringList>
#include <QTextStream>


/**
 * Tworzy obiekt kontrolki.
 *
 * @param parent obiekt rodzica
 */
ScriptsWidget::ScriptsWidget(QWidget *parent):
    QWidget(parent), ui(new Ui::ScriptsWidget), engine(0)
{
    ui->setupUi(this);

    menu = new QMenu(tr("Scripts"), this);
    menu->addAction(ui->actionRun);
    menu->addAction(ui->actionSave);
    
    connect(ui->actionSave, SIGNAL(triggered()), this, SLOT(saveCurrentScript()));
    ui->btnSave->setDefaultAction(ui->actionSave);
    connect(ui->actionRun, SIGNAL(triggered()), this, SLOT(runCurrentScript()));
    ui->btnRun->setDefaultAction(ui->actionRun);

    highlighter = new QtScriptHighligher(ui->editCode);

    connect(ui->listScripts, SIGNAL(doubleClicked(QModelIndex)),
            this, SLOT(scriptDoubleClicked(QModelIndex)));
    connect(ui->editCode, SIGNAL(textChanged()), this, SLOT(updateUi()));
}

/**
 * Usuwa obiekt interfejsu użytkownika.
 */
ScriptsWidget::~ScriptsWidget()
{
    delete ui;
}

/**
 * Przygotowuje listę skryptów w danym katalogu.
 *
 * @param directory katalog, w którym znajdują się skrypty
 */
void ScriptsWidget::loadScripts(QString directory)
{
    model = new QDirModel(QStringList() << "*.js", QDir::Files, QDir::Name);
    model->setIconProvider(new ScriptIconProvider());
    ui->listScripts->setModel(model);
    ui->listScripts->setRootIndex(model->index(directory));

    updateUi();
}

/**
 * Wczytuje skrypt do edytora.
 *
 * @param index indeks w modelu - wskazuje na kliknięty plik
 */
void ScriptsWidget::scriptDoubleClicked(QModelIndex index)
{
    if (!index.isValid())
        return;

    QString filename = model->fileInfo(index).canonicalFilePath();
    QFile file(filename);
    if (!file.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::warning(this, tr("SimpleBird"), tr("Cannot read file %1:\n%2.").
            arg(filename).arg(file.errorString()));
        return;
    }

    QTextStream in(&file);
    in.setCodec("UTF-8");
    currentScript = in.readAll();
    currentScriptFilename = filename;
    ui->editCode->setPlainText(currentScript);
    file.close();

    emit sendMessage(tr("Loaded file: %1").arg(filename));
    updateUi();
}

/**
 * Wykonuje bieżący skrypt.
 */
void ScriptsWidget::runCurrentScript()
{
    if (currentScript.isEmpty())
        return;

    delete engine;
    engine = new ScriptEngine(this);
    registerAllPrototypes(engine);
    engine->setConsole(new TextEditConsole(ui->console->getTextEdit(), this));
    ui->console->clear();

    engine->evaluate(currentScript);
    QScriptValue runFunction = engine->configure();
    QScriptValue returnValue = engine->run(runFunction);

    if (engine->hasUncaughtException())
    {
        QMessageBox messageBox(this);
        messageBox.setIcon(QMessageBox::Warning);
        messageBox.setWindowTitle(tr("Script error"));
        messageBox.setText(tr("An error occurred while executing the script."));
        messageBox.setInformativeText(engine->uncaughtException().toString());
        messageBox.setDetailedText(engine->uncaughtExceptionBacktrace().join("\n"));
        messageBox.exec();
    }

    QApplication::alert(this);
}

/**
 * Zapisuje bieżący skrypt.
 */
void ScriptsWidget::saveCurrentScript()
{
    QFile file(currentScriptFilename);
    if (!file.open(QFile::WriteOnly | QFile::Text))
    {
        QMessageBox::warning(this, tr("SimpleBird"), tr("Cannot write file %1:\n%2.").
            arg(currentScriptFilename).arg(file.errorString()));
        return;
    }

    currentScript = ui->editCode->toPlainText();

    QTextStream out(&file);
    out.setCodec("UTF-8");
    out << currentScript;

    file.close();

    emit sendMessage(tr("Saved file: %1").arg(currentScriptFilename));
    updateUi();
}

/**
 * Aktualizuje interfejs użytkownika zależnie od stanu kontrolki.
 */
void ScriptsWidget::updateUi()
{
    ui->actionRun->setEnabled(!currentScriptFilename.isEmpty());

    // jeśli zmienił się kod skryptu, to ustaw tę flagę
    bool isDirty = !currentScript.isEmpty() && (ui->editCode->toPlainText() != currentScript);
    ui->actionSave->setEnabled(isDirty);

    if (isDirty)
        ui->gbxCode->setTitle(tr("Source code (modified)"));
    else
        ui->gbxCode->setTitle(tr("Source code"));
}
