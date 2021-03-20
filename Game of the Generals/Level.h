#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>

using namespace std;
using namespace sf;

class Level
{
public:
	Level();
	void run();
private:
	RenderWindow window;
	Font font;
	Text deadText;
	Texture bgTexture;
	Sprite bgSprite;
private:
	void pollEvents();
	void update();
	void render();
	void setGUI();
};

