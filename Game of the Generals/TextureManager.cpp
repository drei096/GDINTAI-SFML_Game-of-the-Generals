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

	for (int i = 0; i < 30; i++)
	{
		if (i >= 0 && i < 15)
		{
			loadTexture("black" + to_string(i), stdPath + "p_0" + to_string(i) + ".png");
		}
		else
			loadTexture("white" + to_string(i), stdPath + "p_0" + to_string(i) + ".png");
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
