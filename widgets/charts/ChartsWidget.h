/**
 * @file ChartsWidget.h
 *
 * Kontrolka zarządzania wykresami - nagłówek.
 *
 * @author Zbigniew Siciarz
 * @date 2009-2010
 * @version 0.8.2
 * @since 0.4.0
 */

#ifndef CHARTSWIDGET_H
#define CHARTSWIDGET_H

#include "aquila/WaveFile.h"
#include "aquila/feature/Extractor.h"
#include <qwt_plot.h>
#include <QKeyEvent>
#include <QMenu>
#include <QString>
#include <QWidget>


namespace Ui {
    class ChartsWidget;
}

/**
 * Kontrolka zarządzania wykresami.
 *
 * Umożliwia dodawanie wykresów, zapisywanie i drukowanie jako obrazków.
 */
class ChartsWidget : public QWidget
{
    Q_OBJECT

public:
    ChartsWidget(QWidget *parent = 0);
    ~ChartsWidget();

    /**
     * Zwraca wskaźnik do menu związanego z tą kontrolką.
     */
    QMenu* getMenu() const { return menu; }

public slots:
    void drawWaveform(Aquila::WaveFile* wavefile);

    void drawSpectrogram(Aquila::WaveFile* wavefile);

    void drawFeatureChart(Aquila::Extractor* extractor);

    void drawDtwChart(Aquila::Extractor* extractor);

signals:
    /**
     * Sygnał emitowany w momencie utworzenia nowego wykresu.
     *
     * @param chartIndex indeks zakładki
     */
    void chartAdded(int chartIndex);

    /**
     * Sygnał emitowany w momencie usunięcia zakładki z wykresem.
     *
     * @param chartIndex indeks zakładki
     */
    void chartRemoved(int chartIndex);

    /**
     * Sygnał wywoływany po zapisaniu wykresu do pliku graficznego.
     *
     * @param filename pełna ścieżka pliku
     */
    void chartSaved(QString filename);

    /**
     * Sygnał emitowany gdy kontrolka przestrzeni roboczej wysyła wiadomość na zewnątrz.
     *
     * @param message wiadomość
     */
    void sendMessage(QString message);

    /**
     * Sygnał emitowany, gdy kontrolka żąda przełączenia do przestrzeni roboczej.
     */
    void goToWorkspaceRequested();

protected:
    void keyPressEvent(QKeyEvent* event);

private slots:
    void saveChart();
    void refresh();
    void print();
    void addPlot(QwtPlot* plot, QString tabLabel);
    void closeChart(int index);
    void closeAllCharts();
    void goToWorkspace();
    void updateUi();

private:
    /**
     * Klasa interfejsu wygenerowana przez Designera.
     */
    Ui::ChartsWidget *ui;

    /**
     * Menu powiązane z kontrolką wykresów.
     */
    QMenu* menu;

    /**
     * Liczba wyświetlonych wykresów.
     */
    int chartsCount;
};

#endif // CHARTSWIDGET_H
