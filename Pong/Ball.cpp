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

void Ball::collide(Paddle paddle)
{
	
}

void Ball::moveloop() 
{
	x += velX;
	move(velX, 0);

	y += velY;
	move(0, velY);

	if (x < 0) velX *= -1;
	else if (x > 640) velX *= -1;

	if (y < 0) velY *= -1;
	else if (y > 480) velY *= -1;
}
/*
int Ball::setVelocity()
{
	//srand(time(NULL));
	//int temp = (rand() % 2) + 1;
	//return temp;
}
*/