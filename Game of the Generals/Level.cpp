#include "Level.h"

Level::Level() : window(VideoMode(1280, 720), "Game of the Generals")
{
	//put all initializations here
	font.loadFromFile("Media/Fonts/Pixeled.ttf");
	bgTexture.loadFromFile("Media/Textures/grass bg.jpg");
	bgSprite.setTexture(bgTexture);


	deadText.setFont(font);
	deadText.setCharacterSize(16);
}

void Level::run()
{
	while (window.isOpen())
	{
		pollEvents();
		update();
		render();
	}
}

bool Level::isRunning()
{
	while (window.isOpen())
	{
		return true;
	}
	return false;
}

void Level::pollEvents()
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

void Level::update()
{
}

void Level::render()
{
	window.clear();

	//BG AND UI RENDER
	window.draw(bgSprite);
	setGUI();

	//PIECE RENDER



	window.display();
}

void Level::setGUI()
{
	deadText.setString("DEAD GENERALS");
	deadText.setPosition(1000, 600);
	window.draw(deadText);
}
