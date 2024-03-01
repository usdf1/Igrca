#include "Arrow.h"
#include <cmath>

Arrow::Arrow(Player * player)
{
	_Pos.X = player->GetPosition().X;
	_Pos.Y = player->GetPosition().Y + 20;

	aRect.x = (int)_Pos.X;
	aRect.y = (int)_Pos.Y;
	aRect.h = 100;
	aRect.w = 100;

	kot = 0;
}

void Arrow::CalculateAngle(Arena* arena, Player* player)
{
	double dx = arena->_x - player->GetPosition().X;
	double dy = arena->_y - player->GetPosition().Y;

	kot = std::atan2(dy, dx) * 180.0 / M_PI;
}

void Arrow::Draw(Player* player, int scale)
{
	TextureManager::GetInstance()->Draw_arr("arrow", player->GetPosition().X + 8, player->GetPosition().Y - 35, 50 * scale, 50 * scale,SDL_FLIP_NONE, kot);
}
