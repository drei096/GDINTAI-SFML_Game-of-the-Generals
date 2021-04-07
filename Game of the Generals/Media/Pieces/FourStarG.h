#pragma once
#include"GameObject.h"
#include"../../Level.h"
#include<iostream>
using namespace std;

class FourStarG : public GameObject
{
public:
	FourStarG(string name);
	void initialize();
	void processInput(Event event, RenderWindow* window);
	void update(Time deltaTime);
	int getRanking();
	bool getStatus();
	bool isMouseHover(RenderWindow* window);

public:
	bool isSelected = false;

private:
	int ranking = 15;
	const float SPEED_MULTIPLIER = 300.0f;
	bool isDead = false;
	bool move = false;
};

