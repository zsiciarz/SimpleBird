/**
 * @file SimpleBirdApplication.cpp
 *
 * Obiekt aplikacji - implementacja.
 *
 * @author Zbigniew Siciarz
 * @date 2009-2010
 * @version 0.8.2
 * @since 0.2.2
 */

#include "SimpleBirdApplication.h"

#include "SimpleBirdSettings.h"
#include "aquila/global.h"
#include <QDir>
#include <QLocale>
#include <QTranslator>


/**
 * Tworzy obiekt aplikacji.
 *
 * @param argc liczba argumentów
 * @param argv tablica argumentów
 */
SimpleBirdApplication::SimpleBirdApplication(int& argc, char** argv):
    QApplication(argc, argv)
{
    setOrganizationName("Zbigniew Siciarz");
    setApplicationName("SimpleBird");
    setApplicationVersion(SIMPLEBIRD_VERSION);
    initSettings();
    loadTranslations();
}

QString SimpleBirdApplication::directoryOf(const QString &subdir)
{
    QDir dir(applicationDirPath());

#if defined(Q_OS_WIN)
    if (dir.dirName().toLower() == "debug" || dir.dirName().toLower() == "release")
        dir.cdUp();
#elif defined(Q_OS_MAC)
    if (dir.dirName() == "MacOS")
    {
        dir.cdUp();
        dir.cdUp();
        dir.cdUp();
    }
#endif
    dir.cd(subdir);
    return dir.canonicalPath();
}

/**
 * Zapisuje domyślne ustawienia aplikacji przy pierwszym uruchomieniu.
 */
void SimpleBirdApplication::initSettings()
{
    SimpleBirdSettings settings;
    if (settings.value("firstRun").toBool() == true)
    {
        settings.restoreDefaults();
        settings.setValue("firstRun", false);
    }
}

/**
 * Wczytuje tłumaczenia z podkatalogu translations.
 */
void SimpleBirdApplication::loadTranslations()
{
    QString translationsPath = directoryOf("translations");
    QString locale = QLocale::system().name();

    // Qt translations
    QTranslator* qtTranslator = new QTranslator(this);
    qtTranslator->load("qt_" + locale, translationsPath);
    installTranslator(qtTranslator);

    // SimpleBird translations
    QTranslator* appTranslator = new QTranslator(this);
    appTranslator->load("simplebird_" + locale, translationsPath);
    installTranslator(appTranslator);
}


