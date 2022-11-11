#ifndef FONT_H_INCLUDED
#define FONT_H_INCLUDED

#include <SDL2/SDL_ttf.h>

// TTF font implementation

class Font
{
private:
    TTF_Font* _font;
public:
    Font();
    TTF_Font* getTtfFont();
    void open(const char* path, unsigned int ptSize);
    void close();
    ~Font();
};

#endif // FONT_H_INCLUDED