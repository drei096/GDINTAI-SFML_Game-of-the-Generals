#include <stddef.h>
#include <iostream>
#include "TextureManager.h"

TextureManager* TextureManager::sharedInstance = NULL;

TextureManager* TextureManager::getInstance() 
{
	//initialize only when we need it
	if (sharedInstance == NULL)
	{
		sharedInstance = new TextureManager();
	}
	return sharedInstance;
}

void TextureManager::loadAll() 
{
	string stdPath = "Media/Textures/";

	for (int i = 0; i < 15; i++)
	{
		loadTexture("black" + i, stdPath + "b_0" + to_string(i) + ".png");
		loadTexture("white" + i, stdPath + "w_0" + to_string(i) + ".png");
	}
}

void TextureManager::loadTexture(string key, string path) 
{
	Texture* texture = new Texture();
	texture->loadFromFile(path);
	textureMap[key] = texture;
}

sf::Texture* TextureManager::getTexture(std::string key) 
{
	if (textureMap[key] != NULL) 
	{
		return textureMap[key];
	}
	else 
	{
		cout << "No texture found for " << key;
		return NULL;
	}
}
