#pragma once

#include <SDL_ttf.h>
#include <string>
#include "Player.h"

class Text {
public:
    Text();
    ~Text();

    bool loadFont(const std::string& fontPath, int fontSize);
    void closeFont();
    TTF_Font* mFont;
    std::string GetStringPlayer(Player* player);
    std::string GetStringArena(int count);
    std::string GetStringLevel(int lvl);

};