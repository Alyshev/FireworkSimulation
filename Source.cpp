#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Firework.h"

using namespace sf;



int main()
{
	RenderWindow window(VideoMode(800, 800), "FIRE", Style::Default);
	CircleShape shape(100.f);
	shape.setFillColor(Color::Green);
	std::vector <Firework> vect;

	
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
				vect.emplace_back(window.mapPixelToCoords(Mouse::getPosition(window)));
			}
		}

		window.clear();



		window.draw(shape);

		for (int i = 0; i < vect.size(); i++)
		{
			vect[i].update();
			vect[i].drawFirework(window);
		}

		window.display();
	}

	return 0;
}