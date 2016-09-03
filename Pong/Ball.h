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
	void tempMove(sf::Event);
	void stopTempMove(sf::Event);
private:
	float x = 320;
	float y = 240;
	int velX = 1;
	int velY;
	const float radius = 150;
	int setVelocity();
	bool move1 = false;
};

#endif // !BALL_H_