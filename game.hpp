#ifndef GAME_HPP
#define GAME_HPP

#include "bullet.hpp"
#include "button.hpp"
#include "door.hpp"
#include "map.hpp"
#include "player.hpp"
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

class Game
{
private:
	// VARIABLES
	float deltaTime;
	bool isFired;
	bool isClicked;
	sf::Vector2f bulletPos;
	std::vector<Bullet> bulletVector;
	sf::Vector2f currentPlayerPos;
	sf::Vector2f mousePos;
	std::string currentLoc;
	sf::Vector2f newPlayerPos;

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
	sf::Text exitHouseText;
	sf::Text exitGameText;
	Button houseButton;
	Button exitGameButton;
	Door door;
	sf::Texture cursorTexture;
	sf::Sprite cursor;

public:
	Game();
	void pollEvents();
	void update();
	void render();
	bool running();
	void createTheBullet();
	void updateTheBullet();
	void drawTheBullet();
	bool isAtTheDoor(Door& door);
	void initText();
	bool mouseOnButton(Button& button);
	void currentLocation();
	void changePlayerPos();
	void changeLocation(std::string newLocation);
	void mouseToCenter();
	void mouseHovering();
	bool showCursor();
};
#endif