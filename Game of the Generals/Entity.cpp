#include "Entity.h"

Entity::Entity()
{
}

void Entity::setTexture(Texture texture)
{
	eTexture = texture;
	eSprite.setTexture(eTexture);
}

sf::Sprite* Entity::getSprite()
{
	return &eSprite;
}

void Entity::setRanking(int r)
{
	ranking = r;
}

int Entity::getRanking()
{
	return ranking;
}

void Entity::setPosition(float x, float y)
{
	position.x = x;
	position.y = y;
}

Vector2f Entity::getPosition()
{
	return Vector2f(position);
}
