#pragma once

#include "IRectangle.h"

/**
 * @brief Rectangle is a class for create a rectangle for drawing it on canvas  
**/
class Rectangle: public IRectangle{
private:
    Point _topLeft;
    int _width;
    int _height;
public:
    Rectangle(const Point topLeft, const int width, const int height) : IRectangle{calculateAngleCoords(topLeft, width, height)}, _topLeft{topLeft}, _width{width}, _height{height} {};
    virtual ~Rectangle(){};
    virtual auto calculateAngleCoords([[maybe_unused]]const Point topLeft, [[maybe_unused]]const int width, [[maybe_unused]]const int height) -> decltype(_angles) override {/* calculate angles pos */return _angles; }; 
};