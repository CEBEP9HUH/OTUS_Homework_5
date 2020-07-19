#pragma once

#include "Point.h"
#include "IShape.h"

/**
 * @brief Circle is a class for create a circle for drawing it on canvas  
**/
class Circle: public IShape2D {
    Point _topLeft;
    unsigned int _radius;
public:
    Circle(const Point topLeft, const unsigned int radius) : _topLeft{topLeft}, _radius{radius} {};
    [[maybe_unused]]virtual void draw([[maybe_unused]]Context& context) const override{ std::cout << "Draw a circle\n"; };
    [[maybe_unused]]virtual void rotate([[maybe_unused]]const double angle, [[maybe_unused]]const int rotationCenterX, [[maybe_unused]]const int rotationCenterY) override{std::cout << "Rotate circle\n";};
    [[maybe_unused]]virtual void move([[maybe_unused]][[maybe_unused]]const int deltaX, [[maybe_unused]]const int deltaY) override{std::cout << "Move circle\n";};
    [[maybe_unused]]virtual void scale([[maybe_unused]]const double scaleX, [[maybe_unused]]const double scaleY) override{std::cout << "Scale circle\n";};
};