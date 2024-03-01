#pragma once

#include <cmath>
#include <iostream>
#include "Vector2D.h"
#include "Arena.h"
#include "Player.h"

class Arrow {
public:
	Arrow(Player* playe);
	void CalculateAngle(Arena* arena, Player* player);
	void Draw(Player* player, int scale);
	double kot;
private:
	Vector2D _Pos;
	SDL_Rect aRect;
};