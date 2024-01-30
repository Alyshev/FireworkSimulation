#include "Firework.h"





Firework::Firework(Vector2f position)
{
	this->position = position;
	circles = std::vector <CircleShape>(100);

	for (int i = 0; i < circles.size(); i++)
	{
		circles[i].setPosition(this->position);
		circles[i].setRadius(1);
		circles[i].setFillColor(Color(rand() % 255, rand() % 255, rand() % 255));
	}
}


void Firework::update()
{
	for (int i = 0; i < circles.size(); i++)
	{
		circles[i].move(rand() % 3 - 1, rand() % 3 - 1);
	}
}



void Firework::drawFirework(RenderWindow& window)
{
	for (int i = 0; i < circles.size(); i++)
	{
		window.draw(circles[i]);
	}
}
