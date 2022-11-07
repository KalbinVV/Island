#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include "Core/Renderer.h"
#include "Core/Window.h"
#include "Stage/IStage.h"

// Global game singletone

class Game
{
private:
    Window _window;
    Renderer _renderer;
    IStage* _stage;

    static Game* uniquePtr;

    Game(const char* title, int width, int height);

public:
    // sdl modules [un]initialization
    static void initModules();
    static void unInitModules();

    static Game* init();

    Window* getWindow();
    Renderer* getRenderer();
    void run();
    ~Game();
};

#endif // GAME_H_INCLUDED