#include "Input.h"

Input::Input(super::Coordinates coor, super::Size size, super::RGB color, super::TextSFML text)
{
    this->coor = coor;
    this->size = size;
    this->color = color;
    this->text = text;

    this->rect.setSize(sf::Vector2f(size.width, size.height));
    this->rect.setFillColor(sf::Color(color.red, color.green, color.blue));
    this->rect.setPosition(coor.x, coor.y);

}

void Input::setIsPressed(bool request)
{
    this->isPressed = request;
}

bool Input::getIsPressed()
{
    return this->isPressed;
}

