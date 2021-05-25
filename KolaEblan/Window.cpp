#include "Window.h"

Window::Window(super::RGB background_color) {
    this->background_color = background_color;
}
void InsertInTrees(std::vector<Tree*> trees, int64_t key, int64_t& index);
void RemoveFromTrees(std::vector<Tree*> trees, int64_t key, int64_t& index);
void SimpleTree(std::vector<Tree*> trees, int64_t key, int64_t& index);
void AVLTree(std::vector<Tree*> trees, int64_t key, int64_t& index);
void RedBlackTree(std::vector<Tree*> trees, int64_t key, int64_t& index);
void Splay(std::vector<Tree*> trees, int64_t key, int64_t& index);
void Treap(std::vector<Tree*> trees, int64_t key, int64_t& index);
void ResetTree(std::vector<Tree*> trees, int64_t key, int64_t& index);
void SplayFunc(std::vector<Tree*> trees, int64_t key, int64_t& index);
void CreatesElements(std::vector<Tree*> trees, int64_t key, int64_t& index);
void Window::render() {
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "SFML works!", sf::Style::Default);

    sf::Font font;
    font.loadFromFile("Ubuntu-B.ttf");
    srand(time(nullptr));

    std::vector<Button*> buttons;

    buttons.push_back(new Button({ 40, 80 }, { 50, 100 }, { "Insert", font, 20 }, { 245,171,201 }, InsertInTrees));
    buttons.push_back(new Button({ 150, 80 }, { 50, 100 }, { "Remove", font, 20 }, { 245,171,201 }, RemoveFromTrees));
    buttons.push_back(new Button({ 40, 200 }, { 50, 210 }, { "Simple", font, 30 }, { 245,171,201 }, SimpleTree));
    buttons.push_back(new Button({ 40, 260 }, { 50, 210 }, { "AVL", font, 30 }, { 245,171,201 }, AVLTree));
    buttons.push_back(new Button({ 40, 320 }, { 50, 210 }, { "Splay", font, 30 }, { 245,171,201 }, Splay));
    buttons.push_back(new Button({ 40, 380 }, { 50, 210 }, { "Treap", font, 30 }, { 245,171,201 }, Treap));
    buttons.push_back(new Button({ 40, 440 }, { 50, 210 }, { "Red Black", font, 30 }, { 245,171,201 }, nullptr));
    buttons.push_back(new Button({ 40, 500 }, { 50, 210 }, { "Reset", font, 30 }, { 245,171,201 }, ResetTree));
    buttons.push_back(new Button({ 40, 560 }, { 50, 210 }, { "Create many elements", font, 18 }, { 245,171,201 }, CreatesElements));

    std::vector<std::pair<Button*, std::pair<int, int>>> special_buttons;
    std::vector<std::pair<Input*, int>> special_inputs;

    std::vector<Input*> inputs;
    inputs.push_back(new Input({ 40 , 20 }, { 50, 210 }, { 245,171,201 }, { "", font, 20 }));

    std::vector<Tree*> trees;
    trees.push_back(new BinaryTree({ 233, 59, 129 }));
    trees.push_back(new AVL({ 233, 59, 129 }));
    trees.push_back(new SplayTree({ 233, 59, 129 }));
    trees.push_back(new TreapTree({ 233, 59, 129 }));

    int64_t index = -1;

    special_inputs.push_back({ new Input({ 40 , 640 }, { 50, 210 }, { 245,171,201 }, { "", font, 20 }) , 2});
    special_buttons.push_back({ new Button({ 40, 700 }, { 50, 210 }, { "Splay", font, 30 }, { 245,171,201 }, SplayFunc), {0, 2} });


    sf::CircleShape ha(100.f);
    sf::RectangleShape background;
    background.setPosition(0, 0);
    background.setFillColor(sf::Color(233, 59, 129));
    background.setSize(sf::Vector2f(1920 / 6, 1080));
    sf::View view(sf::FloatRect(0, 0, window.getSize().x / 6 * 5, window.getSize().y));
    view.setViewport(sf::FloatRect(1.f / 6.f, 0.0f, 1.f / 6.f * 5.f, 1.f));
    //sf::View view = window.getDefaultView();
    window.setView(view);
    sf::View view2 (sf::FloatRect(0, 0, window.getSize().x / 6, window.getSize().y));
    view2.setViewport(sf::FloatRect(0.f, 0.f, 1.f / 6.f, 1.f));

    int back = 0;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Right) {
                    view.move(+view.getSize().x / 20, 0.f);
                    window.setView(view);
                }

                if (event.key.code == sf::Keyboard::Left) {
                    view.move(-view.getSize().x / 20, 0.f);
                    window.setView(view);
                }
                if (event.key.code == sf::Keyboard::Up) {
                    view.move(0.f, -view.getSize().y / 20);
                    window.setView(view);
                }
                if (event.key.code == sf::Keyboard::Down) {
                    view.move(0.f, +view.getSize().y / 20);
                    window.setView(view);
                }
            }
            if (event.type == sf::Event::MouseWheelScrolled) {
                if (event.mouseWheelScroll.delta > 0) {
                    view.zoom(0.9f);
                    window.setView(view);
                }
                if (event.mouseWheelScroll.delta < 0) {
                    view.zoom(1.1f);
                    window.setView(view);
                }
               
            }
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                 window.setView(view2);
                for (auto in : inputs) {
                    in->setIsPressed(in->checkClick(window));
                }
                for (std::pair<Input*, int> in : special_inputs) {
                    in.first->setIsPressed(in.first->checkClick(window));
                }
                for (auto in : buttons) {
                    if (in->checkClick(window)) {
                        if (in->getOnClick()) {
                            in->getOnClick()(trees, (inputs[0]->getText().text == "" ? 0 : std::stoll(inputs[0]->getText().text)), index);
                        }
                    }
                }
                for (std::pair<Button*, std::pair<int, int>> in : special_buttons) {
                    if (in.first->checkClick(window)) {
                        if (in.first->getOnClick()) {
                            in.first->getOnClick()(trees, (special_inputs[in.second.first].first->getText().text == "" ? 0 : std::stoll(special_inputs[in.second.first].first->getText().text)), index);
                        }
                    }
                }
                window.setView(view);
            }
            if (event.type == sf::Event::TextEntered) {
                for (auto in : inputs) {
                    if (in->getIsPressed()) {
                        if ((event.text.unicode >= 0x30 && event.text.unicode <= 0x39 ||  event.text.unicode == '-')&& in->getText().text.size() < 8) {
                            in->setString(in->getString() + static_cast<char>(event.text.unicode));
                        }
                    }
                }
                for (std::pair<Input*, int> in : special_inputs) {
                    if (in.first->getIsPressed()) {
                        if ((event.text.unicode >= 0x30 && event.text.unicode <= 0x39 || event.text.unicode == '-') && in.first->getText().text.size() < 8) {
                            in.first->setString(in.first->getString() + static_cast<char>(event.text.unicode));
                        }
                    }
                }
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Backspace)) {
                for (auto in : inputs) {
                    if (in->getIsPressed()) {
                        ++back;
                        if (in->getText().text.size() != 0 && back % 2 == 1) {
                            in->setText(in->getText().text.erase(in->getText().text.size() - 1, 1), in->getText().font, in->getText().char_size);
                        }
                    }
                }
                for (std::pair<Input*, int> in : special_inputs) {
                    if (in.first->getIsPressed()) {
                        ++back;
                        if (in.first->getText().text.size() != 0 && back % 2 == 1) {
                            in.first->setText(in.first->getText().text.erase(in.first->getText().text.size() - 1, 1), in.first->getText().font, in.first->getText().char_size);
                        }
                    }
                }
                
            }

        }

        window.clear({ background_color.red, background_color.green, background_color.blue });
        window.setView(view2);
        window.draw(background);
        buttons[0]->display(window, 10, 5);
        buttons[1]->display(window, 10, 5);
        for (int in = 2; in <= 7; ++in){ 
            if (in - 2 == index) {
                buttons[in]->setColor({ 240, 240, 240 });
            }
            buttons[in]->display(window, 50, 5);
            buttons[in]->setColor({ 245,171,201 });
        }
        buttons[8]->display(window, 10, 5);


        for (auto in : special_buttons) {
            if (in.second.second == index) {
                in.first->display(window, 50, 5);
            }
        }
        for (auto in : special_inputs) {
            if (in.second == index) {
                in.first->display(window, 0, 0);
            }
        }

        for (auto in : inputs) {
            in->display(window, 0 , 0);
        }
        window.setView(view);
        if (index != -1) {
            trees[index]->display(window);
        }
        window.display();
    }
}

