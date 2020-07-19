#pragma once

#include "IRectangle.h"
/**
 * @brief Square is a class for create a square for drawing it on canvas  
**/
class Square: public IRectangle{
private:
    Point _topLeft;
    int _length;
public:
    Square(const Point topLeft, const int length) : IRectangle{calculateAngleCoords(topLeft, length, length)}, _topLeft{topLeft}, _length{length} {};
    virtual ~Square() {};
    virtual auto calculateAngleCoords([[maybe_unused]]const Point topLeft, [[maybe_unused]]const int width, [[maybe_unused]]const int height) -> decltype(_angles) override {/* calculate angles pos */return _angles; }; 
};