#pragma once

/**
*   @brief IRotatable is an abstract class which must be inherited by every rotatable object's class 
**/
class IRotatable{
public:
    virtual void rotate(const double angle, const int rotationCenterX, const int rotationCenterY) = 0;
};