void InsertInTrees(std::vector<Tree*> trees, int64_t key, int64_t& index) {
    if (index == -1) {
        return;
    }
    for (auto in : trees) {
        in->insert(key);
    }
}

void RemoveFromTrees(std::vector<Tree*> trees, int64_t key, int64_t& index) {
    if (index == -1) {
        return;
    }
    for (auto in : trees) {
        in->remove(key);
    }
}


void SimpleTree(std::vector<Tree*> trees, int64_t key, int64_t& index) {
    index = 0;
}

void AVLTree(std::vector<Tree*> trees, int64_t key, int64_t& index) {
    index = 1;
}

void Splay(std::vector<Tree*> trees, int64_t key, int64_t& index)
{
    index = 2;
}

void Treap(std::vector<Tree*> trees, int64_t key, int64_t& index)
{
    index = 3;
}

void RedBlackTree(std::vector<Tree*> trees, int64_t key, int64_t& index)
{
    index = 4;
}

void ResetTree(std::vector<Tree*> trees, int64_t key, int64_t& index)
{
    for (auto in : trees) {
        in->clear();
    }
}

void SplayFunc(std::vector<Tree*> trees, int64_t key, int64_t& index)
{
    if (trees[index] == nullptr) {
        return;
    }
    dynamic_cast<SplayTree*>(trees[index])->splay(key);
}

void CreatesElements(std::vector<Tree*> trees, int64_t key, int64_t& index)
{
    for (int i = 0; i < 10; ++i) {
        int64_t random = rand();
        for (auto in : trees) {
            in->insert(random);
        }
    }
}

