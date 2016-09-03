#ifndef PADDLE_H_
#define PADDLE_H_

#include <SFML/Graphics.hpp>

class Paddle : public sf::RectangleShape
{
public:
	Paddle(int playerNum);
	~Paddle();
	void moveloop();
	void doMovement(sf::Event event);
	void stopMovement(sf::Event event);
	float getX();
	float getY();
private :
	float x;
	float y = 140;
	float width;
	float height;
	int playerNum;
	bool keyUp;
	bool keyDown;
	bool arrowUp;
	bool arrowDown;
};

#endif // !PADDLE_H_