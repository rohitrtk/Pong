#ifndef BALL_H_
#define BALL_H_

#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Paddle.h"

class Ball : public sf::CircleShape
{
public:
	Ball();
	~Ball();
	void collide(Paddle paddle, int playerNum);
	void moveloop();
	bool gameOn = true;
private:
	float x = 320;
	float y = 240;
	float velX = 5;
	float velY = 10;
	const float radius = 150;
	bool changeVel = true;
	bool negativeVel;
};

#endif // !BALL_H_