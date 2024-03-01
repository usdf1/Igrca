#pragma once

#include <ctime>
#include <cstdlib>
#include "Vector2D.h"
#include "TextureManager.h"
#include <vector>

class Arena {
public:
	int _x, _y;
	int count;
public:

	Arena(int cnt);
	void SetArenas(int scale);
	void SetPos();
	void Clear();
	Vector2D GetPosition() { return m_Position;}

	//std::vector <Arena> vec;
	Vector2D m_Position;
	SDL_Rect arenaRect;
};