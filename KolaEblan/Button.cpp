#include "Button.h"

Button::Button(super::Coordinates coor, super::Size size, super::TextSFML text, super::RGB color, std::function<void(std::vector<Tree*> trees, int64_t key, int64_t& index)> onClick)
{
    this->coor = coor;
    this->size = size;
    this->text = text;
    this->color = color;
    this->onClick = onClick;

    this->rect.setSize(sf::Vector2f(size.width, size.height));
    this->rect.setFillColor(sf::Color(color.red, color.green, color.blue));
    this->rect.setPosition(coor.x, coor.y);
}


void Button::setOnClick(std::function<void(std::vector<Tree*> trees, int64_t key, int64_t& index)> onClick = nullptr)
{
    this->onClick = onClick;
}

std::function<void(std::vector<Tree*> trees, int64_t key, int64_t& index)> Button::getOnClick()
{
    return this->onClick;
}



