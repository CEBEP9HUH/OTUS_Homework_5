#pragma once

#include <array>
#include "Point.h"
#include "IShape.h"

/**
*   @brief IRectangle is an abstract class which must be inherited by every class which implements closed shape with 4 right angles
**/
class IRectangle : public IShape2D {
protected:
    std::array<Point, 4> _angles;
public:
    IRectangle(const std::array<Point, 4>& angles) : _angles{angles} {};
    virtual ~IRectangle() {};
    virtual auto calculateAngleCoords([[maybe_unused]]const Point topLeft, [[maybe_unused]]const int width, [[maybe_unused]]const int height) -> decltype(_angles) = 0; 
    [[maybe_unused]]virtual void draw([[maybe_unused]]Context& context) const override{std::cout << "Draw a polygon\n";};
    [[maybe_unused]]virtual void rotate([[maybe_unused]]const double angle, [[maybe_unused]]const int rotationCenterX, [[maybe_unused]]const int rotationCenterY) override{std::cout << "Rotate polygon\n";};
    [[maybe_unused]]virtual void move([[maybe_unused]][[maybe_unused]]const int deltaX, [[maybe_unused]]const int deltaY) override{std::cout << "Move polygon\n";};
    [[maybe_unused]]virtual void scale([[maybe_unused]]const double scaleX, [[maybe_unused]]const double scaleY) override{std::cout << "Scale polygon\n";};
};