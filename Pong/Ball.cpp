#include "stdafx.h"
#include "Ball.h"
#include <iostream>

Ball::Ball() : sf::CircleShape(100)

{
	setPosition(sf::Vector2f(320, 240));
}

Ball::~Ball()
{
}

void Ball::collide(Paddle paddle)
{

}

void Ball::moveloop() 
{
	x += velX;
	//move(x, 0);

	if (x > 640) velX *= -1;
	if (x < 0) velX *= -1;
	//std::cout << x << std::endl;
	if (move1) x-= 0.5, move(x, 0);

}

int Ball::setVelocity()
{
	srand(time(NULL));
	int temp = (rand() % 2) + 1;
	return temp;
}

void Ball::tempMove(sf::Event event)
{
	if (event.key.code == sf::Keyboard::A)
	{
		move1 = true;
	}
}

void Ball::stopTempMove(sf::Event event)
{
	if (event.key.code == sf::Keyboard::A)
	{
		move1 = false;
	}
}