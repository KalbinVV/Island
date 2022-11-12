#ifndef TILEDELEGATE_H_INCLUDED
#define TILEDELEGATE_H_INCLUDED

#include <list>
#include <functional>   

#include "World/Tile/ITile.h"
#include "World/Entity/IEntity.h"

class TileDelegate{
private:
    std::list<std::function<bool(ITile*, IEntity*)>> _invocationList;
public:
    void operator = (std::function<bool(ITile*, IEntity*)> func);
    void operator += (std::function<bool(ITile*, IEntity*)> func);
    bool operator ()(ITile* tile, IEntity* source);
};

#endif // TILEDELEGATE_H_INCLUDED