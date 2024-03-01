#pragma once

#include "Character.h"
#include "Animation.h"
#include "RigidBody.h"

class Player : public Character {
public:
	Player(Properties* props);

	virtual void Draw();
	virtual void Update(float dt);
	virtual void Clean();
	Vector2D GetPosition() { return m_Position; }

	SDL_Rect playerRect;

private:

	RigidBody* m_RigidBody;
	Animation* m_Animation;
	Vector2D m_Position;
};