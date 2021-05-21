#pragma once
#include "Rectangle.h"
#include "Tree.h"
class Button : public Rectangle{
public:
    Button(super::Coordinates coor, super::Size size, super::TextSFML text, super::RGB color, std::function<void(std::vector<Tree*> trees, int64_t key, int64_t& index)> onClick);

    // setters for onClick
    void setOnClick(std::function<void(std::vector<Tree*> trees, int64_t key, int64_t& index)> onClick);

    // getters for onClick
    std::function<void(std::vector<Tree*> trees, int64_t key, int64_t& index)> getOnClick();

private:
    std::function<void(std::vector<Tree*> trees, int64_t key, int64_t& index)> onClick;
};
