#pragma once

#include "Text.h"
#include <string>
#include <map>

class TextureManager {
public:
	static TextureManager* GetInstance() { return s_instance = (s_instance != nullptr) ? s_instance : new TextureManager();}

	bool Load(std::string id, std::string fileName);
	void Drop(std::string id);
	void Clean();

	void Draw(std::string id, int x, int y, int width, int height, SDL_RendererFlip flip = SDL_FLIP_NONE);
	void Draw_arr(std::string id, int x, int y, int width, int height, SDL_RendererFlip flip = SDL_FLIP_NONE, double angle = 0.0);
	void DrawFrames(std::string id, int x, int y, int width, int height, int row, int frame, float scale, SDL_RendererFlip flip = SDL_FLIP_NONE);
	void renderText(const std::string& text, SDL_Color color, Text &tex, int x, int y);

private:
	TextureManager() {};
	std::map<std::string, SDL_Texture*> m_TextureMap;
	static TextureManager* s_instance;
};
