#pragma once

#include<iostream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class Game
{
private:
	//Variables
	//Window
	sf::RenderWindow* window;
	sf::Event ev;
	sf::VideoMode videoMode;

	//Game objects
	sf::RectangleShape enemy;


	//Private Functions
	void initVariables();
	void initWindow();
	void initEnemies();

public:

	Game();
	virtual ~Game();

	//Accessors
	const bool running() const;

	// Functions
	void pollEvents();
	void update();
	void render();

};


