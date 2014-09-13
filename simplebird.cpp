/**
 * @file simplebird.cpp
 * Plik zawierający definicję głównego okna aplikacji.
 *
 * @author Zbigniew Siciarz
 * @date 2008-2010
 * @version 0.8.2
 * @since 0.1.0
 */

#include "simplebird.h"

#include "aquila/global.h"
#include "aquila/Exceptions.h"
#include "aquila/Transform.h"
#include "aquila/dtw/Dtw.h"
#include "aquila/feature/ExtractorFactory.h"
#include "formats/FormatFactory.h"
#include "recognizing/Dictionary.h"
#include "recognizing/DtwRecognizer.h"
#include "Benchmark.h"
#include "ChangelogDialog.h"
#include "PreferencesDialog.h"
#include "ProgressBarIndicator.h"
#include "SimpleBirdApplication.h"
#include "SimpleBirdSettings.h"
#include <qwt_global.h>
#include <QtCore>
#include <QtGui>

/**
 * Tworzy okno główne.
 *
 * @param parent obiekt rodzica
 */
SimpleBird::SimpleBird(QWidget *parent)
    : QMainWindow(parent), dictionaryDlg(0)
{
    ui.setupUi(this);

    connect(ui.consoleWidget, SIGNAL(messageLogged(QString, int)),
            statusBar(), SLOT(showMessage(QString, int)));

    ui.consoleWidget->logMessage(tr("Starting up..."));
    setWindowTitle(qApp->applicationName() + " " + qApp->applicationVersion());
    createActions();
    createMenus();
    createToolbar();

    setCentralWidget(ui.tabWidget);
    ui.tabWidget->setCurrentWidget(ui.tabWorkspace);

    ui.consoleWidget->logMessage(tr("Reading settings..."));
    readSettings();

    createWorkspace();
    createFilesWidget();
    createCharts();
    createScripts();

    progressBar = new QProgressBar(this);
    statusBar()->addPermanentWidget(progressBar);
    progressBar->hide();

    statusBar()->showMessage(tr("Ready"), 3000);
    ui.consoleWidget->logMessage(tr("%1 %2 using Aquila %4: Ready").
               arg(qApp->applicationName()).
               arg(qApp->applicationVersion()).
               arg(Aquila::VERSION.c_str()));

    supportedFileFormats << "WAV" << FormatFactory::getFeatureFormats();
    supportedFileFilters = tr("Wave files (*.wav);;%1").
        arg(FormatFactory::getFeatureFormatsFilter());

    updateUi();
}

/**
 * Usuwa obiekt nagrania przed zniszczeniem okna.
 */
SimpleBird::~SimpleBird()
{
}

/**
 * Zdarzenie zamykania okna.
 *
 * Przesłania metodę zdefiniowaną w klasie QWidget. Przed zamknięciem okna
 * (co w przypadku okna głównego jest równoznaczne z zamknięciem programu)
 * zapisuje ustawienia aplikacji.
 *
 * @param event obiekt informacji o zdarzeniu zamykania okna
 */
void SimpleBird::closeEvent(QCloseEvent* event)
{
    writeSettings();
    event->accept();
}

/**
 * Tworzy akcje aplikacji.
 *
 * Uzupełnia kod automatycznie wygenerowany przez Qt Designera o wskazówki
 * wyświetlane na pasku stanu i skróty klawiszowe oraz łączy sygnały
 * wyzwolenia akcji z odpowiednimi slotami klasy okna.
 */
