#include "Core/Font.h"

#include <stdexcept>

#include <SDL2/SDL_ttf.h>

Font::Font()
{
    _font = nullptr;
}

TTF_Font* Font::getTtfFont()
{
    return _font;
}

void Font::open(const char* path, unsigned int ptSize)
{
    if(_font != nullptr) {
        throw std::invalid_argument("Font is already open!"); // TODO: add exception
    }

    _font = TTF_OpenFont(path, ptSize);
    
    if(_font == NULL){
        throw std::invalid_argument(TTF_GetError()); //TODO: add exception
    }
}

void Font::close()
{
    if(_font == nullptr) {
        throw std::invalid_argument("Font is not opened!"); // TODO: add exception
    }

    TTF_CloseFont(_font);
    _font = nullptr;
}

Font::~Font()
{
    if(_font != nullptr) {
        close();
    }
}