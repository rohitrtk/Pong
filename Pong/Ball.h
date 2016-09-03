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
	void collide(Paddle paddle);
	void moveloop();
	bool gameOn = true;
private:
	float x = 320;
	float y = 240;
	float velX = 0.4;
	float velY = 0.4;
	const float radius = 150;
	int setVelocity();
};

#endif // !BALL_H_