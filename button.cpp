#include "button.hpp"

Button::Button()
{
	buttonTextureNoHover.loadFromFile("./content/button.png");
	buttonTextureHover.loadFromFile("./content/buttonHover.png");

	buttonRectangle.setTexture(&buttonTextureNoHover);
	buttonRectangle.setPosition(sf::Vector2f(208.f, 330.f));
	buttonRectangle.setSize(sf::Vector2f(85.f, 29.f));
	buttonBounds = buttonRectangle.getGlobalBounds();
}

void Button::drawButton(sf::RenderWindow& window, std::string currentLoc)
{
	if (currentLoc == "open")
	{
		buttonRectangle.setPosition(sf::Vector2f(208.f, 330.f));
		buttonBounds = buttonRectangle.getGlobalBounds();
	}

	if (currentLoc == "house")
	{
		buttonRectangle.setPosition(sf::Vector2f(15.f, 150.f));
		buttonBounds = buttonRectangle.getGlobalBounds();
	}
	window.draw(buttonRectangle);
}

void Button::drawExitButton(sf::RenderWindow& window)
{
	buttonRectangle.setPosition(sf::Vector2f(500.f, 5.f));
	buttonRectangle.setSize(sf::Vector2f(40.f, 29.f));
	buttonBounds = buttonRectangle.getGlobalBounds();
	window.draw(buttonRectangle);
}

void Button::buttonNoHover()
{
	buttonRectangle.setTexture(&buttonTextureNoHover);
}
void Button::buttonHover()
{
	buttonRectangle.setTexture(&buttonTextureHover);
}