void SimpleBird::createActions()
{
    ui.actionOpen->setStatusTip(tr("Open a .wav file"));
    ui.actionOpen->setShortcut(tr("Ctrl+O"));
    connect(ui.actionOpen, SIGNAL(triggered()), this, SLOT(openFile()));

    ui.actionExit->setStatusTip(tr("Exit %1").arg(qApp->applicationName()));
    connect(ui.actionExit, SIGNAL(triggered()), this, SLOT(close()));

    ui.actionTest->setStatusTip(tr("Test"));
    ui.actionTest->setShortcut(tr("Ctrl+T"));
    connect(ui.actionTest, SIGNAL(triggered()), this, SLOT(benchmark()));

    ui.actionSpectrogram->setStatusTip(tr("Show spectrogram"));
    ui.actionSpectrogram->setShortcut(tr("Ctrl+Alt+S"));
    connect(ui.actionSpectrogram, SIGNAL(triggered()),
            this, SLOT(showSpectrogram()));

    ui.actionFeatureChart->setStatusTip(tr("Show feature chart"));
    connect(ui.actionFeatureChart, SIGNAL(triggered()),
            this, SLOT(showFeatureChart()));

    ui.actionCalculateEnergy->setStatusTip(tr("Calculate signal's logarithmic energy"));
    ui.actionCalculatePower->setStatusTip(tr("Calculate signal's power"));
    ui.actionCalculateMFCC->setStatusTip(tr("Calculate MFCC parameters"));

    ui.actionRecognizeCurrentFile->setStatusTip(tr("Recognize currently loaded wave file"));
    connect(ui.actionRecognizeCurrentFile, SIGNAL(triggered()), SLOT(recognizeCurrentFile()));

    ui.actionChangelog->setStatusTip(tr("Version changelog"));
    connect(ui.actionChangelog, SIGNAL(triggered()),
            this, SLOT(showChangelog()));

    ui.actionDictionary->setStatusTip(tr("Show dictionary view"));
    connect(ui.actionDictionary, SIGNAL(triggered()),
            this, SLOT(showDictionary()));

    ui.actionPreferences->setStatusTip(tr("Program settings"));
    connect(ui.actionPreferences, SIGNAL(triggered()),
            this, SLOT(showPreferences()));

    ui.actionAbout->setStatusTip(tr("Show information about the program"));
    ui.actionAbout->setShortcut(tr("F1"));
    connect(ui.actionAbout, SIGNAL(triggered()), this, SLOT(about()));

    ui.actionAboutQt->setStatusTip(tr("Show information about the Qt library"));
    connect(ui.actionAboutQt, SIGNAL(triggered()), qApp, SLOT(aboutQt()));

    // connecting "calculate" actions
    // TODO - move this to a more generic function
    QSignalMapper* signalMapper = new QSignalMapper(this);
    connect(ui.actionCalculateEnergy, SIGNAL(triggered()), signalMapper, SLOT(map()));
    signalMapper->setMapping(ui.actionCalculateEnergy, "Energy");
    connect(ui.actionCalculatePower, SIGNAL(triggered()), signalMapper, SLOT(map()));
    signalMapper->setMapping(ui.actionCalculatePower, "Power");
    connect(ui.actionCalculateMFCC, SIGNAL(triggered()), signalMapper, SLOT(map()));
    signalMapper->setMapping(ui.actionCalculateMFCC, "MFCC");
    connect(ui.actionCalculateHFCC, SIGNAL(triggered()), signalMapper, SLOT(map()));
    signalMapper->setMapping(ui.actionCalculateHFCC, "HFCC");
    connect(signalMapper, SIGNAL(mapped(QString)), this, SLOT(calculateFeature(QString)));
}

/**
 * Tworzy te części menu, których nie da się wyklikać w Qt Designerze.
 *
 * W przypadku menu pasków narzędzi: znajduje wszystkie paski narzędzi
 * i dla każdego z nich tworzy dwustanową akcję pokaż/ukryj pasek.
 */
void SimpleBird::createMenus()
{
    // menu pasków narzędzi
    QList<QToolBar*> toolbars = findChildren<QToolBar*>();
    QMenu* toolbarsMenu = new QMenu(this);
    foreach (QToolBar* toolbar, toolbars)
    {
        QAction* tbAction = new QAction(toolbar->windowTitle(), this);
        tbAction->setCheckable(true);
        // przechowujemy nazwę obiektu paska narzędzi
        tbAction->setData(toolbar->objectName());
        connect(tbAction, SIGNAL(toggled(bool)), this,
                SLOT(toggleToolbar(bool)));
        toolbarsMenu->addAction(tbAction);
        tbAction->setChecked(toolbar->isVisible());
    }
    ui.actionToolbars->setMenu(toolbarsMenu);
}

/**
 * Updates the toolbar with some custom actions and widgets which cannot be
 * set in Designer.
 */
