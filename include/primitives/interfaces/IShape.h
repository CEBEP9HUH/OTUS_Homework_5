#pragma once

#include "IDrawable.h"
#include "IRotatable.h"
#include "IScalable.h"
#include "IMovable.h"

/**
*   @brief IShape2D is an abstract class which must be inherited by every class which implements primitive for drawing on canvas. It combines IDrawable, IRotatable, IScalable and IMovable abstract classes
**/
class IShape2D: public IDrawable, public IRotatable, public IScalable, public IMovable {
public:
    virtual ~IShape2D() {};
    [[maybe_unused]]static int calculateLength([[maybe_unused]]const int fromX, [[maybe_unused]]const int fromY, [[maybe_unused]]const int toX, [[maybe_unused]]const int toY) {int length = 0; /* convert points into length */ return length;};
};