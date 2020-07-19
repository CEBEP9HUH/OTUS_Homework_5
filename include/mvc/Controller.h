#pragma once

#include <memory>
#include "IShape.h"
#include "IController.h"


/**
 * @brief Controller is a class which provides you tools to support exchange between Model and UI
**/
class Controller : public IController{
public:
    Controller(IModel* model, IUI* ui) : IController{model, ui} {};
    virtual ~Controller() {};
    virtual void setCurrentTool(Toolset tool) override;
    virtual void useTool(const int fromX, const int fromY, const int toX = 0, const int toY = 0) override;
    virtual void sendCommand(Commands cmd, const std::string& path) override;
    virtual void updateCanvas() override;
};