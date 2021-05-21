#pragma once
#include "Config.h"
class Rectangle
{
public:
	Rectangle();

	void display(sf::RenderWindow& window, int64_t x_offset, int64_t y_offset);
	bool checkClick(sf::RenderWindow& window);

	// setters for Coordinates
	void setCoordinates(super::Coordinates coor);
	void setCoordinates(double, double);

    // getters for Coordinates
    super::Coordinates getCoordinates();

    // setters for Size
    void setSize(super::Size size);
    void setSize(double height, double width);

    // getters for Size
    super::Size getSize();

    // setters for text
    void setText(super::TextSFML text);
    void setText(std::string text, sf::Font font, int64_t char_size);
    void setString(std::string s);

    // getters for text
    super::TextSFML getText();
    std::string getString();

    // setters for Color
    void setColor(super::RGB color);
    void setColor(uint8_t red, uint8_t green, uint8_t blue);
    
    // getters for Color
    super::RGB getColor();
    sf::Color getColorSFML();

protected:
	super::Coordinates coor;
	super::Size size;
	super::RGB color;
	super::TextSFML text;
	sf::RectangleShape rect;
};

