#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <random>
#include <cmath>

using namespace sf;

class Firework
{
	int stage;

	Vector2f center;
	std::vector <CircleShape> circles;

	CircleShape fire;
	float speedFire;
public: 
	Firework(Vector2f position, RenderWindow& window);



	void update(RenderWindow& window);


	void drawFirework(RenderWindow& window);

};

