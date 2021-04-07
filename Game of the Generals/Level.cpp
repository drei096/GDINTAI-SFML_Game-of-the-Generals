#include "Level.h"
#include "GameObjectManager.h"
#include "Media/Pieces/FiveStarG.h"
#include "TextureManager.h"
#include "Board.h"



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
	confirmExit.initFont(font);

	FiveStarG* blackFiveStar = new FiveStarG("blackFiveStar");
	GameObjectManager::getInstance()->addObject(blackFiveStar);

	gameState = "setup";
}

void Level::createEntity(string textureKey, float xPos, float yPos)
{

}

void Level::run()
{

	Clock clock;
	Time timeSinceLast = Time::Zero;
	while (window.isOpen())
	{
		pollEvents();
		timeSinceLast += clock.restart();
		while (timeSinceLast > TimePerFrame)
		{
			timeSinceLast -= TimePerFrame;
			pollEvents();
			update(gameState,TimePerFrame);
		}
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
			(window).close();
			break;
		case Event::KeyPressed:
			if (event.key.code == Keyboard::Escape)
			{
				(window).close();
				exit(0);
				break;
			}
		case Event::MouseMoved:
			if (exitButton.isMouseHover((window)))
			{
				exitButton.setBackColor(Color::Green);
				exitButton.setTextColor(Color::Black);
			}
			else
			{
				exitButton.setBackColor(Color::Black);
				exitButton.setTextColor(Color::White);
			}
			if (readyButton.isMouseHover((window)))
			{
				readyButton.setBackColor(Color::Green);
				readyButton.setTextColor(Color::Black);
			}
			else
			{
				readyButton.setBackColor(Color::Black);
				readyButton.setTextColor(Color::White);
			}
			if (confirmExit.isMouseHover((window)))
			{
				confirmExit.setBackColor(Color::Green);
				confirmExit.setTextColor(Color::Black);
			}
			else
			{
				confirmExit.setBackColor(Color::Black);
				confirmExit.setTextColor(Color::White);
			}
			break;
		case Event::MouseButtonPressed:
			if (exitButton.isMouseHover((window)))
			{
				gameState = "hold";
			}
			if (readyButton.isMouseHover((window)))
			{
				gameState = "play";
			}
			if (confirmExit.isMouseHover((window)))
			{
				gameState = "exit";
			}
		default:
			GameObjectManager::getInstance()->processInput(event, &window);
		}
	}
}

void Level::update(string gameState, Time deltaTime)
{
	GameObjectManager::getInstance()->update(deltaTime);
	if (gameState == "exit")
	{
		(window).close();
		Game game;
		game.run();
	}
}


void Level::render(string gameState)
{
	if (gameState == "setup")
	{
		(window).clear();

		//BG AND UI RENDER
		(window).draw(bgSprite);
		setGUI();
		exitButton.renderButton(&window, "EXIT TO MENU", window.getSize().x - exitButton.getSize().x, 10);

		RectangleShape tempBarrier;
		tempBarrier.setFillColor(Color::Black);
		tempBarrier.setSize(Vector2f(800.0f,80.0f));
		tempBarrier.setPosition(810, 360);
		window.draw(tempBarrier);

		readyButton.renderButton(&window, "READY!", 810, 375);
	
		//PIECE RENDER
		GameObjectManager::getInstance()->draw(&window);
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
		GameObjectManager::getInstance()->draw(&window);
	}

	if (gameState == "hold")
	{
		//BG AND UI RENDER
		window.draw(bgSprite);
		setGUI();
		confirmExit.renderButton(&window, "EXIT!", window.getSize().x - exitButton.getSize().x, 10);

		RectangleShape tempBarrier;
		tempBarrier.setFillColor(Color::Black);
		tempBarrier.setSize(Vector2f(800.0f, 80.0f));
		tempBarrier.setPosition(810, 360);
		tempBarrier.setOutlineColor(Color::Red);
		tempBarrier.setOutlineThickness(2.5);
		window.draw(tempBarrier);

		stateIndicator.setString("You will lose all progress\n when you quit. Continue?");
		stateIndicator.setPosition(830, 370);
		window.draw(stateIndicator);

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


