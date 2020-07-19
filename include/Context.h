#pragma once

/**
 * @brief Context class for "in-memory drawing" and update the canvas
**/
class Context{
public:
    void drawLine(const int begX, const int begY, const int endX, const int endY);
    void drawCircle(const int centerX, const int centerY, const int radius);
    void clear();
};