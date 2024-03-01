#include "TileMap.h"
#include "TextureManager.h"
#include <ctime>
#include <cstdlib>

int lvl1[56][56];

TileMap::TileMap() {

    TextureManager::GetInstance()->Load("grass", "assets/grass.png");
    TextureManager::GetInstance()->Load("sand", "assets/sand.png");

    for (int i = 0; i < 56; i++) {
        for (int j = 0; j < 56; j++) {
            lvl1[i][j] = rand() % 2;
        }
    }

    Load(lvl1);
}

TileMap::~TileMap() {
}

void TileMap::Load(int arr[56][56]) {
    for (int y = 0; y < MAP_HEIGHT; ++y) {
        for (int x = 0; x < MAP_WIDTH; ++x) {
            map[y][x] = arr[y][x];
        }
    }

}

void TileMap::render(const char* tex1, const char* tex2, int scale) {
    int type = 0;

    for (int y = 0; y < MAP_HEIGHT; ++y) {
        for (int x = 0; x < MAP_WIDTH; ++x) {
            type = map[y][x];



            if (type == 0) {
                TextureManager::GetInstance()->Draw(tex1, x * TILE_SIZE * scale, y * TILE_SIZE * scale, TILE_SIZE * scale, TILE_SIZE * scale);
            }
            else if (type == 1) {
                TextureManager::GetInstance()->Draw(tex2, x * TILE_SIZE * scale, y * TILE_SIZE * scale, TILE_SIZE * scale, TILE_SIZE * scale);
            }

        }
    }
}
