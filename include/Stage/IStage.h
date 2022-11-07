#ifndef ISTAGE_H_INCLUDED
#define ISTAGE_H_INCLUDED

class IStage{
public:
    virtual void render() = 0;
    virtual void handleEvents() = 0;
    virtual ~IStage() {}
};

#endif // ISTAGE_H_INCLUDED