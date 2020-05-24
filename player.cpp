#include "player.hpp"
#include <SFML/Graphics.hpp>

Player::Player()
{
	playerModel.setSize(sf::Vector2f(50.f, 50.f));
	playerTexture.loadFromFile("./content/player.png");
	playerModel.setTexture(&playerTexture);
	playerModel.setPosition(sf::Vector2f(20.f, 420.f));
	speed = 100.f;
}

void Player::drawPlayer(sf::RenderWindow& window)
{
	window.draw(playerModel);
}

void Player::playerMovement(float& deltaTime, sf::Vector2f& currentPos)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && currentPos.x > 0)
		playerModel.move(-speed * deltaTime, 0);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && currentPos.x < 494)
		playerModel.move(speed * deltaTime, 0);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && currentPos.y > 0)
		playerModel.move(0, -speed * deltaTime);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && currentPos.y < 430)
		playerModel.move(0, speed * deltaTime);
}

void Player::getPlayerPos()
{
	playerPosition = playerModel.getPosition();
}

void Player::changePlayerPos(sf::Vector2f& newPlayerPos)
{
	playerModel.setPosition(newPlayerPos);
}