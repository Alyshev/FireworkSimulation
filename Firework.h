#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <random>
#include <cmath>

using namespace sf;


class Firework
{
	int stage;

	Vector2f center;
	std::vector <std::vector <CircleShape>> circles;
	std::vector <double> speed;
	std::vector <double> direction;
	std::vector <double> slowdown;

	CircleShape fire;
	float speedFire;

	Clock time;
	Clock endTime;
	bool endFlag;

	bool isActive;



public: 
	Firework(Vector2f position, RenderWindow& window);
	Firework();
	~Firework();


	bool update(RenderWindow& window);


	void drawFirework(RenderWindow& window);


	//void startSound(Sound& sound);


};

