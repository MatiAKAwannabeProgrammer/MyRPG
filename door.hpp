#ifndef DOOR_HPP
#define DOOR_HPP

#include <SFML/Graphics.hpp>

class Door
{
private:
	sf::RectangleShape doorArea;

public:
	Door();
	void setDoorPosition(std::string& currentLoc);
	sf::FloatRect doorBounds;
};
#endif