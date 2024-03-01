#include "Arena.h"
#include <iterator>
#include <iostream>

Arena::Arena(int cnt)
{
	count = cnt;
}

void Arena::SetArenas(int scale)
{
		TextureManager::GetInstance()->Draw("arena", _x, _y, 100 * scale, 100 * scale);
}

void Arena::SetPos()
{
	count--;

	_x = rand() % (3100 - 0);
	_y = rand() % (3100 - 0);

	m_Position.X = _x;
	m_Position.Y = _y;

	arenaRect = { (int)_x, (int)_y, 100, 100 };
}

void Arena::Clear() {
	_x = -100;
	_y = -100;
}