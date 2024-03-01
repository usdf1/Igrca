#include "Camera.h"
#include <iostream>

void Camera::Update(int scale) {
	m_View.x = m_Target.X - SCREEN_WIDTH / 2 + 100;
	m_View.y = m_Target.Y - SCREEN_HEIGHT / 2;

	if (m_View.x < 0)
		m_View.x = 0;

	if (m_View.y < 0)
		m_View.y = 0;

	if (m_View.x > (2 * MAP_WIDTH - m_View.w) - 300)
		m_View.x = (2 * MAP_WIDTH - m_View.w);

	if (m_View.y > (2 * MAP_HEIGHT - m_View.h) - 300)
		m_View.y = (2 * MAP_HEIGHT - m_View.h);

	if (m_View.x > MAP_WIDTH - 1720 && m_View.x < 3210) // kje se ustav kamera X
		m_View.x = MAP_WIDTH - 1720;

	if (m_View.y > MAP_HEIGHT - 1000) // kje se ustav kamera Y
		m_View.y = MAP_HEIGHT - 1000;

	m_Position = Vector2D(m_View.x, m_View.y);

}
