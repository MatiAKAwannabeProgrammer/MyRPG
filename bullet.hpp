#ifndef BULLET_HPP
#define BULLET_HPP

#include <SFML/Graphics.hpp>

class Bullet
{
private:
	sf::RectangleShape bulletModel;
	sf::Texture bulletTexture;
	float speed;

public:
	Bullet(sf::Vector2f &playerPosition);
	void drawBullet(sf::RenderWindow &window);
	void bulletMovement(float &deltaTime);
	void getBulletPos();
	sf::Vector2f bulletPosition;

};
#endif