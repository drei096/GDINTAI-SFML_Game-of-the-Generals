#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include "Button.h"

using namespace std;
using namespace sf;

class Level
{
public:
	Level();
	void run();
	bool isRunning();
private:
	RenderWindow window;
	Font font;
	Text deadText;
	Texture bgTexture;
	Sprite bgSprite;
	Button exitButton;
	string gameState;
private:
	void pollEvents();
	void update();
	void render(string gameState);
	void setGUI(float logoPosX, float logoPosY);
};

