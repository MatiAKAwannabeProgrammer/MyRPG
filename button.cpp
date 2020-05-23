#include "button.hpp"

Button::Button()
{
	//buttonRectangle.setFillColor(sf::Color::Blue);
	buttonTexture.loadFromFile("./content/button.png");
	buttonRectangle.setTexture(&buttonTexture);
	buttonRectangle.setPosition(sf::Vector2f(208, 330));
	buttonRectangle.setSize(sf::Vector2f(85, 29));
	buttonBounds = buttonRectangle.getGlobalBounds();
}

void Button::drawButton(sf::RenderWindow& window, std::string currentLoc)
{
	if (currentLoc == "open")
	{
		buttonRectangle.setPosition(sf::Vector2f(208, 330));
		buttonBounds = buttonRectangle.getGlobalBounds();
	}

	if (currentLoc == "house")
	{
		buttonRectangle.setPosition(sf::Vector2f(15, 150));
		buttonBounds = buttonRectangle.getGlobalBounds();
	}
	window.draw(buttonRectangle);
}