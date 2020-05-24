#include "door.hpp"

Door::Door()
{
	doorArea.setSize(sf::Vector2f(40.f, 45.f));
}

void Door::setDoorPosition(std::string& currentLoc)
{
	if (currentLoc == "open")
	{
		doorArea.setPosition(sf::Vector2f(210.f, 350.f));
		doorBounds = doorArea.getGlobalBounds();
	}

	if (currentLoc == "house")
	{
		doorArea.setPosition(sf::Vector2f(38.f, 190.f));
		doorBounds = doorArea.getGlobalBounds();
	}
}