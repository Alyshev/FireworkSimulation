#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <random>

using namespace sf;

class Firework
{
public:
	Firework(Vector2f position);

	Vector2f position;
	std::vector <CircleShape> circles;
	

	void update();

	
	void drawFirework(RenderWindow& window);

};

