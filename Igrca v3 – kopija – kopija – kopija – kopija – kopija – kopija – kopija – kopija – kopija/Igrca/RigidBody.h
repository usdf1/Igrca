#pragma once

#include "Game.h"
#include "Vector2D.h"

constexpr auto UNI_MASS = 1.0f;
constexpr auto GRAVITY = 9.8f;

constexpr auto FORWARD = 1;
constexpr auto BACKWARD = -1;

constexpr auto UP = -1;
constexpr auto DOWN = 1;

class RigidBody {
public:
	RigidBody() {
		m_Mass = UNI_MASS;
		m_Gravity = GRAVITY;
	}
	//fizike
	void SetMass(float mass) { m_Mass = mass; }
	void SetGravity(float gravity) { m_Gravity = gravity; }

	void ApplyForce(Vector2D F) { m_Force = F; }
	void ApplyForceX(float X) { m_Force.X = X; }
	void ApplyForceY(float Y) { m_Force.Y = Y; }

	void UnsetForce() { m_Force = Vector2D(0,0); }

	void ApplyFriction(Vector2D Fr) { m_Friction = Fr; }
	void UnsetFriction() { m_Friction = Vector2D(0, 0); }
	
	float GetMass() const { return m_Mass; }
	Vector2D Position() const { return m_Position; }
	Vector2D Velocity() const { return m_Velocity; }
	Vector2D Accel() const { return m_Accel; }

	//update

	void Update(float dt) {
		m_Accel.X = (m_Force.X + m_Friction.X) / m_Mass;
		m_Accel.Y = (m_Force.Y + m_Friction.Y) / m_Mass;
		m_Velocity = m_Accel * dt;
		m_Position = m_Velocity * dt;
	}

private:
	float m_Mass;
	float m_Gravity;

	Vector2D m_Force;
	Vector2D m_Friction;

	Vector2D m_Position;
	Vector2D m_Velocity;
	Vector2D m_Accel; // == accelaration

};
