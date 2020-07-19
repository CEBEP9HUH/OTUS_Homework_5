#pragma once

/**
*   @brief IScalable is an abstract class which must be inherited by every scalable object's class 
**/
class IScalable{
public:
    virtual void scale(const double scaleX, const double scaleY) = 0;
};