void SimpleBird::createToolbar()
{
    QLabel* label = new QLabel(tr("Feature type: "), ui.toolBar);
    QAction* lblAction = ui.toolBar->insertWidget(ui.actionSpectrogram, label);
    ui.toolBar->insertSeparator(lblAction);

    cbxFeatureType = new QComboBox(ui.toolBar);

    // keep original names in "user data" of each item
    QStringList translated = QStringList() << tr("Energy") << tr("Power") << tr("MFCC") << tr("HFCC");
    QStringList untranslated = QStringList() << "Energy" << "Power" << "MFCC" << "HFCC";
    for (int i = 0; i < translated.size(); ++i)
        cbxFeatureType->addItem(translated[i], untranslated[i]);

    cbxFeatureType->setEnabled(false);
    ui.toolBar->insertWidget(ui.actionSpectrogram, cbxFeatureType);

    btnCalculate = new QPushButton(QIcon(":/icons/next.png"), tr("Calculate"), ui.toolBar);
    btnCalculate->setEnabled(false);
    ui.toolBar->insertWidget(ui.actionSpectrogram, btnCalculate);
    connect(btnCalculate, SIGNAL(clicked()), this, SLOT(calculateFeatureFromToolbar()));
    ui.toolBar->insertSeparator(ui.actionSpectrogram);
}

/**
 * Slot akcji przełączającej widoczność paska narzędzi.
 *
 * Rzutuje nadawcę na QAction, jeśli to się uda, próbuje znaleźć
 * pasek narzędzi o nazwie obiektu takiej jak dane przekazane do akcji,
 * a następnie przełącza widoczność paska.
 *
 * @param visible pokazać czy ukryć pasek narzędzi
 */
void SimpleBird::toggleToolbar(bool visible)
{
    QAction* action = qobject_cast<QAction*>(sender());
    if (action)
    {
        QToolBar* toolbar = findChild<QToolBar*>(action->data().toString());
        if (toolbar)
            toolbar->setVisible(visible);
    }
}

/**
 * Tworzy kontrolkę zarządzającą obszarem roboczym.
 */
void SimpleBird::createWorkspace()
{
    ui.consoleWidget->logMessage(tr("Preparing workspace..."));
    workspaceWidget = new WorkspaceWidget(initialDirectory, this);
    QMap<QString, QColor> colorMap;
    colorMap["WAV"] = Qt::blue;
    colorMap["BIR"] = Qt::darkYellow;
    colorMap["XML"] = Qt::darkGreen;
    workspaceWidget->setColorMap(colorMap);

    connect(workspaceWidget, SIGNAL(sendMessage(QString)),
            ui.consoleWidget, SLOT(logMessage(QString)));
    connect(workspaceWidget, SIGNAL(fileLoaded(QString)), SLOT(loadFile(QString)));
    connect(ui.actionChangeWorkspace, SIGNAL(triggered()), workspaceWidget, SLOT(addDirectory()));

    QGridLayout* workspaceLayout = new QGridLayout();
    workspaceLayout->addWidget(workspaceWidget, 0, 0);
    ui.tabWorkspace->setLayout(workspaceLayout);
}

/**
 * Tworzy kontrolkę zarządzania wczytanymi plikami.
 */
void SimpleBird::createFilesWidget()
{
    filesWidget = new FilesWidget(this);
    connect(filesWidget, SIGNAL(sendMessage(QString)),
            ui.consoleWidget, SLOT(logMessage(QString)));
    connect(filesWidget, SIGNAL(chartRequested()), SLOT(goToCharts()));
    connect(filesWidget, SIGNAL(featureCalculationRequested()), SLOT(showFeatureChart()));
    connect(filesWidget, SIGNAL(fileChanged(QString, FileType)), SLOT(updateUi()));

    QGridLayout* filesLayout = new QGridLayout();
    filesLayout->addWidget(filesWidget, 0, 0);
    ui.tabFiles->setLayout(filesLayout);
}

/**
 * Tworzy kontrolkę zarządzającą wykresami.
 */
