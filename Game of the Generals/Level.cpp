#include "Level.h"

Level::Level() : window(VideoMode(1280, 720), "Game of the Generals")
{
	//put all initializations here
	font.loadFromFile("Media/Fonts/Pixeled.ttf");
	bgTexture.loadFromFile("Media/Textures/grass bg.jpg");
	bgSprite.setTexture(bgTexture);


	deadText.setFont(font);
	deadText.setCharacterSize(16);

	gameState = "setup";
}

void Level::run()
{
	while (window.isOpen())
	{
		pollEvents();
		update();
		render(gameState);
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

void Level::render(string gameState)
{
	if (gameState == "setup")
	{
		window.clear();

		//BG AND UI RENDER
		window.draw(bgSprite);
		setGUI(1000, 600);

		//PIECE RENDER
	}
	



	window.display();
}

void Level::setGUI(float logoPosX, float logoPosY)
{
	deadText.setString("DEAD GENERALS");
	deadText.setPosition(logoPosX, logoPosY);
	window.draw(deadText);
}
