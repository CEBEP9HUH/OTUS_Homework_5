#include "Controller.h"

/**
 * @brief Set current tool selected by yser
 * @param tool is Toolset's value for selected tool 
**/
void Controller::setCurrentTool(Toolset tool){
    _currentTool = tool;
}

/**
 * @brief Send command for file creation/saving/loading from user UI to Model
 * @param cmd is Commands's value for command
 * @param path is a const std::string reference to a file's path 
**/
void Controller::sendCommand(Commands cmd, const std::string& path){
    switch(cmd){
    case Commands::saveCommand: _model->saveDoc(path); break;
    case Commands::loadCommand: _model->loadDoc(path); break;
    case Commands::createCommand: _model->createDoc(path);break;
    }
}

/**
 * @brief Calls handler for selected tool
 * @param fromX is a X coordinate of begin point from canvas (mouse left button pressed)
 * @param fromY is a Y coordinate of begin point from canvas (mouse left button pressed)
 * @param toX is a X coordinate of end point from canvas (mouse left button released) 
 * @param toY is a Y coordinate of end point from canvas (mouse left button released) 
**/
void Controller::useTool([[maybe_unused]]const int fromX, [[maybe_unused]]const int fromY, [[maybe_unused]]const int toX, [[maybe_unused]]const int toY){
    switch(_currentTool){
    case Toolset::cursorTool: _model->select(toX, toY); break;
    case Toolset::lineTool: _model->drawLine(fromX, fromY, toX, toY); updateCanvas(); break;
    case Toolset::circleTool: _model->drawCircle(fromX, fromY, toX, toY); updateCanvas(); break;
    case Toolset::squareTool: _model->drawSquare(fromX, fromY, toX, toY); updateCanvas(); break;
    case Toolset::rectangleTool: _model->drawRectangle(fromX, fromY, toX, toY); updateCanvas(); break;
    case Toolset::rotationTool: _model->rotateSelected(fromX, fromY, toX, toY); updateCanvas(); break;
    case Toolset::scaleTool: _model->scaleSelected(fromX, fromY, toX, toY); updateCanvas(); break;
    case Toolset::moveTool: _model->moveSelected(fromX, fromY, toX, toY); updateCanvas(); break;
    case Toolset::setRotationCenter: _model->setRotationCenter(toX, toY); break;
    }
}


/**
 * @brief Updates canvas
**/
void Controller::updateCanvas(){
    auto primitives = _model->getPrimitives();
    auto canvas = _ui->getCanvas();
    auto context = canvas->getContext();

    for(const auto& primitive : primitives){
        primitive->draw(context);
    }
    canvas->redraw(context);
}