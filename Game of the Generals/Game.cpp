#include "Game.h"

Game::Game() : window(VideoMode(800, 600), "Game of the Generals")
{
	//put all initializations here
	font.loadFromFile("Media/Fonts/Pixeled.ttf");
	bgTexture.loadFromFile("Media/Textures/grass bg.jpg");
	bgSprite.setTexture(bgTexture);
	

	menuText.setFont(font);
	menuText.setCharacterSize(16);
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

	//BG AND UI RENDER
	window.draw(bgSprite);
	setGUI();

	//PIECE RENDER
	


	window.display();
}

void Game::setGUI()
{
	menuText.setString("GAME OF THE GENERALS");
	menuText.setPosition((window.getSize().x/2) - 160, 30 );
	window.draw(menuText);
}