void SimpleBird::createCharts()
{
    ui.consoleWidget->logMessage(tr("Preparing charts..."));
    chartsWidget = new ChartsWidget(this);
    menuBar()->insertMenu(ui.menuTools->menuAction(), chartsWidget->getMenu());

    connect(chartsWidget, SIGNAL(sendMessage(QString)),
            ui.consoleWidget, SLOT(logMessage(QString)));
    connect(chartsWidget, SIGNAL(goToWorkspaceRequested()), SLOT(goToWorkspace()));

    connect(filesWidget, SIGNAL(waveformRequested(Aquila::WaveFile*)),
        chartsWidget, SLOT(drawWaveform(Aquila::WaveFile*)));
    connect(filesWidget, SIGNAL(spectrogramRequested(Aquila::WaveFile*)),
        chartsWidget, SLOT(drawSpectrogram(Aquila::WaveFile*)));
    connect(filesWidget, SIGNAL(featureChartRequested(Aquila::Extractor*)),
        chartsWidget, SLOT(drawFeatureChart(Aquila::Extractor*)));
    connect(filesWidget, SIGNAL(dtwChartRequested(Aquila::Extractor*)),
        chartsWidget, SLOT(drawDtwChart(Aquila::Extractor*)));

    QGridLayout* chartsLayout = new QGridLayout();
    chartsLayout->addWidget(chartsWidget, 0, 0);
    ui.tabCharts->setLayout(chartsLayout);
}

/**
 * Tworzy kontrolkę zarządzania skryptami.
 */
void SimpleBird::createScripts()
{
    ui.consoleWidget->logMessage(tr("Preparing scripts..."));
    scriptsWidget = new ScriptsWidget(this);
    menuBar()->insertMenu(ui.menuHelp->menuAction(), scriptsWidget->getMenu());

    connect(scriptsWidget, SIGNAL(sendMessage(QString)),
            ui.consoleWidget, SLOT(logMessage(QString)));

    QGridLayout* scriptsLayout = new QGridLayout();
    scriptsLayout->addWidget(scriptsWidget, 0, 0);
    ui.tabScripts->setLayout(scriptsLayout);

    scriptsWidget->loadScripts(SimpleBirdApplication::directoryOf("scripts"));
}

/**
 * Odczytuje ustawienia aplikacji.
 *
 * Metodę tę wywołuje się w konstruktorze głównego okna po utworzeniu wszystkiego
 * co związane z GUI. Jej zadaniem jest przywrócenie wymiarów i położenia okna,
 * stanu pasków narzędzi i doków itp...
 */
void SimpleBird::readSettings()
{
    SimpleBirdSettings settings;
    restoreGeometry(settings.value("geometry").toByteArray());
    restoreState(settings.value("state").toByteArray());

    // przy starcie programu ustawiamy domyślną zakładkę ustawień
    settings.setValue("general/lastPrefsPage", 0);

    initialDirectory = settings.value("general/initialDirectory").toString();

    if (settings.useStylesheet())
        loadStylesheet(settings.getStylesheet());
}

/**
 * Zapisuje ustawienia programu.
 *
 * Zapisuje informacje o położeniu i wymiarach okna, stanie pasków narzędzi,
 * doków itp...
 */
void SimpleBird::writeSettings()
{
    SimpleBirdSettings settings;
    settings.setValue("geometry", saveGeometry());
    settings.setValue("state", saveState());
    settings.setValue("general/initialDirectory", workspaceWidget->getDirectory());
}

/**
 * Próbuje wczytać i ustawić dany arkusz stylu.
 *
 * @param filename nazwa arkusza stylów, a właściwie część ścieżki do arkusza
 */
void SimpleBird::loadStylesheet(QString filename)
{
    filename = ":/styles/" + filename + "/style.css";
    QFile file(filename);
    if (!file.open(QFile::ReadOnly | QFile::Text))
    {
        ui.consoleWidget->logWarning(tr("Cannot read file %1:\n%2.").arg(filename).arg(file.errorString()));
        return;
    }

     QTextStream in(&file);
     in.setCodec("UTF-8");
     qApp->setStyleSheet(in.readAll());
}

/**
 * Aktualizuje interfejs użytkownika po zmianie stanu (np. wczytanie pliku).
 */
