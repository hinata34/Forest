#pragma once
#include "Rectangle.h"
class Input : public Rectangle{
public:
	Input(super::Coordinates coor, super::Size size, super::RGB color, super::TextSFML text);

	// setters for isPressed
	void setIsPressed(bool request);

	// getters for isPressed
	bool getIsPressed();
	
private:
	bool isPressed = false;
};

