#ifndef SPRITEATLAS_H_INCLUDED
#define SPRITEATLAS_H_INCLUDED

#include <SDL2/SDL.h>

#include "Core/Renderer.h"

class SpriteAtlas
{
private:
    SDL_Texture* _texture;

public:
    SpriteAtlas(const char* path, Renderer* renderer);
    SDL_Texture* getTexture();
    ~SpriteAtlas();
};

#endif // SPRITEATLAS_H_INCLUDED