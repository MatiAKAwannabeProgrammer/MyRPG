#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics.hpp>

class Player
{
private:
	sf::Texture playerTexture;
	sf::RectangleShape playerModel;
	float speed;

public:
	Player();
	void drawPlayer(sf::RenderWindow& window);
	void playerMovement(float& deltaTime, sf::Vector2f& currentPos);
	void getPlayerPos();
	sf::Vector2f playerPosition;
	void changePlayerPos(sf::Vector2f& newPlayerPos);
};
#endif