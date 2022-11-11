#include "Core/Vec2i.h"

Vec2i::Vec2i()
{
    x = 0;
    y = 0;
}

Vec2i::Vec2i(int x, int y)
{
    this->x = x;
    this->y = y;
}

Vec2i Vec2i::addX(int value)
{
    Vec2i newVec = Vec2i(x, y);
    newVec.x += value;
    return newVec;
}

Vec2i Vec2i::addY(int value)
{
    Vec2i newVec = Vec2i(x, y);
    newVec.y += value;
    return newVec;
}