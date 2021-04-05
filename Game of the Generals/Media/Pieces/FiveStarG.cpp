#include "FiveStarG.h"
#include <iostream>
#include "../../TextureManager.h"
#include <SFML/Graphics.hpp>
#include "../../Game.h"
#include "../../Level.h"

FiveStarG::FiveStarG(string name) : GameObject(name) {

}

void FiveStarG::initialize() {
	//cout << "Declared as " << getName() << "\n";

	//assign texture
	sprite = new Sprite();

	if(name == "blackFiveStar")
		sprite->setTexture(*TextureManager::getInstance()->getTexture("black0"));
	else
		sprite->setTexture(*TextureManager::getInstance()->getTexture("white0"));

	Vector2u textureSize = sprite->getTexture()->getSize();
	sprite->setOrigin(textureSize.x / 2, textureSize.y / 2);
	transformable.setPosition(Game::WINDOW_WIDTH / 2, Game::WINDOW_HEIGHT / 2);
	

}

void FiveStarG::processInput(Event event, RenderWindow* window)
{

	if (event.type == Event::MouseButtonPressed && event.key.code == Mouse::Left)
	{
		if (isMouseHover(window))
		{
			this->transformable.setScale(2.0, 2.0); //remove later
			isSelected = true;
		}
	}
	if(event.type == Event::MouseButtonPressed && event.key.code == Mouse::Right)
	{
		this->transformable.setScale(1.0, 1.0); //remove later
		isSelected = false;
	}
}

void FiveStarG::update(Time deltaTime) {

	
	Vector2f offset(0.0f, 0.0f);

	GameObject::update(deltaTime);

	if (isSelected) 
	{
		//HIGHLIGHT BOARD WITH POSSIBLE MOVES
		//move the piece here na rin siguro

		//offset.y -= this->SPEED_MULTIPLIER;

		//this->transformable.move(offset * deltaTime.asSeconds());

	}
	
	/*
	else if (this->moveDown) {
		offset.y += this->SPEED_MULTIPLIER;
		this->transformable.move(offset * deltaTime.asSeconds());
	}
	else if (this->moveRight) {
		offset.x += this->SPEED_MULTIPLIER;
		this->transformable.move(offset * deltaTime.asSeconds());

	}
	else if (this->moveLeft) {
		offset.x -= this->SPEED_MULTIPLIER;
		this->transformable.move(offset * deltaTime.asSeconds());

	}
	*/
}

int FiveStarG::getRanking()
{
	return ranking;
}

bool FiveStarG::getStatus()
{
	return isDead;
}

bool FiveStarG::isMouseHover(RenderWindow* window)
{
	float mouseX = Mouse::getPosition(*window).x, mouseY = Mouse::getPosition(*window).y;

	float iconPosX = transformable.getPosition().x, iconPosY = transformable.getPosition().y;
	
	float iconxPosWidth = transformable.getPosition().x + (sprite->getLocalBounds().width);
	float iconyPosHeight = transformable.getPosition().y + (sprite->getLocalBounds().height);


	if (mouseX < iconxPosWidth && mouseY < iconyPosHeight)
	{
		return true;
	}
	return false;
}
