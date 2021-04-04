#pragma once
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class GameObject
{
public:
	GameObject(string name);
	virtual ~GameObject();
	virtual void initialize() = 0;
	virtual void processInput(Event event) = 0;
	virtual void update(Time deltaTime);
	void draw(RenderWindow* window, RenderStates renderStates);
	string getName();
	void attachChild(GameObject* child);
	void detachChild(GameObject* child);
	void setPosition(float x, float y);

protected:
	Transformable transformable;
	string name;
	Sprite* sprite;
	Texture* texture;
	vector<GameObject*> childList;
};

