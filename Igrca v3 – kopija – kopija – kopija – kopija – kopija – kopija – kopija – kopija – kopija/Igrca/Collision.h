#pragma once
#include "Arena.h"
#include "Enemy.h"

class Collision {
public:
	bool CheckCollision(Arena* arena, SDL_Rect rect2);
	bool EnemyCollision(Enemy* enemy, SDL_Rect rect2);
	bool CheckBorder(Player* player);
};