#include "Player.h"
#include "TextureManager.h"
#include "SDL.h"
#include "Keyboard.h"
#include "Game.h"

Game* game;

Player::Player(Properties *props) : Character(props)
{
	m_RigidBody = new RigidBody();
	m_Animation = new Animation();

}

void Player::Draw()
{
	m_Animation->Draw(m_Transform->X, m_Transform->Y, m_Width, m_Height);
}

void Player::Update(float sc)
{
	m_Animation->SetProps("player", 2, 2, 140, sc);
	m_RigidBody->UnsetForce();

	m_Position.X = m_Transform->X;
	m_Position.Y = m_Transform->Y;


	if (Keyboard::GetInstance()->GetKeyDown(SDL_SCANCODE_S) && Keyboard::GetInstance()->GetKeyDown(SDL_SCANCODE_A)) {
		if (GetPosition().Y > MAP_HEIGHT - m_Height)
			m_RigidBody->ApplyForceY(0 * DOWN);
		else
			m_RigidBody->ApplyForceY(4 * DOWN);

		if (GetPosition().X < 0) 
			m_RigidBody->ApplyForceX(0 * BACKWARD);
		else 
			m_RigidBody->ApplyForceX(4 * BACKWARD);

		m_Animation->SetProps("player_walk", 0, 6, 140, sc);
	}

	else if (Keyboard::GetInstance()->GetKeyDown(SDL_SCANCODE_S) && Keyboard::GetInstance()->GetKeyDown(SDL_SCANCODE_D)) {
		if (GetPosition().Y > MAP_HEIGHT - m_Height)
			m_RigidBody->ApplyForceY(0 * DOWN);
		else 
			m_RigidBody->ApplyForceY(4 * DOWN);

		if (GetPosition().X > MAP_WIDTH - m_Width)
			m_RigidBody->ApplyForceX(0 * FORWARD);
		else
			m_RigidBody->ApplyForceX(4 * FORWARD);

		m_Animation->SetProps("player_walk", 0, 6, 140, sc, SDL_FLIP_HORIZONTAL);
	}

	else if (Keyboard::GetInstance()->GetKeyDown(SDL_SCANCODE_W) && Keyboard::GetInstance()->GetKeyDown(SDL_SCANCODE_A)) {

		if (GetPosition().Y < 0)
			m_RigidBody->ApplyForceY(0 * UP);
		else
			m_RigidBody->ApplyForceY(4 * UP);

		if (GetPosition().X < 0)
			m_RigidBody->ApplyForceX(0 * BACKWARD);
		else
			m_RigidBody->ApplyForceX(4 * BACKWARD);

		m_Animation->SetProps("player_walk", 0, 6, 140, sc);
	}

	else if (Keyboard::GetInstance()->GetKeyDown(SDL_SCANCODE_W) && Keyboard::GetInstance()->GetKeyDown(SDL_SCANCODE_D)) {

		if (GetPosition().Y < 0)
			m_RigidBody->ApplyForceY(0 * UP);
		else 
			m_RigidBody->ApplyForceY(4 * UP);

		if (GetPosition().X > MAP_WIDTH - m_Width)
			m_RigidBody->ApplyForceX(0 * FORWARD);
		else 
			m_RigidBody->ApplyForceX(4 * FORWARD);
		m_Animation->SetProps("player_walk", 0, 6, 140, sc, SDL_FLIP_HORIZONTAL);

	}

	 else if (Keyboard::GetInstance()->GetKeyDown(SDL_SCANCODE_A)) {
		if (GetPosition().X < 0) {
			m_RigidBody->ApplyForceX(0 * BACKWARD);
		}
		else 
			m_RigidBody->ApplyForceX(4 * BACKWARD);
		m_Animation->SetProps("player_walk", 0, 6, 140, sc);
	 }

	else if (Keyboard::GetInstance()->GetKeyDown(SDL_SCANCODE_D)) {
		if (GetPosition().X > MAP_WIDTH - m_Width) 
			m_RigidBody->ApplyForceX(0 * FORWARD);
		else 
			m_RigidBody->ApplyForceX(4 * FORWARD);
		m_Animation->SetProps("player_walk", 0, 6, 140, sc, SDL_FLIP_HORIZONTAL);
	}

	else if (Keyboard::GetInstance()->GetKeyDown(SDL_SCANCODE_W)) {
		if (GetPosition().Y < 0) 
			m_RigidBody->ApplyForceY(0 * UP);
		else 
			m_RigidBody->ApplyForceY(4 * UP);
		m_Animation->SetProps("player_walk", 3, 4, 140, sc);
	}

	else if (Keyboard::GetInstance()->GetKeyDown(SDL_SCANCODE_S)) {
		if (GetPosition().Y > MAP_HEIGHT - m_Height)
			m_RigidBody->ApplyForceY(0 * DOWN);
		else 
			m_RigidBody->ApplyForceY(4 * DOWN);
		m_Animation->SetProps("player_walk", 1, 3, 140, sc);
	}



	if (Keyboard::GetInstance()->GetKeyDown(SDL_SCANCODE_ESCAPE)) {
		game->Quit();
	}
	m_RigidBody->Update(1.3);
	m_RigidBody->ApplyForceX(0);

	m_Transform->TranslateX(m_RigidBody->Position().X);
	m_Transform->TranslateY(m_RigidBody->Position().Y);

	m_Origin->X = m_Transform->X + m_Width / static_cast<float>(2);
	m_Origin->Y = m_Transform->Y + m_Height / static_cast<float>(2);

	playerRect = { (int)m_Transform->X, (int)m_Transform->Y, 40, 45 };

	m_Animation->Update();
}

void Player::Clean()
{
	TextureManager::GetInstance()->Clean();
}

