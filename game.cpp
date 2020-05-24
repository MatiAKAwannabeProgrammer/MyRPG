#include "game.hpp"

Game::Game()
{
	window.create(sf::VideoMode(544, 480), "Best RPG EU");
	isFired = false;
	isClicked = true;
	window.setFramerateLimit(60);
	window.setKeyRepeatEnabled(true);
	initText();
	currentLoc = "open";
	window.setMouseCursorGrabbed(true);
	window.setMouseCursorVisible(false);
	mouseToCenter();
	cursorTexture.loadFromFile("./content/cursor.png");
	cursor.setTexture(cursorTexture);
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

	// If the player is at the door, register mouse clicks.
	if (isAtTheDoor(door))
	{
		if (event.type == event.MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left && mouseOnButton(houseButton) == true && currentLoc == "open")
		{
			event.type = event.MouseButtonReleased;
			map.changeMap(currentLoc);
			player.changePlayerPos(newPlayerPos);
			currentLoc = "house";
		}

		if (event.type == event.MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left && mouseOnButton(houseButton) == true && currentLoc == "house")
		{
			event.type = event.MouseButtonReleased;
			map.changeMap(currentLoc);
			player.changePlayerPos(newPlayerPos);
			currentLoc = "open";
		}
	}

	// Exit game button.
	if (event.type == event.MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left && mouseOnButton(exitGameButton) == true)
		window.close();
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
		createTheBullet();

	updateTheBullet();
	isFired = false;

	// Update the mouse position.
	mousePos = sf::Vector2f(sf::Mouse::getPosition(window));

	// Changing the color of the button.
	mouseHovering();
	cursor.setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)));
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
	exitGameButton.drawExitButton(window);
	window.draw(exitGameText);
	showCursor();

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
			bulletVector.erase(bulletVector.begin() + i);
	}
}

void Game::drawTheBullet()
{
	// Display each bullet.
	for (unsigned int i = 0; i < bulletVector.size(); i++)
		bulletVector[i].drawBullet(window);
}

bool Game::isAtTheDoor(Door& door)
{
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
	enterHouseText.setPosition(sf::Vector2f(210.f, 337.f));
	enterHouseText.setFont(font);
	enterHouseText.setFillColor(sf::Color(65, 53, 53));
	enterHouseText.setCharacterSize(12);

	//ExitHouseText
	exitHouseText.setString("Exit the house");
	exitHouseText.setPosition(sf::Vector2f(20.f, 157.f));
	exitHouseText.setFont(font);
	exitHouseText.setFillColor(sf::Color(65, 53, 53));
	exitHouseText.setCharacterSize(12);

	// exitGameButton
	exitGameText.setString("Exit");
	exitGameText.setPosition(sf::Vector2f(510.f, 9.f));
	exitGameText.setFont(font);
	exitGameText.setFillColor(sf::Color(65, 53, 53));
	exitGameText.setCharacterSize(12);
}

bool Game::mouseOnButton(Button& button)
{
	if (button.buttonBounds.contains(mousePos))
		return true;

	else
		return false;
}

void Game::currentLocation()
{
	// Check the current location.
	if (currentLoc == "open")
	{
		door.setDoorPosition(currentLoc);
		if (isAtTheDoor(door))
		{
			houseButton.drawButton(window, currentLoc);
			window.draw(enterHouseText);
			newPlayerPos = sf::Vector2f(40.f, 195.f);
		}
	}

	if (currentLoc == "house")
	{
		door.setDoorPosition(currentLoc);
		if (isAtTheDoor(door))
		{
			houseButton.drawButton(window, currentLoc);
			window.draw(exitHouseText);
			newPlayerPos = sf::Vector2f(225.f, 375.f);
		}
	}
}

void Game::mouseToCenter()
{
	sf::Mouse::setPosition(sf::Vector2i(window.getSize().x / 2, window.getSize().y / 2), window);
}

void Game::mouseHovering()
{
	// Checking if cursor is hovering on the specific buttons.
	if (mouseOnButton(houseButton))
		houseButton.buttonHover();
	if (!mouseOnButton(houseButton))
		houseButton.buttonNoHover();

	if (mouseOnButton(exitGameButton))
		exitGameButton.buttonHover();
	if (!mouseOnButton(exitGameButton))
		exitGameButton.buttonNoHover();
}

bool Game::showCursor()
{
	if (isAtTheDoor(door))
	{
		window.draw(cursor);
		return true;
	}
	else
	{
		mouseToCenter();
		return false;
	}
}