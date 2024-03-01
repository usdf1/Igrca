#include "Enemy.h"
#include "ctime"
#include "cstdlib"
#include <iterator>
#include <cmath>
#include "GameObject.h"



void Enemy::FllVec( int num) {
	for (int i = 0; i < num; i++) {
		Enemy e;
		vec_enemy.push_back(e);
	}
}

void Enemy::moveEnemyTowardsPlayer(Player* player, float e_Speed)
{
	prevX = m_Position.X;
	prevY = m_Position.Y;

	float dx = (float)player->GetPosition().X - m_Position.X;
	float dy = (float)player->GetPosition().Y - m_Position.Y;

	float distance = sqrt(dx * dx + dy * dy);

	if (distance != 0) {
		dx /= distance;
		dy /= distance;
	}

	if (distance < 600) {
		m_Position.X += (int)(dx * e_Speed);
		m_Position.Y += (int)(dy * e_Speed);
	}

	enemy_Rect.x = m_Position.X;
	enemy_Rect.y = m_Position.Y;

}

Enemy::Enemy(){

	e_Animation = new Animation();

	m_Position.X = rand() % (3100 - 0);
	m_Position.Y = rand() % (3100 - 0);

	m_Width = 50;
	m_Height = 59;

	enemy_Rect.x = m_Position.X;
	enemy_Rect.y = m_Position.Y;
	enemy_Rect.w = m_Width;
	enemy_Rect.h = m_Height;

}

void Enemy::Draw(Enemy* enemy)
{
	for (int i = 0; i < enemy->vec_enemy.size(); i++) {
		vec_enemy[i].e_Animation->Draw(enemy->vec_enemy[i].m_Position.X, enemy->vec_enemy[i].m_Position.Y, enemy->m_Width, enemy->m_Height);
	}
}

void Enemy::Update(float dt, int scale)
{	

	for (int i = 0; i < vec_enemy.size(); i++) {
		vec_enemy[i].e_Animation->SetProps("enemy", 3, 2, 80, scale);
		if (vec_enemy[i].prevX > vec_enemy[i].m_Position.X)
			vec_enemy[i].e_Animation->SetProps("enemy", 0, 6, 80, scale);

		else if (vec_enemy[i].prevX > vec_enemy[i].m_Position.X && vec_enemy[i].prevY < vec_enemy[i].m_Position.Y)
			vec_enemy[i].e_Animation->SetProps("enemy", 0, 6, 80, scale);

		else if (vec_enemy[i].prevX < vec_enemy[i].m_Position.X && vec_enemy[i].prevY < vec_enemy[i].m_Position.Y)
			vec_enemy[i].e_Animation->SetProps("enemy", 0, 6, 80, scale, SDL_FLIP_HORIZONTAL);

		else if (vec_enemy[i].prevX > vec_enemy[i].m_Position.X && vec_enemy[i].prevY > vec_enemy[i].m_Position.Y)
			vec_enemy[i].e_Animation->SetProps("enemy", 0, 6, 80, scale);

		else if (vec_enemy[i].prevX < vec_enemy[i].m_Position.X && vec_enemy[i].prevY > vec_enemy[i].m_Position.Y)
			vec_enemy[i].e_Animation->SetProps("enemy", 0, 6, 80, scale, SDL_FLIP_HORIZONTAL);

		else if (vec_enemy[i].prevX < vec_enemy[i].m_Position.X)
			vec_enemy[i].e_Animation->SetProps("enemy", 0, 6, 80, scale, SDL_FLIP_HORIZONTAL);

		else if (vec_enemy[i].prevY < vec_enemy[i].m_Position.Y)
			vec_enemy[i].e_Animation->SetProps("enemy", 1, 4, 80, scale);

		else if (vec_enemy[i].prevY > vec_enemy[i].m_Position.Y)
			vec_enemy[i].e_Animation->SetProps("enemy", 2, 4, 80, scale);

		vec_enemy[i].e_Animation->Update();

	}
}

void Enemy::Clean()
{
	for (int i = 0; i < vec_enemy.size(); i++)
		vec_enemy.pop_back();
	TextureManager::GetInstance()->Clean();
}
