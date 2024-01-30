#include "Firework.h"





Firework::Firework(Vector2f position, RenderWindow& window)
{
	this->center = position;

	circles = std::vector <CircleShape>(100);
	for (int i = 0; i < circles.size(); i++)
	{
		circles[i].setPosition(this->center);
		circles[i].setRadius(1);
		circles[i].setFillColor(Color(rand() % 255, rand() % 255, rand() % 255));
	}

	fire.setFillColor(Color::Yellow);
	fire.setRadius(4);
	fire.setOrigin(4, 4);
	fire.setPosition(rand() % window.getSize().x, window.getSize().y);
	stage = 1;
	speedFire = 10;
}


void Firework::update(RenderWindow& window)
{
	if (stage == 1)
	{
		Vector2f vect = center - fire.getPosition();
		float length = sqrt(vect.x * vect.x + vect.y * vect.y);
		float div = length / speedFire;
		fire.move(vect.x / div, vect.y / div);

		if (fire.getPosition().y < center.y)
		{
			stage = 2;
		}
	}
	else if (stage == 2)
	{
		for (int i = 0; i < circles.size(); i++)
		{
			circles[i].move(rand() % 3 - 1, rand() % 3 - 1);
		}
	}
}



void Firework::drawFirework(RenderWindow& window)
{
	if (stage == 1)
	{
		window.draw(fire);
	}
	else if (stage == 2)
	{
		for (int i = 0; i < circles.size(); i++)
		{
			window.draw(circles[i]);
		}
	}
}
