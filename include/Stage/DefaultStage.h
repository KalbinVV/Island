#ifndef DEFAULTSTAGE_H_INCLUDED
#define DEFAULTSTAGE_H_INCLUDED

#include "Core/Game.h"
#include "IStage.h"

// Default stage: start menu

class DefaultStage : public IStage
{
private:
    Game* _game;

public:
    DefaultStage(Game* game);
    virtual void render() override;
    virtual void handleEvents() override;
    virtual ~DefaultStage() {}
};

#endif // DEFAULTSTAGE_H_INCLUDED