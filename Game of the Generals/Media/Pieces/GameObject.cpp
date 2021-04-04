#include "GameObject.h"
#include <iostream>


GameObject::GameObject(string n) 
{
	name = n;
}

GameObject::~GameObject() 
{
	if (sprite != NULL) 
	{
		delete sprite;
	}
}

string GameObject::getName() 
{
	return name;
}

void GameObject::draw(RenderWindow* window, RenderStates renderStates) 
{
	//apply the transform to its children
	renderStates.transform = renderStates.transform * transformable.getTransform();

	window->draw(*sprite, renderStates);

	cout << "Drawing " + getName() + "\n";

	//draw its children
	for (int i = 0; i < childList.size(); i++) 
	{
		GameObject* child = childList[i];
		child->draw(window, renderStates);
	}
}

void GameObject::update(Time deltaTime) 
{
	// Add Implementation here

}

void GameObject::attachChild(GameObject* child) 
{
	childList.push_back(child);
	child->initialize(); //initialize when attaching to child
}

void GameObject::detachChild(GameObject* child)
{
	int index = -1;
	for (int i = 0; i < childList.size(); i++) 
	{
		if (childList[i] == child) 
		{
			index = i;
		}
	}

	if (index != -1) 
	{
		childList.erase(childList.begin() + index);
	}
}

void GameObject::setPosition(float x, float y)
{
	transformable.setPosition(x, y);
}
