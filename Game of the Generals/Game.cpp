#include "Game.h"

Game::Game() : window(VideoMode(1280, 720), "Game of the Generals")
{
	//put all initializations here
	font.loadFromFile("Media/Fonts/Pixeled.ttf");
	deadText.setFont(font);
	deadText.setCharacterSize(16);
}

void Game::run()
{
	while (window.isOpen())
	{
		pollEvents();
		update();
		render();
	}
}

void Game::pollEvents()
{
	Event event;
	while (window.pollEvent(event))
	{
		switch (event.type)
		{
		case Event::Closed:
			window.close();
			break;
		case Event::KeyPressed:
			if (event.key.code == Keyboard::Escape)
			{
				window.close();
				exit(0);
				break;
			}
		}
	}
}

void Game::update()
{
}

void Game::render()
{
	window.clear();

	setGUI();

	window.display();
}

void Game::setGUI()
{
	deadText.setString("DEAD");
	deadText.setPosition(5, 10);
	window.draw(deadText);
}
