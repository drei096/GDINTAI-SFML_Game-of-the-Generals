#include "Game.h"

Game::Game() : window(VideoMode(800, 600), "Game of the Generals")
{
	//put all initializations here
	font.loadFromFile("Media/Fonts/Pixeled.ttf");
	bgTexture.loadFromFile("Media/Textures/grass bg.jpg");
	bgSprite.setTexture(bgTexture);
	logoTexture.loadFromFile("Media/Textures/game_logo.png");
	logoSprite.setTexture(logoTexture);
	

	menuText.setFont(font);
	menuText.setCharacterSize(16);

	exitButton.initFont(font);
	playButton.initFont(font);
	mechanicsButton.initFont(font);
	backButton.initFont(font);

	gameState = "MainMenu";
}

void Game::run()
{
	while (window.isOpen())
	{
		pollEvents();
		update();
		render(gameState);
	}
}

bool Game::isRunning()
{
	while (window.isOpen())
	{
		return true;
	}
	return false;
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
			if (playButton.isMouseHover(window))
			{
				playButton.setBackColor(Color::Green);
				playButton.setTextColor(Color::Black);
			}
			else
			{
				playButton.setBackColor(Color::Black);
				playButton.setTextColor(Color::White);
			}
			/*
			if (mechanicsButton.isMouseHover(window))
			{
				mechanicsButton.setBackColor(Color::Green);
				mechanicsButton.setTextColor(Color::Black);
			}
			else
			{
				mechanicsButton.setBackColor(Color::Black);
				mechanicsButton.setTextColor(Color::White);
			}
			*/
			if (backButton.isMouseHover(window))
			{
				backButton.setBackColor(Color::Green);
				backButton.setTextColor(Color::Black);
			}
			else
			{
				backButton.setBackColor(Color::Black);
				backButton.setTextColor(Color::White);
			}
			break;
		case Event::MouseButtonPressed:
			if (exitButton.isMouseHover(window))
			{
				exit(0);
			}
			if (playButton.isMouseHover(window))
			{
				window.close();
			}
			/*
			if (mechanicsButton.isMouseHover(window))
			{
				gameState = "mechs";
			}
			*/
			if (backButton.isMouseHover(window))
			{
				gameState = "MainMenu";
			}
			break;
		}
	}
}

void Game::update()
{
}

void Game::render(string gameState)
{
	if (gameState == "MainMenu")
	{
		window.clear();

		//BG AND UI RENDER
		window.draw(bgSprite);
		setGUI(0, 100);
		//BUTTON RENDERS
		playButton.renderButton(&window, "PLAY!", 550, 150);
		//mechanicsButton.renderButton(&window, "HOW TO PLAY", 550, 250);
		exitButton.renderButton(&window, "EXIT!", 550, 350);
		
	}
	
	/*
	if (gameState == "mechs")
	{
		//BG AND UI RENDER
		window.clear();
		window.draw(bgSprite);
		setGUI(150,0);
		//BUTTON RENDERS
		backButton.renderButton(&window, "BACK TO MENU", 10, 550);
		
	}
	*/

	//PIECE RENDER
	


	window.display();
}

void Game::setGUI(float logoPosX, float logoPosY)
{
	logoSprite.setPosition(logoPosX, logoPosY);
	window.draw(logoSprite);
	//menuText.setString("GAME OF THE GENERALS");
	//menuText.setPosition((window.getSize().x/2) - 160, 30 );
	//window.draw(menuText);
}
