#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;

class Entity
{
public:
	Entity();
	void setTexture(Texture texture);
	sf::Sprite* getSprite();
	void setRanking(int r);
	int getRanking();
	void setPosition(float x, float y);
	Vector2f getPosition();
private:
	Texture eTexture;
	Sprite eSprite;
	int ranking = 0;
	Vector2f position;
};

