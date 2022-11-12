#ifndef IENTITY_H_INCLUDED
#define IENTITY_H_INCLUDED

#include <string>

class IEntity{
public:
    virtual std::string getName() = 0;
};

#endif // IENTITY_H_INCLUDED