void SimpleBird::updateUi()
{
    if (filesWidget->currentFileType() == FilesWidget::Wave)
    {
        ui.actionSpectrogram->setEnabled(true);
        ui.actionFeatureChart->setEnabled(true);
        ui.actionRecognizeCurrentFile->setEnabled(true);
        ui.menu_Visualisations->setEnabled(true);
        ui.menu_Calculate->setEnabled(true);
        cbxFeatureType->setEnabled(true);
        btnCalculate->setEnabled(true);
        ui.tblWaveProperties->show();
        ui.tblWaveProperties->setWaveFile(filesWidget->currentWaveFile());
        ui.tblExtractorProperties->hide();
    }
    else if (filesWidget->currentFileType() == FilesWidget::Feature)
    {
        ui.actionSpectrogram->setEnabled(false);
        ui.actionFeatureChart->setEnabled(true);
        ui.actionRecognizeCurrentFile->setEnabled(false);
        ui.menu_Visualisations->setEnabled(true);
        ui.menu_Calculate->setEnabled(false);
        cbxFeatureType->setEnabled(false);
        btnCalculate->setEnabled(false);
        ui.tblWaveProperties->hide();
        ui.tblExtractorProperties->show();
        ui.tblExtractorProperties->setExtractor(filesWidget->currentFile(),
            filesWidget->currentExtractor());
    }
    else
    {
        ui.actionSpectrogram->setEnabled(false);
        ui.actionFeatureChart->setEnabled(false);
        ui.actionRecognizeCurrentFile->setEnabled(false);
        ui.menu_Visualisations->setEnabled(false);
        ui.menu_Calculate->setEnabled(false);
        cbxFeatureType->setEnabled(false);
        btnCalculate->setEnabled(false);
        ui.tblWaveProperties->hide();
        ui.tblExtractorProperties->hide();
    }
}

/**
 * Przechodzi do przestrzeni roboczej.
 */
void SimpleBird::goToWorkspace()
{
    ui.tabWidget->setCurrentWidget(ui.tabWorkspace);
}

/**
 * Przechodzi do wykresów.
 */
void SimpleBird::goToCharts()
{
    ui.tabWidget->setCurrentWidget(ui.tabCharts);
}

/**
 * Slot akcji otwierania pliku.
 */
void SimpleBird::openFile()
{
    QString file = QFileDialog::getOpenFileName(this, tr("Select file"),
            "L:\\ptaki\\", supportedFileFilters);
    if (file.isEmpty())
        return;

    loadFile(file);
}

/**
 * Wczytuje dowolny plik obsługiwany przez program.
 *
 * @param filename nazwa pliku
 */
void SimpleBird::loadFile(const QString& filename)
{
    QFileInfo info(filename);
    if (!info.exists())
    {
        ui.consoleWidget->logWarning(tr("File %1 does not exist!").arg(filename));
        return;
    }
    QString extension = info.suffix().toUpper();
    if (!supportedFileFormats.contains(extension))
    {
        ui.consoleWidget->logWarning(tr("Unsupported file type: %1 (file: %2, supported formats: %3)").
            arg(extension).arg(filename).arg(supportedFileFormats.join(", ")));
        return;
    }

    if (filesWidget->hasFile(filename))
    {
        ui.consoleWidget->logWarning(tr("File %1 is already loaded").arg(filename));
        return;
    }
    filesWidget->addFile(filename);
    ui.tabWidget->setCurrentWidget(ui.tabFiles);
}

/**
 * Slot akcji testowej.
 */
