#include "door.hpp"

Door::Door()
{
	doorArea.setSize(sf::Vector2f(40, 45));
}

void Door::setDoorPosition(std::string& currentLoc)
{
	if (currentLoc == "open")
	{
		doorArea.setPosition(sf::Vector2f(210, 350));
		doorBounds = doorArea.getGlobalBounds();
	}

	if (currentLoc == "house")
	{
		doorArea.setPosition(sf::Vector2f(10, 350));
		doorBounds = doorArea.getGlobalBounds();
	}
}