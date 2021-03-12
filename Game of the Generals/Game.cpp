#include "Game.h"

Game::Game() : window(VideoMode(1024, 768), "Game of the Generals")
{
	
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

	window.display();
}
