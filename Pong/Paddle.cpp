#include "stdafx.h"
#include "Paddle.h"
#include <iostream>

Paddle::Paddle(int playerNum) : sf::RectangleShape(sf::Vector2f(10, 200))
{
	this->playerNum = playerNum;

	if (playerNum == 1) x = 30;
	else x = 600;

	setPosition(sf::Vector2f(x, y));
}


Paddle::~Paddle()
{

}

void Paddle::doMovement(sf::Event event)
{
	if (playerNum == 1)
	{
		if (event.key.code == sf::Keyboard::W) keyUp = true, std::cout << "asd" << std::endl;
		if (event.key.code == sf::Keyboard::S) keyDown = true;
	}
	else if (playerNum == 2)
	{
		if (event.key.code == sf::Keyboard::Up) arrowUp = true;
		if (event.key.code == sf::Keyboard::Down) arrowDown = true;
	}
}

void Paddle::stopMovement(sf::Event event)
{
	if (playerNum == 1)
	{
		if (event.key.code == sf::Keyboard::W) keyUp = false;
		if (event.key.code == sf::Keyboard::S) keyDown = false;
	}
	else if (playerNum == 2)
	{
		if (event.key.code == sf::Keyboard::Up) arrowUp = false;
		if (event.key.code == sf::Keyboard::Down) arrowDown = false;
	}
}

void Paddle::moveloop()
{
	if (keyUp == 1|| arrowUp == 1) y--, move(0, -1);
	if (keyDown == 1| arrowDown == 1) y++, move(0, 1);

	if (y < 0) y = 2, setPosition(x,2);
	else if (y + 200 > 478) y = 278, setPosition(x, 278);
}

float Paddle::getX()
{
	return x;
}

float Paddle::getY()
{
	return y;
}