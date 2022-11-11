#include "Graphics/AsciiSprite.h"

#include <stdexcept>

#include <SDL2/SDL_ttf.h>

AsciiSprite::AsciiSprite(Font* font, char symbol, SDL_Color color, Renderer* renderer)
{
    SDL_Surface* surface = TTF_RenderGlyph_Blended(font->getTtfFont(), symbol, color);

    if(surface == NULL) {
        throw std::invalid_argument(TTF_GetError()); // TODO: Add exception
    }

    _texture = SDL_CreateTextureFromSurface(renderer->getSdlRenderer(), surface);

    if(_texture == NULL) {
        throw std::invalid_argument(SDL_GetError()); // TOOD: add exception
    }

    SDL_FreeSurface(surface);
}

void AsciiSprite::draw(Renderer* renderer, SDL_Rect* dstRect, SDL_Rect* srcRect  )
{
    if(_texture == NULL) {
        throw std::invalid_argument("Texture is not created!"); //TODO: add exception;
    }
    
    SDL_RenderCopy(renderer->getSdlRenderer(), _texture, srcRect, dstRect);
}

AsciiSprite::~AsciiSprite(){
    if(_texture != NULL) {
        SDL_DestroyTexture(_texture);
    }
}