#include "UI.h"

UI::UI() : IUIWithController{} {
    _createDoc      = std::make_shared<ButtonType >(ButtonType(std::bind(&UI::createDoc_click, this)));
    _saveDoc        = std::make_shared<ButtonType >(ButtonType(std::bind(&UI::saveDoc_click, this)));
    _loadDoc        = std::make_shared<ButtonType >(ButtonType(std::bind(&UI::loadDoc_click, this)));
    _cursorTool     = std::make_shared<ButtonType >(ButtonType(std::bind(&UI::cursorTool_click, this)));
    _lineTool       = std::make_shared<ButtonType >(ButtonType(std::bind(&UI::lineTool_click, this)));
    _circleTool     = std::make_shared<ButtonType >(ButtonType(std::bind(&UI::circleTool_click, this)));
    _squareTool     = std::make_shared<ButtonType >(ButtonType(std::bind(&UI::squareTool_click, this)));
    _rectangleTool  = std::make_shared<ButtonType >(ButtonType(std::bind(&UI::rectangleTool_click, this)));
    _rotationTool   = std::make_shared<ButtonType >(ButtonType(std::bind(&UI::rotationTool_click, this)));
    _scaleTool      = std::make_shared<ButtonType >(ButtonType(std::bind(&UI::scaleTool_click, this)));
    _moveTool       = std::make_shared<ButtonType >(ButtonType(std::bind(&UI::moveTool_click, this)));
    _setRotationCenterTool       = std::make_shared<ButtonType >(ButtonType(std::bind(&UI::setRotationCenterTool_click, this)));
}

void UI::createDoc_click(){
    if(_controller != nullptr){
        std::string path = "";
        /* get path */
        _controller->sendCommand(Commands::createCommand, path);
    }
}

void UI::saveDoc_click(){
    if(_controller != nullptr){
        std::string path = "";
        /* get path */
        _controller->sendCommand(Commands::saveCommand, path);
    }
}

void UI::loadDoc_click(){
    if(_controller != nullptr){
        std::string path = "";
        /* get path */
        _controller->sendCommand(Commands::loadCommand, path);
    }
}

void UI::cursorTool_click(){
    if(_controller != nullptr){
        _controller->setCurrentTool(Toolset::cursorTool);
    }
}

void UI::lineTool_click(){
    if(_controller != nullptr){
        _controller->setCurrentTool(Toolset::lineTool);
    }
}

void UI::circleTool_click(){
    if(_controller != nullptr){
        _controller->setCurrentTool(Toolset::circleTool);
    }
}

void UI::squareTool_click(){
    if(_controller != nullptr){
        _controller->setCurrentTool(Toolset::squareTool);
    }
}

void UI::rectangleTool_click(){
    if(_controller != nullptr){
        _controller->setCurrentTool(Toolset::rectangleTool);
    }
}


void UI::setRotationCenterTool_click(){
    if(_controller != nullptr){
        _controller->setCurrentTool(Toolset::setRotationCenter);
    }
}

void UI::rotationTool_click(){
    if(_controller != nullptr){
        _controller->setCurrentTool(Toolset::rotationTool);
    }
}

void UI::scaleTool_click(){
    if(_controller != nullptr){
        _controller->setCurrentTool(Toolset::scaleTool);
    }
}

void UI::moveTool_click(){
    if(_controller != nullptr){
        _controller->setCurrentTool(Toolset::moveTool);
    }
}

void UI::canvasEvent(const int fromX, const int fromY, const int toX, const int toY){
    if(_controller != nullptr){
        _controller->useTool(fromX, fromY, toX, toY);
    }
}

void UI::deletePrimitive(){
    
}