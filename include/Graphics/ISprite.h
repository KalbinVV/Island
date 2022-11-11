#ifndef ISPRITE_H_INCLUDED
#define ISPRITE_H_INCLUDED

#include <SDL2/SDL.h>

#include "Core/Renderer.h"

class ISprite
{
public:
    virtual void draw(Renderer* renderer, SDL_Rect* dstRect, SDL_Rect* srcRect = NULL) = 0;
    virtual ~ISprite() {};
};

#endif // ISPRITE_H_INCLUDED