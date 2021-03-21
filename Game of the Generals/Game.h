#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include "Button.h"

using namespace std;
using namespace sf;

class Game
{
public:
	Game();
	void run();
	bool isRunning();
private:
	RenderWindow window;
	Font font;
	Text menuText;
	Texture bgTexture,logoTexture;
	Sprite bgSprite,logoSprite;
	string gameState;
	Button exitButton,playButton,mechanicsButton, backButton;
private:
	void pollEvents();
	void update();
	void render(string gameState);
	void setGUI(float logoPosX, float logoPosY);
};
	
