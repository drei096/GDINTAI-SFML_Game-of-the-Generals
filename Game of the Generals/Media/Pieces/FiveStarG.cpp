#include "FiveStarG.h"
#include <iostream>
#include "../../TextureManager.h"
#include <SFML/Graphics.hpp>
#include "../../Game.h"
#include "../../Level.h"

FiveStarG::FiveStarG(string name) : GameObject(name) {

}

void FiveStarG::initialize() {
	cout << "Declared as " << getName() << "\n";

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

void FiveStarG::processInput(Event event)
{
	switch (event.type)
	{
	case Event::MouseButtonPressed:
		if (event.key.code == Mouse::Left)
			cout << "PRESSED" << endl;
		break;
	}




	/*
	bool mouseFlag = false;
	if (event.type == Event::MouseButtonPressed) 
	{
		mouseFlag = true;
	}

	switch (event.key.code)
	{
	case Mouse::Left:
		this->transformable.setScale(3.0, 3.0);
		break;
	case Mouse::Right:
		this->transformable.setScale(1.0, 1.0);
	}
	*/


	/*
	//ayaw mag scale up ng piece
	case Event::MouseButtonPressed:
		this->transformable.move(3.0f, 3.0f);
		break;
	*/
	/*
	bool keyFlag = false;
	if (event.type == sf::Event::KeyPressed) {
		keyFlag = true;
	}
	else if (event.type == sf::Event::KeyReleased) {
		keyFlag = false;
	}
	switch (event.key.code) {
	case sf::Keyboard::W:
		this->moveUp = keyFlag;
		break;
	case sf::Keyboard::A:
		this->moveLeft = keyFlag;
		break;
	case sf::Keyboard::S:
		this->moveDown = keyFlag;
		break;
	case sf::Keyboard::D:
		this->moveRight = keyFlag;
		break;
	}
	*/
}

void FiveStarG::update(Time deltaTime) {

	/*
	Vector2f offset(0.0f, 0.0f);

	GameObject::update(deltaTime);

	if (this->moveUp) {
		offset.y -= this->SPEED_MULTIPLIER;
		this->transformable.move(offset * deltaTime.asSeconds());

	}
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

//broken function pa, it's supposed to take in RENDERWINDOW WINDOW, kaso nagerror kapag inaaccess si window dito
bool FiveStarG::isMouseHover(RenderWindow& window)
{
	float mouseX = Mouse::getPosition(window).x, mouseY = Mouse::getPosition(window).y;

	float iconPosX = sprite->getPosition().x, iconPosY = sprite->getPosition().y;

	float iconxPosWidth = sprite->getPosition().x + sprite->getLocalBounds().width;
	float iconyPosHeight = sprite->getPosition().y + sprite->getLocalBounds().height;

	if (mouseX < iconxPosWidth && mouseX > iconPosX && mouseY < iconyPosHeight && mouseY > iconPosY)
	{
		return true;
	}
	return false;
}
