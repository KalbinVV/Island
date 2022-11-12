#include "Graphics/SpriteAtlas.h"

#include <stdexcept>

#include <SDL2/SDL_image.h>

SpriteAtlas::SpriteAtlas(const char* path, Renderer* renderer)
{
    SDL_Surface* surface = IMG_Load(path);

    if(surface == NULL) {
        throw std::invalid_argument(IMG_GetError());
    }

    _texture = SDL_CreateTextureFromSurface(renderer->getSdlRenderer(), surface);

    SDL_FreeSurface(surface);

    if(_texture == NULL) {
        throw std::invalid_argument(SDL_GetError());
    }
}

SDL_Texture* SpriteAtlas::getTexture(){
    return _texture;
}

SpriteAtlas::~SpriteAtlas(){
    if(_texture != nullptr){
        SDL_DestroyTexture(_texture);
    }
}