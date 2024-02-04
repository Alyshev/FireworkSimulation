#include "Firework.h"





Firework::Firework(Vector2f position, RenderWindow& window)
{
	this->center = position;




	circles = std::vector <std::vector <CircleShape>>(100);
	for (int i = 0; i < circles.size(); i++)
	{
		circles[i] = std::vector<CircleShape>(30);
	}
	for (int i = 0; i < circles.size(); i++)
	{
		for (int j = 0; j < circles[i].size(); j++)
		{
			circles[i][j].setPosition(this->center);
			circles[i][j].setRadius(1);
			circles[i][j].setFillColor(Color(rand() % 255, rand() % 255, rand() % 255));
		}
	}

	speed = std::vector <double>(30);
	for (int i = 0; i < speed.size(); i++)
	{
		speed[i] = i * 4;
	}
	slowdown = std::vector <double>(30);
	for (int i = 0; i < slowdown.size(); i++)
	{
		slowdown[i] = i * 4;
	}

	direction = std::vector <double>(100);
	for (int i = 0; i < direction.size(); i++)
	{
		direction[i] = (360.0 / direction.size()) * i;
	}

	

	fire.setFillColor(Color(200, 200, 200, 255));
	fire.setRadius(2);
	fire.setOrigin(2, 2);
	fire.setPosition(rand() % window.getSize().x, window.getSize().y);


	stage = 1;
	speedFire = 500;


	time.restart();
	endFlag == false;

	isActive = true;
}

Firework::Firework()
{
	isActive = false;
}

Firework::~Firework()
{
}


bool Firework::update(RenderWindow& window)
{
	//SoundBuffer buffer;
	//buffer.loadFromFile("bah.mp3");
	//Sound sound;
	//sound.setBuffer(buffer);
	if (isActive)
	{
		double currentTime = time.restart().asSeconds();

		if (stage == 1)
		{
			Vector2f vect = center - fire.getPosition();
			float length = sqrt(vect.x * vect.x + vect.y * vect.y);
			float div = length / (speedFire * currentTime);
			fire.move(vect.x / div, vect.y / div);


			if (fire.getPosition().y < center.y)
			{
				stage = 2;

				//startSound(sound);
			}
		}
		else if (stage == 2)
		{
			for (int i = 0; i < circles.size(); i++)
			{
				for (int j = 0; j < circles[i].size(); j++)
				{
					float y = sin(direction[i]) * (speed[j] * currentTime);
					float x = cos(direction[i]) * (speed[j] * currentTime);
					circles[i][j].move(x, y);
				}
			}
			for (int i = 0; i < speed.size(); i++)
			{
				speed[i] -= (slowdown[i] * currentTime);
			}
			if (speed[speed.size() - 1] <= 10)
			{
				stage = 3;
				endTime.restart();
				endFlag = true;
			}
		}
		else if (stage == 3)
		{
			for (int i = 0; i < circles.size(); i++)
			{
				for (int j = 0; j < circles[i].size(); j++)
				{
					float y = sin(direction[i]) * (speed[j] * currentTime) + (10 * currentTime);
					float x = cos(direction[i]) * (speed[j] * currentTime);
					circles[i][j].move(x, y);
					if (rand() % 10 == 0)
					{
						circles[i][j].setFillColor(Color(0, 0, 0));
					}
				}
			}
		}

		if (endFlag && endTime.getElapsedTime().asMilliseconds() > 5000)
		{
			return true;
		}
	}
	return false;
}



void Firework::drawFirework(RenderWindow& window)
{
	if (isActive)
	{
		if (stage == 1)
		{
			CircleShape cs = fire;
			Vector2f vect = center - fire.getPosition();
			float length = sqrt(vect.x * vect.x + vect.y * vect.y);
			float div = -length / 3;

			for (int i = 0; i < 25; i++)
			{
				cs.move(vect.x / div, vect.y / div);
				cs.setFillColor(Color(cs.getFillColor().r, cs.getFillColor().g-6, cs.getFillColor().b-10,
					cs.getFillColor().a - 10));
				window.draw(cs);
			}
		}
		else if (stage == 2 || stage == 3)
		{
			for (int i = 0; i < circles.size(); i++)
			{
				for (int j = 0; j < circles[i].size(); j++)
				{
					window.draw(circles[i][j]);
				}
			}
		}
	}
}

//void Firework::startSound(Sound& sound)
//{
//	if (stage == 1)
//	{
//		sound.play();
//	}
//	else
//	{
//		sound.play();
//	}
//}
