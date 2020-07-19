#pragma once

#include "IModel.h"
#include "IController.h"
#include "Line.h"
#include "Circle.h"
#include "Square.h"
#include "Rectangle.h"

/**
 * @brief Model is a class which responsible for execution all user's commands
**/
class Model: public IModelWithController{
public:
    Model() : IModelWithController{} {};
    virtual ~Model();
    virtual void drawLine(const int fromX, const int fromY, const int toX, const int toY) override;
    virtual void drawCircle(const int fromX, const int fromY, const int toX, const int toY) override;
    virtual void drawSquare(const int fromX, const int fromY, const int toX, const int toY) override;
    virtual void drawRectangle(const int fromX, const int fromY, const int toX, const int toY) override;
    virtual void select(const int X, const int Y) override;
    virtual void setRotationCenter(const int _rotCenterX, const int _rotCenterY) override;
    virtual void rotateSelected(const int fromX, const int fromY, const int toX, const int toY) override;
    virtual void moveSelected(const int fromX, const int fromY, const int toX, const int toY) override;
    virtual void scaleSelected(const int fromX, const int fromY, const int toX, const int toY) override;
    virtual void saveDoc(const std::string& path) override;
    virtual void loadDoc(const std::string& path) override;
    virtual void createDoc(const std::string& path) override;
};