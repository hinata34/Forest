#pragma once
#include "Button.h"
#include "Input.h"
#include "BinaryTree.h"
#include "AVL.h"
class Window
{
public:
	Window(super::RGB background_color = { 0 , 0 , 0 });
	void render();
private:
	super::RGB background_color;
};

