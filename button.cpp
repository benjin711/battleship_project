#include "ui_spielfeld.h"
#include <QWidget>
#include <QPushButton>
#include <QGridLayout>

#include "button.h"

Button::Button(int x, int y)
/// Initialisierungsliste für den Konstruktor
    : _x(x), _y(y)
{
}

