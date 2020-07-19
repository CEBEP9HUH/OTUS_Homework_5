#pragma once

/**
*   @brief IMovable is an abstract class which must be inherited by every movable object's class 
**/
class IMovable{
public:
    virtual void move(const int deltaX, const int deltaY) = 0;
};