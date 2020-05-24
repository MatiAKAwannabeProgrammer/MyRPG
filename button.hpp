#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <SFML/Graphics.hpp>

class Button
{
private:
	sf::RectangleShape buttonRectangle;
	sf::Texture buttonTextureNoHover;
	sf::Texture buttonTextureHover;

public:
	Button();
	void drawButton(sf::RenderWindow& window, std::string currentLoc);
	void drawExitButton(sf::RenderWindow& window);
	void buttonNoHover();
	void buttonHover();
	sf::FloatRect buttonBounds;
};
#endif