#include "map.hpp"
#include <SFML/Graphics.hpp>

Map::Map()
{
	mapTexture.loadFromFile("./content/map.jpg");
	mapModel.setTexture(mapTexture);
}

void Map::drawMap(sf::RenderWindow& window)
{
	window.draw(mapModel);
}

void Map::changeMap()
{
	mapTexture.loadFromFile("./content/house.png");
}