/**
 * @file button.cpp
 * @brief Header von Button
 * @author V. Feierle
 * */


#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QLayout>


namespace Ui {
class Button;
}

/**
 * @brief Klasse Button
 */
class Button : public QPushButton
{
    Q_OBJECT

/**
 * Deklaration von friend Klasse Spielfeld
 */
friend class Spielfeld;

public:
/**
 * @brief Konstruktor Button
 * @param x x-Koordinate
 * @param y y-Koordinate
 */
    Button(int x,int y);

private:
    /**
     * @brief _x: x-Koordinate
     */
    int _x;
    /**
     * @brief _y: y-Koordinate
     */
    int _y;
};





#endif // BUTTON_HPP

