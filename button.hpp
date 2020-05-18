#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <SFML/Graphics.hpp>

class Button
{
private:
	sf::RectangleShape buttonRectangle;
	sf::Texture buttonTexture;
	sf::Vector2f buttonSize;
	sf::Text enterHouseText;

public:
	Button();
	void drawButton(sf::RenderWindow& window);
};
#endif