void SimpleBird::test()
{
    QString dbfile = SimpleBirdApplication::directoryOf("data") + "/dictionary.db";
    Dictionary* dict = new Dictionary(dbfile, this);

    QString dir = QFileDialog::getExistingDirectory(this, tr("Choose directory"),
                                                    workspaceWidget->getDirectory());
    if (dir.isEmpty())
        return;

    bool ok;
    QString expectedLabel = QInputDialog::getItem(this, tr("Expected label"),
        tr("Expected label:"), dict->labels(), 0, false, &ok);
    if (!ok || expectedLabel.isEmpty())
        return;

    ui.consoleWidget->logMessage(tr("Starting batch recognizing"), Qt::darkGreen);
    QDateTime start = QDateTime::currentDateTime();
    ui.consoleWidget->logMessage(tr("Started at %1").arg(start.toString()));
    ui.consoleWidget->logMessage(tr("Directory: %1, expected label: %2").arg(dir).arg(expectedLabel));
    QFileInfoList files = QDir(dir).entryInfoList(QStringList() << "*.wav", QDir::Files);
    int total = files.count(), correct = 0, i = 0;
    ui.consoleWidget->logMessage(tr("Number of files: %1").arg(total));

    DtwRecognizer* recognizer = new DtwRecognizer(dict, this);
    connect(recognizer, SIGNAL(sendMessage(QString, QColor)),
            ui.consoleWidget, SLOT(logMessage(QString, QColor)));
    connect(recognizer, SIGNAL(progressRangeChanged(int,int)),
            progressBar, SLOT(setRange(int,int)));
    connect(recognizer, SIGNAL(progressChanged(int)),
            progressBar, SLOT(setValue(int)));

    progressBar->reset();
    progressBar->show();

    foreach (QFileInfo fi, files)
    {
        QString file = fi.canonicalFilePath();
        ui.consoleWidget->logMessage(file);
        ui.consoleWidget->logMessage(tr("Recognizing file %1 of %2").arg(++i).arg(total), Qt::darkBlue);

        RecognizingResult result = recognizer->recognizeFile(file);
        if (result.label == expectedLabel)
            correct++;
    }

    ui.consoleWidget->logMessage(tr("Batch recognizing finished"), Qt::darkGreen);
    ui.consoleWidget->logMessage(tr("Correctly recognized %1 out of %2 files (%3 percent)").
        arg(correct).arg(total).arg(100.0 * correct / static_cast<double>(total), 0, 'f', 4));
    QDateTime stop = QDateTime::currentDateTime();
    ui.consoleWidget->logMessage(tr("Finished at %1").arg(stop.toString()));
    ui.consoleWidget->logMessage(tr("Total time: %1 seconds").arg(start.secsTo(stop)));
    QApplication::alert(this);

    progressBar->hide();

    delete recognizer;
    delete dict;
}

/**
 * Pomiar wydajności programu.
 */
void SimpleBird::benchmark()
{
    Benchmark b;
    connect(&b, SIGNAL(sendMessage(QString)), ui.consoleWidget, SLOT(logMessage(QString)));

    b.run();
}

/**
 * Slot akcji "pokaż spektrogram".
 */
void SimpleBird::showSpectrogram()
{
    chartsWidget->drawSpectrogram(filesWidget->currentWaveFile());
    goToCharts();
}

/**
 * Slot akcji "pokaż wykres cech".
 */
void SimpleBird::showFeatureChart()
{
    if (filesWidget->currentFileType() == FilesWidget::Feature)
    {
        chartsWidget->drawFeatureChart(filesWidget->currentExtractor());
        goToCharts();
        return;
    }

    QString featureType = cbxFeatureType->itemData(
        cbxFeatureType->currentIndex(), Qt::UserRole).toString();
    Aquila::Extractor* extractor = FormatFactory::getExtractor(featureType);

    SimpleBirdSettings settings;
    Aquila::TransformOptions options;
    options.zeroPaddedLength = filesWidget->currentWaveFile()->getSamplesPerFrameZP();
    options.windowType = settings.getWindowType();
    options.preemphasisFactor = settings.getPreemphasis();

    ProgressBarIndicator indicator(progressBar);
    extractor->setProcessingIndicator(&indicator);
    extractor->process(filesWidget->currentWaveFile(), options);

    // filesWidget przejmuje wskaźnik do ekstraktora na własność
    filesWidget->addExtractor(extractor);

    chartsWidget->drawFeatureChart(extractor);
    goToCharts();
}

/**
 * Slot przycisku "Oblicz cechy" z głównego paska narzędzi.
 */
void SimpleBird::calculateFeatureFromToolbar()
{
    QString featureType = cbxFeatureType->itemData(
        cbxFeatureType->currentIndex(), Qt::UserRole).toString();
    calculateFeature(featureType);
}

/**
 * Obliczanie dowolnych cech nagrania.
 *
 * @param featureType typ cech, np. energia, moc, MFCC itp.
 */
