#ifndef WINDOW_H_INCLUDED
#define WINDOW_H_INCLUDED

#include <SDL2/SDL.h>

class Window
{
private:
    SDL_Window* _sdlWindow;
    int _width;
    int _height;
    bool _openFlag;

public:
    Window();
    SDL_Window* getSdlWindow();
    void open(const char* title, int width, int height);
    bool isOpen();
    void close();
    int getWidth();
    int getHeight();
    ~Window();
};

#endif // WINDOW_H_INCLUDED