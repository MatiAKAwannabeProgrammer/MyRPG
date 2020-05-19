#include "game.hpp"

Game::Game()
{
	window.create(sf::VideoMode(544, 480), "Best RPG EU");
	isFired = false;
	window.setFramerateLimit(60);
	window.setKeyRepeatEnabled(true);
	initText();
	currentLoc = "open";
}

void Game::pollEvents()
{
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();
	}

	// If space is pressed, fire every 200 milliseconds.
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && bulletTime.asMilliseconds() >= 200)
	{
		bulletClock.restart();
		isFired = true;
	}

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && mouseOnButton() == true)
	{
		map.changeMap();
		currentLoc = "house";
	}
}

void Game::update()
{
	// Start the timers.
	deltaTime = deltaClock.restart().asSeconds();
	bulletTime = bulletClock.getElapsedTime();

	// Update and initialize the player position.
	player.getPlayerPos();
	currentPlayerPos = player.playerPosition;
	player.playerMovement(deltaTime, currentPlayerPos);

	if (isFired)
	{
		createTheBullet();
	}

	updateTheBullet();
	isFired = false;

	// Update the mouse position.
	mousePos = sf::Vector2f(sf::Mouse::getPosition(window));
}

void Game::render()
{
	// Clear the screen.
	window.clear();

	// Draw the objects.
	map.drawMap(window);
	player.drawPlayer(window);
	drawTheBullet();
	currentLocation();

	// Display the picture.
	window.display();
}

bool Game::running()
{
	return window.isOpen();
}

void Game::createTheBullet()
{
	//Creating a bullet
	Bullet* bullet = new Bullet(currentPlayerPos);
	bulletVector.push_back(*bullet);

	// Calling the Bullet member functions for each bullet.
	for (unsigned int i = 0; i < bulletVector.size(); i++)
	{
		bulletVector[i].bulletMovement(deltaTime);
		bulletVector[i].getBulletPos();
	}
}

void Game::updateTheBullet()
{
	//Updating each bullet in every frame.
	for (unsigned int i = 0; i < bulletVector.size(); i++)
	{
		bulletVector[i].bulletMovement(deltaTime);
		bulletVector[i].getBulletPos();

		//If the bullet reaches the end of the screen - delete it.
		if (bulletVector[i].bulletPosition.x > 544)
		{
			bulletVector.erase(bulletVector.begin() + i);
		}
	}
}

void Game::drawTheBullet()
{
	// Display each bullet.
	for (unsigned int i = 0; i < bulletVector.size(); i++)
	{
		bulletVector[i].drawBullet(window);
	}
}

bool Game::isAtTheDoor(Door& door)
{
	//if (currentPlayerPos.x >= 210 && currentPlayerPos.x <= 250 && currentPlayerPos.y >= 350 && currentPlayerPos.y <= 395)
	if (door.doorBounds.contains(currentPlayerPos))
		return true;

	else
		return false;
}

void Game::initText()
{
	font.loadFromFile("./content/arial_narrow_7.ttf");

	// EnterHouseText button.
	enterHouseText.setString("Enter the house");
	enterHouseText.setPosition(sf::Vector2f(210, 337));
	enterHouseText.setFont(font);
	enterHouseText.setFillColor(sf::Color(65, 53, 53));
	enterHouseText.setCharacterSize(12);

	//ExitHouseText
	exitHouseText.setString("Enter the house");
	exitHouseText.setPosition(sf::Vector2f(210, 337));
	exitHouseText.setFont(font);
	exitHouseText.setFillColor(sf::Color(65, 53, 53));
	exitHouseText.setCharacterSize(12);
}

bool Game::mouseOnButton()
{
	if (houseButton.buttonBounds.contains(mousePos))
		return true;

	else
		return false;
}

void Game::currentLocation()
{
	// Check the current localtion.
	if (currentLoc == "open")
	{
		door.setDoorPosition(currentLoc);
		if (isAtTheDoor(door))
		{
			houseButton.drawButton(window);
			window.draw(enterHouseText);
		}
	}

	if (currentLoc == "house")
	{
		door.setDoorPosition(currentLoc);
		if (isAtTheDoor(door))
		{
			houseButton.drawButton(window);
			window.draw(exitHouseText);
		}
	}
}