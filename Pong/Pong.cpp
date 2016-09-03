// Pong.cpp : Defines the entry point for the console application.
//

#include <SFML/Graphics.hpp>
#include <iostream>
#include <chrono>

#include "stdafx.h"
#include "Paddle.h"
#include "Ball.h"

using namespace std;

static int WIDTH = 640;	
static int HEIGHT = 480;

int main() {

	sf::RenderWindow window(sf::VideoMode(640, 480), "Pong");
	window.setFramerateLimit(60);

	Paddle paddle1(1);
	Paddle paddle2(2);
	Ball ball;
	
	while (window.isOpen()) {

		sf::Event event;
		while (window.pollEvent(event)) {
			switch (event.type)
			{

			case sf::Event::Closed:
				window.close();
				break;

			case sf::Event::Resized:
				cout << event.size.width << endl;
				cout << event.size.height << endl;
				break;

			case sf::Event::KeyPressed:
				paddle1.doMovement(event);
				paddle2.doMovement(event);
				break;
			case sf::Event::KeyReleased:
				paddle1.stopMovement(event);
				paddle2.stopMovement(event);
				break;
			}
		}

		paddle1.moveloop();
		paddle2.moveloop();

		if (ball.gameOn) ball.moveloop();

		ball.collide(paddle1, 1);
		ball.collide(paddle2, 2);

		window.clear();
		window.draw(paddle1);
		window.draw(paddle2);
		window.draw(ball);
		window.display();
	}
}