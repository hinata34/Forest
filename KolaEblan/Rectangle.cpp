#include "Rectangle.h"


Rectangle::Rectangle()
{
    ;
}

void Rectangle::display(sf::RenderWindow& window, int64_t x_offeset, int64_t y_offeset)
{
    this->rect.setOutlineThickness(3);
    window.draw(this->rect);
    sf::Text text(this->text.text, this->text.font, this->text.char_size);
    text.setPosition(this->rect.getPosition().x + x_offeset, this->rect.getPosition().y + y_offeset);
    text.setFillColor(sf::Color::White);
    window.draw(text);
}
bool Rectangle::checkClick(sf::RenderWindow& window)
{
    if (window.mapPixelToCoords(sf::Mouse::getPosition(window)).x >= this->coor.x &&
        window.mapPixelToCoords(sf::Mouse::getPosition(window)).x <= this->coor.x + this->size.width &&
        window.mapPixelToCoords(sf::Mouse::getPosition(window)).y >= this->coor.y &&
        window.mapPixelToCoords(sf::Mouse::getPosition(window)).y <= this->coor.y + this->size.height) {
        return true;
    }
    return false;
}

void Rectangle::setCoordinates(super::Coordinates coor = { 0,0 })
{
    this->coor = coor;
}

void Rectangle::setCoordinates(double x = 0, double y = 0)
{
    this->coor.x = x;
    this->coor.y = y;
}

super::Coordinates Rectangle::getCoordinates()
{
    return this->coor;
}

void Rectangle::setSize(super::Size size = { 100, 100 })
{
    this->size = size;
}

void Rectangle::setSize(double height = 0, double width = 0)
{
    this->size.height = height;
    this->size.width = width;
}

super::Size Rectangle::getSize()
{
    return this->size;
}

void Rectangle::setText(super::TextSFML text = { "", sf::Font(), 0 })
{
    this->text = text;
}

void Rectangle::setText(std::string text = "", sf::Font font = sf::Font(), int64_t char_size = 0)
{
    this->text = { text, font, char_size };
}

void Rectangle::setString(std::string s)
{
    this->text.text = s;
}

super::TextSFML Rectangle::getText()
{
    return this->text;
}

std::string Rectangle::getString()
{
    return this->text.text;
}

void Rectangle::setColor(super::RGB color = { 0, 0, 0 })
{
    this->color = color;
    this->rect.setFillColor(sf::Color{ color.red, color.green, color.blue });
}

void Rectangle::setColor(uint8_t red = 0, uint8_t green = 0, uint8_t blue = 0)
{
    this->color = { red, green, blue };
    this->rect.setFillColor(sf::Color{ color.red, color.green, color.blue });
}

super::RGB Rectangle::getColor()
{
    return this->color;
}

sf::Color Rectangle::getColorSFML()
{
    return { this->color.red, this->color.green, this->color.blue };
}