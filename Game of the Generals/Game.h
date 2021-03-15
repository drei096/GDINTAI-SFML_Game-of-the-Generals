#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>

using namespace std;
using namespace sf;

class Game
{
public:
	Game();
	void run();
private:
	RenderWindow window;
	Font font;
	Text deadText;
	Texture bgTexture, samplePcTexture;
	Sprite bgSprite, samplePcSprite;
private:
	void pollEvents();
	void update();
	void render();
	void setGUI();
};
	
