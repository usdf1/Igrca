#include "Collision.h"
#include <SDL.h>


bool Collision::CheckCollision(Arena* arena, SDL_Rect rect2)
{
		if (SDL_HasIntersection(&arena->arenaRect, &rect2) == SDL_TRUE) {
			return true;
		}
		return false;
}

bool Collision::EnemyCollision(Enemy* enemy, SDL_Rect rect2)
{
	for (int i = 0; i < enemy->vec_enemy.size(); i++) {
		if (SDL_HasIntersection(&enemy->vec_enemy[i].enemy_Rect, &rect2) == SDL_TRUE) {
			enemy->vec_enemy[i].m_Position.X = 100000;
			return true;
		}
	}
	return false;
}

bool Collision::CheckBorder(Player* player)
{
	if (player->GetPosition().X < 0 || player->GetPosition().Y < 0 || player->GetPosition().X > 960 || player->GetPosition().Y > 640) {
		return 1;
	}
	return false;
}


