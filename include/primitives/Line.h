#pragma once

#include "Point.h"
#include "IShape.h"

/**
 * @brief Line is a class for create a line for drawing it on canvas  
**/
class Line: public IShape2D {
protected:
    Point _from;
    Point _to;
public:
    Line(const Point from, const Point to) : _from{from}, _to{to} {};
    [[maybe_unused]]virtual void draw([[maybe_unused]]Context& context) const override{std::cout << "Draw a line\n";};
    [[maybe_unused]]virtual void rotate([[maybe_unused]]const double angle, [[maybe_unused]]const int rotationCenterX, [[maybe_unused]]const int rotationCenterY) override{std::cout << "Rotate line\n";};
    [[maybe_unused]]virtual void move([[maybe_unused]][[maybe_unused]]const int deltaX, [[maybe_unused]]const int deltaY) override{std::cout << "Move line\n";};
    [[maybe_unused]]virtual void scale([[maybe_unused]]const double scaleX, [[maybe_unused]]const double scaleY) override{std::cout << "Scale line\n";};
};