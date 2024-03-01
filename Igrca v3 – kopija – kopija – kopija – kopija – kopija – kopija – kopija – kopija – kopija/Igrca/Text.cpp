#include "Text.h"
#include <iostream>

Text::Text() : mFont(nullptr) {}

Text::~Text() {
    closeFont();
}

bool Text::loadFont(const std::string& fontPath, int fontSize) {
    mFont = TTF_OpenFont(fontPath.c_str(), fontSize);
    if (!mFont) {
        std::cerr << "Failed to load font: " << TTF_GetError() << std::endl;
        return false;
    }
    return true;
}


void Text::closeFont() {
    if (mFont) {
        TTF_CloseFont(mFont);
        mFont = nullptr;
    }
}

std::string Text::GetStringPlayer(Player* player)
{
    std::string pString;
    pString = "Pozicija: " + std::to_string((int)player->GetPosition().X);
    return std::string();
}

std::string Text::GetStringArena(int count)
{
    std::string aString;
    aString = "Preostale Arene: " + std::to_string(count + 1);
    return std::string();
}

std::string Text::GetStringLevel(int lvl)
{
    std::string pString;
    pString = "Level: " + std::to_string(lvl);
    return std::string();
}
