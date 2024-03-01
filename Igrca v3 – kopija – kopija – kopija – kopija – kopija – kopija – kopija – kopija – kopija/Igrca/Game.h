#pragma once
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

constexpr auto SCREEN_WIDTH = 1780;;
constexpr auto SCREEN_HEIGHT = 1060;;
constexpr auto MAP_WIDTH = 3200;
constexpr auto MAP_HEIGHT = 3200;

class Game {
public:
	static Game* GetInstance() {
		return s_instance = (s_instance != nullptr) ? s_instance : new Game();
	}

	bool Init(int lvl, int en, int ar);
	bool Clean();

	void Quit();

	void Update(float speed);
	void Render();
	void Events();

	inline int IsRunning() { return m_IsRunning; }
	inline SDL_Renderer* GetRenderer() { return m_renderer; }

private:
	Game() {}
	int m_IsRunning;
	SDL_Window* m_window;
	SDL_Renderer* m_renderer;
	static Game* s_instance;
};