#pragma once
#include"GameObject.h"
#include"../../Level.h"
#include<iostream>
using namespace std;

class FiveStarG : public GameObject
{
public:
	FiveStarG(string name);
	void initialize();
	void processInput(Event event, RenderWindow* window);
	void update(Time deltaTime);
	int getRanking();
	bool getStatus();
	bool isMouseHover(RenderWindow* window);

private:
	bool isDead = false;
	int ranking = 15;
	bool isSelected = false;
	const float SPEED_MULTIPLIER = 300.0f;
};

