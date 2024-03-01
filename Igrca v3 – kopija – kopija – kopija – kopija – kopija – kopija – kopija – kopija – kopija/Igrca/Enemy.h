#pragma once

#include "Character.h"
#include "RigidBody.h"
#include "Animation.h"
#include "TextureManager.h"
#include "Player.h"
#include <vector>


class Enemy{
public:
	Enemy();
	void Draw(Enemy* enemy);
	void Update(float dt, int scale);
	void Clean();
	void FllVec(int num);
	void moveEnemyTowardsPlayer(Player* player, float speed);

	std::vector<Enemy> vec_enemy;
	SDL_Rect enemy_Rect;
	Vector2D m_Position;
	float prevX;
	float prevY;


private:
	Animation* e_Animation;

	int m_Width;
	int m_Height;
	float m_Distance;

};