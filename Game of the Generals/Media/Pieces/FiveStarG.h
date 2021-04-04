#pragma once
#include"GameObject.h"
#include<iostream>
using namespace std;

class FiveStarG : public GameObject
{
public:
	FiveStarG(string name);
	void initialize();
	void processInput(Event event);
	void update(Time deltaTime);
	int getRanking();
	bool getStatus();
	bool isMouseHover(RenderWindow& window);

private:
	bool isDead = false;
	int ranking = 15;
};

