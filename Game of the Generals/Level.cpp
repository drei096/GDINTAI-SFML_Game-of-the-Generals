#include "Level.h"

Level::Level() : window(VideoMode(1280, 720), "Game of the Generals")
{
	//put all initializations here
	font.loadFromFile("Media/Fonts/Pixeled.ttf");
	bgTexture.loadFromFile("Media/Textures/grass bg.jpg");
	bgSprite.setTexture(bgTexture);
	


	deadTextP1.setFont(font);
	deadTextP1.setCharacterSize(16);
	deadTextP2.setFont(font);
	deadTextP2.setCharacterSize(16);
	stateIndicator.setFont(font);
	stateIndicator.setCharacterSize(16);

	exitButton.initFont(font);
	readyButton.initFont(font);

	gameState = "setup";
}

void Level::createEntity(string textureKey, float xPos, float yPos)
{

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
		case Event::MouseMoved:
			if (exitButton.isMouseHover(window))
			{
				exitButton.setBackColor(Color::Green);
				exitButton.setTextColor(Color::Black);
			}
			else
			{
				exitButton.setBackColor(Color::Black);
				exitButton.setTextColor(Color::White);
			}
			if (readyButton.isMouseHover(window))
			{
				readyButton.setBackColor(Color::Green);
				readyButton.setTextColor(Color::Black);
			}
			else
			{
				readyButton.setBackColor(Color::Black);
				readyButton.setTextColor(Color::White);
			}
			break;
		case Event::MouseButtonPressed:
			if (exitButton.isMouseHover(window))
			{
				window.close();
				Game game;
				game.run();
			}
			if (readyButton.isMouseHover(window))
			{
				gameState = "play";
			}
			break;
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
		setGUI();
		exitButton.renderButton(&window, "EXIT TO MENU", window.getSize().x - exitButton.getSize().x, 10);

		RectangleShape tempBarrier;
		tempBarrier.setFillColor(Color::Black);
		tempBarrier.setSize(Vector2f(800.0f,80.0f));
		tempBarrier.setPosition(810, 360);
		window.draw(tempBarrier);

		readyButton.renderButton(&window, "READY!", 810, 375);
	
		//PIECE RENDER
	}
	
	if (gameState == "play")
	{
		window.clear();

		//BG AND UI RENDER
		window.draw(bgSprite);
		setGUI();
		exitButton.renderButton(&window, "EXIT TO MENU", window.getSize().x - exitButton.getSize().x, 10);

		RectangleShape tempBarrier;
		tempBarrier.setFillColor(Color::Black);
		tempBarrier.setSize(Vector2f(800.0f, 80.0f));
		tempBarrier.setPosition(810, 360);
		tempBarrier.setOutlineColor(Color::Red);
		tempBarrier.setOutlineThickness(2.5);
		window.draw(tempBarrier);

		//PIECE RENDER
	}



	window.display();
}

void Level::setGUI()
{
	deadTextP1.setString("DEAD GENERALS P2");
	deadTextP1.setPosition(900,300);
	window.draw(deadTextP1);

	deadTextP2.setString("DEAD GENERALS P1");
	deadTextP2.setPosition(900, 490);
	window.draw(deadTextP2);
}


