TEMPLATE = app
TARGET = SimpleBird
QT += core \
    gui \
    xml \
    sql \
    script
include(libraries.pri)
HEADERS += simplebird.h \
    widgets/WavePropertiesWidget.h \
    plots/PlotZoomer.h \
    plots/WaveFileData.h \
    plots/WaveformPlot.h \
    plots/SpectrogramData.h \
    plots/SpectrogramPlot.h \
    plots/FrequencyScaleDraw.h \
    plots/DurationScaleDraw.h \
    PreferencesDialog.h \
    plots/SpectrogramPlotZoomer.h \
    SimpleBirdApplication.h \
    formats/QBinaryFeatureReader.h \
    formats/QBinaryFeatureWriter.h \
    formats/FormatFactory.h \
    formats/QXmlFeatureWriter.h \
    formats/QXmlFeatureReader.h \
    ProgressBarIndicator.h \
    widgets/workspace/WorkspaceWidget.h \
    widgets/workspace/WorkspaceTreeView.h \
    widgets/workspace/WorkspaceDirModel.h \
    widgets/charts/ChartsWidget.h \
    ChangelogDialog.h \
    widgets/color/ColorWidget.h \
    plots/FeatureData.h \
    MelFiltersDialog.h \
    widgets/files/FilesWidget.h \
    widgets/ExtractorPropertiesWidget.h \
    recognizing/Dictionary.h \
    DictionaryDialog.h \
    Benchmark.h \
    plots/DtwData.h \
    SimpleBirdSettings.h \
    widgets/console/ConsoleWidget.h \
    recognizing/Recognizer.h \
    recognizing/DtwRecognizer.h \
    recognizing/Classifier.h \
    recognizing/NeighborClassifier.h \
    widgets/scripts/ScriptsWidget.h \
    script/TextEditConsole.h \
    script/ScriptEngine.h \
    script/Console.h \
    script/prototypes/WaveFilePrototype.h \
    script/prototypes/prototypes.h \
    widgets/scripts/ScriptIconProvider.h \
    widgets/scripts/QtScriptHighligher.h \
    script/prototypes/DictionaryPrototype.h \
    script/prototypes/RecognizerPrototype.h \
    BenchmarkDialog.h
SOURCES += main.cpp \
    simplebird.cpp \
    widgets/WavePropertiesWidget.cpp \
    plots/PlotZoomer.cpp \
    plots/WaveFileData.cpp \
    plots/WaveformPlot.cpp \
    plots/SpectrogramData.cpp \
    plots/SpectrogramPlot.cpp \
    plots/FrequencyScaleDraw.cpp \
    plots/DurationScaleDraw.cpp \
    PreferencesDialog.cpp \
    plots/SpectrogramPlotZoomer.cpp \
    SimpleBirdApplication.cpp \
    formats/QBinaryFeatureReader.cpp \
    formats/QBinaryFeatureWriter.cpp \
    formats/FormatFactory.cpp \
    formats/QXmlFeatureWriter.cpp \
    formats/QXmlFeatureReader.cpp \
    ProgressBarIndicator.cpp \
    widgets/workspace/WorkspaceWidget.cpp \
    widgets/workspace/WorkspaceTreeView.cpp \
    widgets/workspace/WorkspaceDirModel.cpp \
    widgets/charts/ChartsWidget.cpp \
    ChangelogDialog.cpp \
    widgets/color/ColorWidget.cpp \
    plots/FeatureData.cpp \
    MelFiltersDialog.cpp \
    widgets/files/FilesWidget.cpp \
    widgets/ExtractorPropertiesWidget.cpp \
    recognizing/Dictionary.cpp \
    DictionaryDialog.cpp \
    Benchmark.cpp \
    plots/DtwData.cpp \
    SimpleBirdSettings.cpp \
    widgets/console/ConsoleWidget.cpp \
    recognizing/Recognizer.cpp \
    recognizing/DtwRecognizer.cpp \
    recognizing/Classifier.cpp \
    recognizing/NeighborClassifier.cpp \
    widgets/scripts/ScriptsWidget.cpp \
    script/TextEditConsole.cpp \
    script/ScriptEngine.cpp \
    script/Console.cpp \
    script/prototypes/WaveFilePrototype.cpp \
    script/prototypes/prototypes.cpp \
    widgets/scripts/QtScriptHighligher.cpp \
    script/prototypes/DictionaryPrototype.cpp \
    script/prototypes/RecognizerPrototype.cpp \
    BenchmarkDialog.cpp
FORMS += simplebird.ui \
    PreferencesDialog.ui \
    widgets/workspace/WorkspaceWidget.ui \
    widgets/charts/ChartsWidget.ui \
    ChangelogDialog.ui \
    MelFiltersDialog.ui \
    widgets/files/FilesWidget.ui \
    DictionaryDialog.ui \
    widgets/console/ConsoleWidget.ui \
    widgets/scripts/ScriptsWidget.ui \
    BenchmarkDialog.ui
TRANSLATIONS = simplebird_pl.ts
CODECFORTR = UTF-8
RESOURCES += icons.qrc \
    texts.qrc \
    style.qrc
OTHER_FILES += CHANGELOG.txt \
    aquila/CHANGELOG.txt \
    styles/default/style.css \
    scripts/wave_properties.js \
    scripts/settings_example.js \
    scripts/dictionary.js \
    scripts/recognizer.js \
    scripts/batch_recognizing.js \
    scripts/research.js
win32:BUILDNO = $$system(build.py)
unix:BUILDNO = $$system(./build.py)
DEFINES += BUILDNUMBER=$${BUILDNO}
