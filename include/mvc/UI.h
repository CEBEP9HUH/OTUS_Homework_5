#pragma once

#include "Button.h"
#include "IUI.h"
#include "IController.h"

/**
 * @brief UI is a class which responsible for get all user's commands and send it to Model (by Controller)
**/
class UI: public IUIWithController{
private:
    using ButtonType = Button<std::function<void(void)> >;
public:
    std::shared_ptr<ButtonType > _createDoc;
    std::shared_ptr<ButtonType > _saveDoc;
    std::shared_ptr<ButtonType > _loadDoc;
    std::shared_ptr<ButtonType > _cursorTool;
    std::shared_ptr<ButtonType > _lineTool;
    std::shared_ptr<ButtonType > _circleTool;
    std::shared_ptr<ButtonType > _squareTool;
    std::shared_ptr<ButtonType > _rectangleTool;
    std::shared_ptr<ButtonType > _rotationTool;
    std::shared_ptr<ButtonType > _scaleTool;
    std::shared_ptr<ButtonType > _moveTool;
    std::shared_ptr<ButtonType > _setRotationCenterTool;
    UI();
    virtual ~UI() {};
    void cursorTool_click();
    void lineTool_click();
    void circleTool_click();
    void squareTool_click();
    void rectangleTool_click();
    void createDoc_click();
    void saveDoc_click();
    void loadDoc_click();
    void rotationTool_click();
    void scaleTool_click();
    void moveTool_click();
    void setRotationCenterTool_click();
    virtual void canvasEvent(const int fromX, const int fromY, const int toX, const int toY) override;
    virtual void deletePrimitive() override;
};