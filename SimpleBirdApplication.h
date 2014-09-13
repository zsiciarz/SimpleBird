/**
 * @file SimpleBirdApplication.h
 *
 * Obiekt aplikacji - nagłówek.
 *
 * @author Zbigniew Siciarz
 * @date 2009-2010
 * @version 0.8.2
 * @since 0.2.2
 */

#ifndef SIMPLEBIRDAPPLICATION_H
#define SIMPLEBIRDAPPLICATION_H

#include <QApplication>


#define SIMPLEBIRD_VERSION "0.8.2"

class SimpleBirdApplication : public QApplication
{
public:
    SimpleBirdApplication(int& argc, char** argv);
    static QString directoryOf(const QString &subdir);

private:
    void initSettings();
    void loadTranslations();
};

#endif // SIMPLEBIRDAPPLICATION_H
