#pragma once

#include <list>
#include <string>
#include "IShape.h"


/**
 * @brief IModel is an abstract class which provides you required minimum to create Model
**/
class IModel{
protected:
    using primitivesList = std::list<IShape2D*>;
    primitivesList _primitives;
    IShape2D* _selected;
    int _rotCenterX, _rotCenterY;
public:
    IModel() : _selected{nullptr} {};
    virtual ~IModel() {};
    primitivesList getPrimitives() {return _primitives;};
    virtual void drawLine(const int fromX, const int fromY, const int toX, const int toY) = 0;
    virtual void drawCircle(const int fromX, const int fromY, const int toX, const int toY) = 0;
    virtual void drawSquare(const int fromX, const int fromY, const int toX, const int toY) = 0;
    virtual void drawRectangle(const int fromX, const int fromY, const int toX, const int toY) = 0;
    virtual void select(const int X, const int Y) = 0;
    virtual void setRotationCenter(const int _rotCenterX, const int _rotCenterY) = 0;
    virtual void rotateSelected(const int fromX, const int fromY, const int toX, const int toY) = 0;
    virtual void moveSelected(const int fromX, const int fromY, const int toX, const int toY) = 0;
    virtual void scaleSelected(const int fromX, const int fromY, const int toX, const int toY) = 0;
    virtual void saveDoc(const std::string& path) = 0;
    virtual void loadDoc(const std::string& path) = 0;
    virtual void createDoc(const std::string& path) = 0;
};