/**
 * @file simplebird.h
 * Plik zawierający definicję głównego okna aplikacji.
 *
 * @author Zbigniew Siciarz
 * @date 2008-2010
 * @version 0.8.2
 * @since 0.1.0
 */

#ifndef SIMPLEBIRD_H
#define SIMPLEBIRD_H

#include "ui_simplebird.h"
#include "widgets/charts/ChartsWidget.h"
#include "widgets/files/FilesWidget.h"
#include "widgets/scripts/ScriptsWidget.h"
#include "widgets/workspace/WorkspaceWidget.h"
#include "DictionaryDialog.h"
#include <QMainWindow>
#include <QCloseEvent>
#include <QComboBox>
#include <QProgressBar>
#include <QPushButton>
#include <QString>
#include <QStringList>

/**
 * Główne okno aplikacji.
 */
class SimpleBird : public QMainWindow
{
    Q_OBJECT

public:
    SimpleBird(QWidget *parent = 0);
    ~SimpleBird();

protected:
    void closeEvent(QCloseEvent* event);

private:
    void createActions();
    void createMenus();
    void createToolbar();
    void createWorkspace();
    void createFilesWidget();
    void createCharts();
    void createScripts();
    void readSettings();
    void writeSettings();
    void loadStylesheet(QString filename);

private slots:
    void updateUi();
    void toggleToolbar(bool visible);

    void goToWorkspace();
    void goToCharts();
    void openFile();
    void loadFile(const QString& filename);

    void test();
    void benchmark();
    void showSpectrogram();
    void showFeatureChart();
    void calculateFeature(QString featureType = "MFCC");
    void calculateFeatureFromToolbar();
    void recognizeCurrentFile();
    void showDictionary();
    void showPreferences();
    void showChangelog();
    void about();

private:
    /**
     * Klasa interfejsu wygenerowana przez Qt Designera.
     */
    Ui::SimpleBirdClass ui;

    /**
     * Obsługiwane formaty plików.
     */
    QStringList supportedFileFormats;

    /**
     * Filtry dla okienka zapisu/odczytu.
     */
    QString supportedFileFilters;
    
    /**
     * Bieżący katalog wyświetlany w przestrzeni roboczej.
     */
    QString initialDirectory;

    /**
     * Kontrolka przestrzeni roboczej.
     */
    WorkspaceWidget* workspaceWidget;

    /**
     * Kontrolka aktualnie załadowanych plików.
     */
    FilesWidget* filesWidget;

    /**
     * Kontrolka zarządzania wykresami.
     */
    ChartsWidget* chartsWidget;

    /**
     * Kontrolka zarządzania skryptami.
     */
    ScriptsWidget* scriptsWidget;

    /**
     * Pasek postępu na pasku stanu.
     */
    QProgressBar* progressBar;

    /**
     * Wybór typu cech.
     */
    QComboBox* cbxFeatureType;

    /**
     * Przycisk wywołujący obliczanie cech zależnie od wyboru w comboboksie.
     */
    QPushButton* btnCalculate;

    /**
     * Okienko obsługi słownika.
     */
    DictionaryDialog* dictionaryDlg;
};


#endif // SIMPLEBIRD_H
