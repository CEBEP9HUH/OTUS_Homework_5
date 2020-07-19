#pragma once

#include <tuple>
#include "IRotatable.h"
#include "IMovable.h"
/**
 * @brief Point is a class for create a point as which can be moved or ratated  
**/
class Point : public IRotatable, public IMovable{
protected:
    using coords = std::pair<int, int>;
    coords _pos;
public:
    Point(const int x, const int y) : _pos{x, y} {};
    virtual ~Point() {};
    void setCenter(const int x, const int y);
    [[maybe_unused]]virtual void rotate([[maybe_unused]]const double angle, [[maybe_unused]]const int rotationCenterX, [[maybe_unused]]const int rotationCenterY) override{};
    [[maybe_unused]]virtual void move([[maybe_unused]]const int deltaX, [[maybe_unused]]const int deltaY) override{};
};