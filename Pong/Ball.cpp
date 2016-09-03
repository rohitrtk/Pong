#include "stdafx.h"
#include "Ball.h"
#include <iostream>

Ball::Ball() : sf::CircleShape(10)

{
	setPosition(sf::Vector2f(320, 240));
}

Ball::~Ball()
{
}

void Ball::collide(Paddle paddle, int playerNum)
{
	sf::Vector2f point;
	char c;

	if (playerNum == 1) point = sf::Vector2f(x - 5, y - 5);
	else if (playerNum == 2) point = sf::Vector2f(x + 10, y + 10);

	if (paddle.getGlobalBounds().contains(point)) 
	{
		velX *= -1;
		velY *= -1;
		std::cout << "HIT!" << std::endl;
	}
}

void Ball::moveloop() 
{
	x += velX;
	move(velX, 0);

	y += velY;
	move(0, velY);

	if (x < 0 || x > 640)
	{
		x = 320;
		velX *= -1;
		setPosition(sf::Vector2f(x, y));
	}

	if (y < 0) velY *= -1;
	else if (y > 480) velY *= -1;
}