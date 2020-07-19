#pragma once

#include <iostream>
#include "Context.h"

/**
*   @brief IDrawable is an abstract class which must be inherited by every drawable object's class 
**/
class IDrawable{
public:
    virtual void draw(Context& context) const = 0;
};