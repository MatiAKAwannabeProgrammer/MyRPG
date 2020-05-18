#include "bullet.hpp"
#include <iostream>

Bullet::Bullet(sf::Vector2f &playerPosition)
{
	bulletModel.setSize(sf::Vector2f(10, 10));
	bulletTexture.loadFromFile("./content/bullet.png");
	bulletModel.setTexture(&bulletTexture);
	bulletModel.setPosition(playerPosition.x +40, playerPosition.y + 15);
	speed = 300.f;
}

void Bullet::drawBullet(sf::RenderWindow &window)
{
	window.draw(bulletModel);
}

void Bullet::bulletMovement(float &deltaTime)
{
	bulletModel.move(speed * deltaTime, 0);
}

void Bullet::getBulletPos()
{
	bulletPosition = bulletModel.getPosition();
}