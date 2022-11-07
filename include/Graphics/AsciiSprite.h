#ifndef SYMBOLSPRITE_H_INCLUDED
#define SYMBOLSPRITE_H_INCLUDED

#include "Graphics/ISprite.h"

// Simple ASCII character sprite

class AsciiSprite : public ISprite
{
private:
    SDL_Texture* _texture;
public:
    virtual void draw(Renderer* renderer, SDL_Rect dstRect, SDL_Rect* srcRect = NULL) override;
};