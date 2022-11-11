#ifndef ASCIISPRITE_H_INCLUDED
#define ASCIISPRITE_H_INCLUDED

#include "Graphics/ISprite.h"
#include "Core/Font.h"

// Simple ASCII character sprite

class AsciiSprite : public ISprite
{
private:
    SDL_Texture* _texture;
public:
    AsciiSprite(Font* font, char symbol, SDL_Color color, Renderer* renderer);
    virtual void draw(Renderer* renderer, SDL_Rect* dstRect, SDL_Rect* srcRect = NULL) override;
    ~AsciiSprite();
};

#endif // ASCIISPRITE_H_INCLUDED