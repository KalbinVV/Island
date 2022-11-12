#ifndef TILEDELEGATESSTORAGE_H_INCLUDED
#define TILEDELEGATESSTORAGE_H_INCLUDED

#include <functional>

#include "World/Tile/TileDelegateEnum.h"
#include "World/Entity/IEntity.h"
#include "World/Tile/ITile.h"

class TileDelegatesStorage{
public:
    static std::function<bool(ITile*, IEntity*)> getFunction(TileDelegateEnum tileDelegateEnum);
};

#endif // TILEDELEGATESSTORAGE_H_INCLUDED