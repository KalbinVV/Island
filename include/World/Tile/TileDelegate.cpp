#include "World/Tile/TileDelegate.h"

void TileDelegate::operator=(std::function<bool(ITile*, IEntity*)> func)
{
    _invocationList.clear();
    _invocationList.push_back(func);
}

void TileDelegate::operator+=(std::function<bool(ITile*, IEntity*)> func)
{
    _invocationList.push_back(func);
}

bool TileDelegate::operator()(ITile* tile, IEntity* source)
{
    bool isSuccessfulFlag = true;
    for(const auto& func : _invocationList) {
        isSuccessfulFlag &= func(tile, source);
    }
    return isSuccessfulFlag;
}