void SimpleBird::calculateFeature(QString featureType)
{
    Aquila::WaveFile* wav = filesWidget->currentWaveFile();

    QFileInfo info(wav->getFilename().c_str());
    QString defaultName = info.path() + "/" + info.baseName() + ".bir";
    QString featureFile = QFileDialog::getSaveFileName(this,
        tr("Save feature file (%1)").arg(featureType),
        defaultName,
        FormatFactory::getFeatureFormatsFilter());

    if (!featureFile.isEmpty())
    {
        SimpleBirdSettings settings;
        Aquila::TransformOptions options;
        options.zeroPaddedLength = wav->getSamplesPerFrameZP();
        options.windowType = settings.getWindowType();
        options.preemphasisFactor = settings.getPreemphasis();

        QApplication::setOverrideCursor(Qt::WaitCursor);
        Aquila::Extractor* extractor = 0;
        Aquila::FeatureWriter* writer = 0;
        try
        {
            ui.consoleWidget->logMessage(tr("Calculating feature: %1...").arg(featureType));

            ProgressBarIndicator indicator(progressBar);
            extractor = FormatFactory::getExtractor(featureType);
            extractor->setProcessingIndicator(&indicator);
            extractor->process(wav, options);

            ui.consoleWidget->logMessage(tr("Saving to %1...").arg(featureFile));
            writer = FormatFactory::getFeatureWriter(featureFile);
            extractor->save(*writer);
            ui.consoleWidget->logMessage(tr("Save successful"));

            workspaceWidget->refresh();
        }
        catch (Aquila::Exception& e)
        {
            ui.consoleWidget->logWarning(QString::fromStdString(e.what()));
        }

        delete writer;
        delete extractor;
        QApplication::restoreOverrideCursor();
    }
}

/**
 * Rozpoznaje aktualnie wybrany plik.
 */
void SimpleBird::recognizeCurrentFile()
{
    QString dbfile = SimpleBirdApplication::directoryOf("data") + "/dictionary.db";
    Dictionary* dict = new Dictionary(dbfile, this);

    DtwRecognizer* recognizer = new DtwRecognizer(dict, this);
    connect(recognizer, SIGNAL(sendMessage(QString, QColor)),
            ui.consoleWidget, SLOT(logMessage(QString, QColor)));
    connect(recognizer, SIGNAL(progressRangeChanged(int,int)),
            progressBar, SLOT(setRange(int,int)));
    connect(recognizer, SIGNAL(progressChanged(int)),
            progressBar, SLOT(setValue(int)));

    progressBar->reset();
    progressBar->show();
    ui.actionRecognizeCurrentFile->setEnabled(false);

    recognizer->recognizeFile(filesWidget->currentFile());

    ui.actionRecognizeCurrentFile->setEnabled(true);
    progressBar->hide();

    delete recognizer;
    delete dict;
}

/**
 * Wyświetla okno widoku słownika wzorców.
 */
void SimpleBird::showDictionary()
{
    if (!dictionaryDlg)
    {
        dictionaryDlg = new DictionaryDialog(this);
        connect(dictionaryDlg, SIGNAL(sendMessage(QString, QColor)),
                ui.consoleWidget, SLOT(logMessage(QString, QColor)));
    }
    dictionaryDlg->show();
}

/**
 * Wywołuje okienko ustawień.
 */
void SimpleBird::showPreferences()
{
    PreferencesDialog dlg(this);
    if (dlg.exec())
    {
        dlg.saveSettings();
        SimpleBirdSettings settings;
        // przeładowanie plików, jeśli zmieniły się parametry ramek
        unsigned int frameLength = settings.getFrameLength();
        double overlap = settings.getOverlap();
        filesWidget->recalculateWaveFiles(frameLength, overlap);

        if (settings.useStylesheet())
            loadStylesheet(settings.getStylesheet());
        else
            qApp->setStyleSheet(QString());

        updateUi();
    }
}

/**
 * Pokazuje okno historii zmian w programie.
 */
void SimpleBird::showChangelog()
{
    ChangelogDialog dlg(this);
    dlg.exec();
}

/**
 * Prezentuje informacje o programie.
 */
void SimpleBird::about()
{
    QString version = qApp->applicationVersion();
#ifdef BUILDNUMBER
    version += tr(" (build %1)").arg(BUILDNUMBER);
#endif

    QMessageBox::about(this, tr("About %1").arg(qApp->applicationName()),
        tr("SimpleBird %1 - a bird voices recognizing software\n\n"
           "Copyright Zbigniew Siciarz 2009-2010\n\n"
           "This program uses Aquila DSP library for calculations and recognizing.\n"
           "Aquila %2, (c) Zbigniew Siciarz 2007-2010\n\n"
           "Using Qt version %3, Qwt %4").
            arg(version).arg(Aquila::VERSION.c_str())
            .arg(QT_VERSION_STR).arg(QWT_VERSION_STR));
}
