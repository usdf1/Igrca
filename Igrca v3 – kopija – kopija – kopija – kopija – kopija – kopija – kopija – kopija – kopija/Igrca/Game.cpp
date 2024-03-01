#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "Game.h"
#include "TextureManager.h"
#include "Vector2D.h"
#include "Transform.h"
#include "Player.h"
#include "Keyboard.h"
#include "RigidBody.h"
#include "TileMap.h"
#include "Camera.h"
#include "Arena.h"
#include "Collision.h"
#include "Enemy.h"
#include "Arrow.h"
#include "Text.h"

Game* Game::s_instance = nullptr;
Player* player = NULL;
TileMap* map;
Arena* arena;
Collision* coll;
Enemy* enemy;
Arrow* arrow;
Text text;

int score = 0;
int scale = 2;

bool Game::Init(int lvl, int en, int ar) {
	if (SDL_Init(SDL_INIT_VIDEO) != 0 && IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG) != 0) {
		std::cout << "fail" << std::endl;
		return false;
	}

	if (TTF_Init() != 0) {
		return false;

	}

	m_window = SDL_CreateWindow("igrca", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT,0);
	if (m_window == NULL) {
		std::cout << "xD" << std::endl;
		return false;	
	}
	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (m_renderer == NULL) {
		std::cout << "render error" << std::endl;
		return false;
	}

	if (!text.loadFont("assets/arial.ttf", 32))
		std::cout << "balls";

	TextureManager::GetInstance()->Load("player", "assets/moai.png");
	TextureManager::GetInstance()->Load("player_walk", "assets/moai.png");
	TextureManager::GetInstance()->Load("arena", "assets/arena.png");
	TextureManager::GetInstance()->Load("bg", "assets/bg.png");
	TextureManager::GetInstance()->Load("enemy", "assets/enemy2.png");
	TextureManager::GetInstance()->Load("grass2", "assets/grass2.png");
	TextureManager::GetInstance()->Load("sand2", "assets/sand2.png");
	TextureManager::GetInstance()->Load("arrow", "assets/arrow.png");

	player = new Player(new Properties("player", 10, 10, 64, 64, 1));
	map = new TileMap();
	arena = new Arena(ar);
	coll = new Collision;
	enemy = new Enemy();
	arrow = new Arrow(player);

	enemy->FllVec(en);
	arena->SetPos();

	return m_IsRunning = lvl;
}

bool Game::Clean() {
	TextureManager::GetInstance()->Clean();
	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyWindow(m_window);
	IMG_Quit();
	TTF_Quit();
	SDL_Quit();
	return 1;
}

void Game::Quit() {
	Game::GetInstance()->Clean();
	m_IsRunning = 0;
}

void Game::Update(float speed) {
	std::cout << score << std::endl;

	enemy->Update(0.3, scale + 1);
	player->Update(scale);
	Camera::GetInstance().SetTarget(player->GetOrigin());
	Camera::GetInstance().Update(1);

	for (int i = 0; i < enemy->vec_enemy.size(); i ++) {
		enemy->vec_enemy[i].moveEnemyTowardsPlayer(player,speed);
	} 

	if (coll->EnemyCollision(enemy, player->playerRect)) {
		score -= 50; 
	}

	if (coll->CheckCollision(arena, player->playerRect)) {
		score += 100;
		if (arena->count > 0)
			arena->SetPos();

		else
			m_IsRunning += 1;
	}

	arrow->CalculateAngle(arena, player);

}

void Game::Render() {
	SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);
	SDL_RenderClear(m_renderer);

	if (Game::GetInstance()->IsRunning() == 1) {
		map->render("grass", "sand", scale);
	}
	else if (Game::GetInstance()->IsRunning() == 2) {
		map->render("grass2", "sand2", scale);
	}
		enemy->Draw(enemy);
		player->Draw();
		arena->SetArenas(scale);
		arrow->Draw(player, scale);

		TextureManager::GetInstance()->renderText("Tocke  " + std::to_string(score), {0,0,0,255}, text, 3, 0);
		TextureManager::GetInstance()->renderText("Tocke  " + std::to_string(score), { 0,0,0,255 }, text, 5, 0);
		TextureManager::GetInstance()->renderText("Preostale  Arene  " + std::to_string(arena->count + 1), {0,0,0,255}, text, 3, 30);
		TextureManager::GetInstance()->renderText("Preostale  Arene  " + std::to_string(arena->count + 1), { 0,0,0,255 }, text, 5, 30);
		TextureManager::GetInstance()->renderText("Level  " + std::to_string(m_IsRunning), {0,0,0,255}, text, 3, 60);
		TextureManager::GetInstance()->renderText("Level  " + std::to_string(m_IsRunning), { 0,0,0,255 }, text, 5, 60);

		SDL_RenderPresent(m_renderer);

	
}
void Game::Events() {
	Keyboard::GetInstance()->Listen();
}
