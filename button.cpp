#include "button.hpp"

Button::Button()
{
	//buttonRectangle.setFillColor(sf::Color::Blue);
	buttonTexture.loadFromFile("./content/button.png");
	buttonRectangle.setTexture(&buttonTexture);
	buttonRectangle.setPosition(sf::Vector2f(208, 330));
	buttonRectangle.setSize(sf::Vector2f(85, 29));
}

void Button::drawButton(sf::RenderWindow& window)
{
	window.draw(buttonRectangle);
}