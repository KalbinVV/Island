#ifndef ITILE_H_INCLUDED
#define ITILE_H_INCLUDED

#include <string>

#include "World/Entity/IEntity.h"

class ITile{
public:
    virtual bool onMove(IEntity* source) = 0;
    virtual bool onUse(IEntity* source) = 0;
    virtual std::string getName() = 0;
};

#endif