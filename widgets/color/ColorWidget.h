/**
 * @file ColorWidget.h
 *
 * Kontrolka wyboru koloru - nagłówek.
 *
 * @author Zbigniew Siciarz
 * @date 2009-2010
 * @version 0.8.2
 * @since 0.6.0
 */

#ifndef COLORWIDGET_H
#define COLORWIDGET_H

#include <QColor>
#include <QLabel>
#include <QPushButton>
#include <QString>
#include <QWidget>


/**
 * Kontrolka wyboru koloru.
 */
class ColorWidget : public QWidget
{
    Q_OBJECT
public:
    ColorWidget(QWidget* parent = 0);

    /**
     * Zwraca aktualnie wybrany kolor.
     */
    QColor getColor() const { return m_color; }

    /**
     * Ustawia bieżący kolor.
     */
    void setColor(QColor color) { m_color = color; updateLabel(); }

private slots:
    void colorButtonClicked();

private:
    void updateLabel();

    /**
     * Wartość bieżącego koloru.
     */
    QColor m_color;

    /**
     * Etykietka prezentująca kolor w hex.
     */
    QLabel* lblColor;

    /**
     * Styl CSS etykietki.
     */
    QString lblStyle;

    /**
     * Przycisk otwierający okno wyboru koloru.
     */
    QPushButton* btnChooseColor;
};

#endif // COLORWIDGET_H
