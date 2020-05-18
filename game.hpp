#ifndef GAME_HPP
#define GAME_HPP

#include "bullet.hpp"
#include "button.hpp"
#include "map.hpp"
#include "player.hpp"
#include <SFML/Graphics.hpp>
#include <vector>

class Game
{
private:
	// VARIABLES
	float deltaTime;
	bool isFired;
	sf::Vector2f bulletPos;
	std::vector<Bullet> bulletVector;
	sf::Vector2f currentPlayerPos;
	sf::Vector2f mousePos;

	// OBJECTS
	sf::RenderWindow window;
	Player player;
	Map map;
	sf::Event event;
	sf::Clock deltaClock;
	sf::Time bulletTime;
	sf::Clock bulletClock;
	sf::Font font;
	sf::Text enterHouseText;
	Button enterHouseButton;

public:
	Game();
	void pollEvents();
	void update();
	void render();
	bool running();
	void createTheBullet();
	void updateTheBullet();
	void drawTheBullet();
	bool isAtTheDoor();
	void initText();
	bool mouseOnButton();
};
#endif