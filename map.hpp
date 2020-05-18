#ifndef MAP_HPP
#define MAP_HPP

#include <SFML/Graphics.hpp>

class Map
{
private:
	sf::Sprite mapModel;
	sf::Texture mapTexture;

public:
	Map();
	void drawMap(sf::RenderWindow &window);

};
#endif