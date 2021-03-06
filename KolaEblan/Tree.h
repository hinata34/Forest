#pragma once
#include "Config.h"
class Tree
{
public:
	 Tree();
	 void display(sf::RenderWindow& window);
	 void clear();
	 int64_t countHeight();
	 virtual void insert(int64_t key) = 0;
	 virtual void remove(int64_t key) = 0;
	 std::vector<super::Node*> phases;
protected:
	void clearTrue(super::Node* elem);
	super::RGB color;
	int64_t countHeightTrue(super::Node* top);
	int64_t index = 0;
};

