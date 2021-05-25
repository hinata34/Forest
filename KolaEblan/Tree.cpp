#include "Tree.h"
sf::Vertex line[] =
{
	sf::Vertex(sf::Vector2f(10, 10)),
	sf::Vertex(sf::Vector2f(150, 150))
};
Tree::Tree()
{
	;
}
void Tree::display(sf::RenderWindow& window) {
	int64_t height = countHeight();
	std::queue < std::pair < super::Node*, std::pair< std::pair< double , double >, int64_t > > > lines;
	lines.push({ phases[index], {{500 , 500}, height } });
	if (height == 0) {
		return;
	}
	int64_t coef = 25;

	while (!lines.empty()) {
		std::pair < super::Node*, std::pair< std::pair< double, double >, int64_t >> element = lines.front();
		lines.pop();
		if (element.first->left != nullptr) {
			line[0] = sf::Vertex(sf::Vector2f(element.second.first.first + 50, element.second.first.second + 50));
			line[1] = sf::Vertex(sf::Vector2f(element.second.first.first - coef * pow(2, element.second.second) + 50, element.second.first.second + 150 + 50));
			line[0].color = sf::Color(255, 229, 226);
			line[1].color = sf::Color(255, 229, 226);
			window.draw(line, 2, sf::Lines);
			lines.push({ element.first->left, {{element.second.first.first - coef * pow(2, element.second.second), element.second.first.second + 150}, element.second.second - 1} });
		}
		if (element.first->right != nullptr) {
			line[0] = sf::Vertex(sf::Vector2f(element.second.first.first + 50, element.second.first.second + 50));
			line[1] = sf::Vertex(sf::Vector2f(element.second.first.first + coef * pow(2, element.second.second) + 50, element.second.first.second + 150 + 50));
			line[0].color = sf::Color(255, 229, 226);
			line[1].color = sf::Color(255, 229, 226);
			window.draw(line, 2, sf::Lines);
			lines.push({ element.first->right, {{element.second.first.first + coef * pow(2, element.second.second) , element.second.first.second + 150}, element.second.second - 1} });
		}
	}
	std::queue < std::pair < super::Node*, std::pair< std::pair< double, double >, int64_t > > > circles;
	circles.push({ phases[index], {{500 , 500}, height } });
	sf::CircleShape circle(50);
	circle.setPointCount(1000);
	sf::Text text;
	sf::Font font;
	font.loadFromFile("Ubuntu-B.ttf");
	text.setFont(font);
	text.setCharacterSize(30);
	text.setFillColor(sf::Color::White);
	while (!circles.empty()) {
		std::pair < super::Node*, std::pair< std::pair< double, double >, int64_t >> element = circles.front();
		circles.pop();
		circle.setPosition(element.second.first.first, element.second.first.second);
		circle.setFillColor(sf::Color(element.first->color.red, element.first->color.green, element.first->color.blue));
		text.setPosition(circle.getPosition().x + 30, circle.getPosition().y + 30);
		text.setString(std::to_string(element.first->key));
		window.draw(circle);
		window.draw(text);
		if (element.first->left != nullptr) {
			circles.push({ element.first->left, {{element.second.first.first - coef * pow(2, element.second.second), element.second.first.second + 150}, element.second.second - 1} });
		}
		if (element.first->right != nullptr) {
			circles.push({ element.first->right, {{element.second.first.first + coef * pow(2, element.second.second) , element.second.first.second + 150}, element.second.second - 1} });
		}
	}
	
}

void Tree::clear()
{
	for (auto& in : this->phases) {
		clearTrue(in);
		in = nullptr;
	}
	this->phases.resize(1000000, nullptr);
}

void Tree::clearTrue(super::Node* elem) {
	if (elem == nullptr) {
		return;
	}
	clearTrue(elem->right);
	clearTrue(elem->left);
	delete(elem);
}

int64_t Tree::countHeight()
{
	if (this->phases[this->index] == nullptr) {
		return 0;
	}
	return countHeightTrue(this->phases[this->index]);
}

int64_t Tree::countHeightTrue(super::Node* top)
{
	if (top == nullptr) {
		return 0;
	}
	return std::max(countHeightTrue(top->left) + 1, countHeightTrue(top->right) + 1);
}
