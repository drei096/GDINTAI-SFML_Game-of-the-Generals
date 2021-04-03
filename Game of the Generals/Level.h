#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include "Button.h"
#include "Game.h"
#include "Entity.h"

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
	Text deadTextP1, deadTextP2, stateIndicator;
	Texture bgTexture, fenceTexture;
	Sprite bgSprite, fenceSprite;
	Button exitButton, readyButton, confirmExit;
	string gameState;
	vector <Entity*> entityList;
private:
	void pollEvents();
	void update(string gameState);
	void render(string gameState);
	void setGUI();
	void createEntity(string, float, float);
};

