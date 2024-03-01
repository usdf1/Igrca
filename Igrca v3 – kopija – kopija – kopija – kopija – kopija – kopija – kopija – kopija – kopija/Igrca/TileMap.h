#pragma once

#include <SDL.h>
#include <vector>

class TileMap {
public:
    TileMap();
    ~TileMap();
    void render(const char* tex1, const char* tex2, int scale);
    void Load(int arr[56][56]);

private:
    const int MAP_WIDTH = 56;
    const int MAP_HEIGHT = 56;
    const int TILE_SIZE = 32;
    int map[56][56];

    SDL_Renderer* renderer;
};
