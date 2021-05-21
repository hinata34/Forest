#pragma once
namespace super {
    struct Coordinates {
        double x = 0;
        double y = 0;
        Coordinates(double x = 0, double y = 0) {
            this->x = x;
            this->y = y;
        }
    };

    struct Size {
        double height = 0;
        double width = 0;
        Size(double height = 0, double width = 0) {
            this->height = height;
            this->width = width;
        }
    };
    struct RGB {
        uint8_t red, green, blue;
    };
    struct Node {
        Node* right, * left;
        int64_t key, height, priority;
        RGB color;
        Node(Node* right = nullptr, Node* left = nullptr, int64_t key = 0, int64_t height = 0, int priority = 0, RGB color = { 255, 255, 255 }) {
            this->right = right;
            this->left = left;
            this->key = key;
            this->height = height;
            this->priority = priority;
            this->color = color;
        }
    };
    struct TextSFML {
        std::string text;
        sf::Font font;
        int64_t char_size;
    };
}
