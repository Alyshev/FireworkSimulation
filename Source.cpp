#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>
#include "Firework.h"

using namespace sf;



int main()
{
	RenderWindow window(VideoMode(800, 800), "FIRE", Style::Default);

	std::vector <Firework> vect(1000);
	int index = 999;

	const int FPS = 200;
	Clock frameTime;




	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
			if (Keyboard::isKeyPressed(Keyboard::Escape))
				window.close();
			if (event.type == Event::MouseButtonPressed)
			{
				vect[index] = Firework(window.mapPixelToCoords(Mouse::getPosition(window)), window);
				index--;
			}
		}

		if (frameTime.getElapsedTime().asMilliseconds() > 1000 / FPS)
		{
			frameTime.restart();

			window.clear(Color::Black);

			for (int i = vect.size() - 1; i > 0; i--)
			{
				bool isDead = vect[i].update(window);
				if (isDead)
				{
					vect.pop_back();
				}
				else
				{
					vect[i].drawFirework(window);
				}
			}

			window.display();
		}
	}

	return 0;
}