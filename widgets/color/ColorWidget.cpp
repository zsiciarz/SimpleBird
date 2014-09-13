/**
 * @file ColorWidget.cpp
 *
 * Kontrolka wyboru koloru - implementacja.
 *
 * @author Zbigniew Siciarz
 * @date 2009-2010
 * @version 0.8.2
 * @since 0.6.0
 */

#include "ColorWidget.h"
#include <QColorDialog>
#include <QFontMetrics>
#include <QHBoxLayout>


/**
 * Konstruktor - tworzy kontrolkę i ustawia domyślny kolor (czerwony).
 *
 * @param parent obiekt rodzica
 */
ColorWidget::ColorWidget(QWidget* parent):
    QWidget(parent), m_color(Qt::red), btnChooseColor(0)
{
    lblColor = new QLabel(m_color.name(), this);
    lblColor->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    lblColor->setAlignment(Qt::AlignCenter);
    lblStyle = QString("QLabel { background-color: %1; color: %2; }");
    updateLabel();
    btnChooseColor = new QPushButton(this);
    btnChooseColor->setText(tr("Choose color..."));
    connect(btnChooseColor, SIGNAL(clicked()), SLOT(colorButtonClicked()));
    QHBoxLayout* layout = new QHBoxLayout();
    layout->addWidget(lblColor);
    layout->addWidget(btnChooseColor);
    setLayout(layout);
}

/**
 * Slot naciśnięcia przycisku - otwiera okno wyboru koloru.
 */
void ColorWidget::colorButtonClicked()
{
    QColor color = QColorDialog::getColor(m_color, this, tr("Choose color"));
    if (color.isValid())
    {
        m_color = color;
        updateLabel();
    }
}

/**
 * Aktualizuje etykietę, dobierając kolor tła tak by kontrastował z wybranym.
 */
void ColorWidget::updateLabel()
{
    QFontMetrics fm(font());
    int lblWidth = fm.width(m_color.name()) + 5;
    int lblHeight = fm.height() + 5;
    lblColor->setMinimumSize(lblWidth, lblHeight);
    lblColor->setMaximumSize(lblWidth, lblHeight);
    QString foreground = m_color.value() > 150 ? "#000000" : "#ffffff";
    lblColor->setStyleSheet(lblStyle.arg(m_color.name()).arg(foreground));
    lblColor->setText(m_color.name());
}
