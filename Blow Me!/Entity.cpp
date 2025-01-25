#include <raylib.h>

#include "Entity.hpp"

Entity::Entity(const char* path, Vector2 pos, int frameSpd, 
	int frameCnt, float velocityX, bool shouldInvert, float scale)
: position(pos), velX(velocityX), scale(scale)
{
	animComponent = new Animation(path, frameCnt, frameSpd, shouldInvert);
	collisionBox.x = 0; collisionBox.y = 0;
	collisionBox.width = 0; collisionBox.height = 0;
}

Entity::~Entity()
{
	delete animComponent;
}

//void Entity::shiftSpriteFrame()
//{
//	frameCounter++;
//
//	if (frameCounter >= (60 / frameSpeed))
//	{
//		frameCounter = 0;
//		currentFrame++;
//
//		if (currentFrame > frameCount) currentFrame = 0;
//		destRect.x = currentFrame * spriteSheet.width / frameCount;
//
//	}
//}

void Entity::display(int64_t& global_frame)
{
	animComponent->draw(global_frame, position.x, position.y, scale);
}

void Entity::move()
{
	position.x -= velX;
}

EntityQueue::EntityQueue()
{
	enemiesTypeQuantities = {0};
}

void EntityQueue::addEntity(int i)
{
	Vector2 pos = {screenWidth, static_cast<float>(GetRandomValue(100, 700))};

	//int randomNumber = GetRandomValue(0, enemyTypeCount - 1);
	int randomNumber = i;

	while (enemiesTypeQuantities[randomNumber] > maxEnemiesPerType)
		if (randomNumber == enemyTypeCount)
			randomNumber = 0;
		else
			++randomNumber;
	
	const char *const path = initArr[randomNumber].path;
	int frameCnt = initArr[randomNumber].frameCount;
	float newScale = initArr[randomNumber].scale * static_cast<float>(GetRandomValue(100, 200)) / 200.0f;
	bool shouldInvert = initArr[randomNumber].shouldInvert;

	queue.push(Entity(path, pos, animationSpeed, frameCnt, velocityX, shouldInvert, newScale));
}
