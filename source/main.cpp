#include <iostream>

#include "UI.h"
#include "Controller.h"
#include "Model.h"

/**
 * @mainpage Painter model
 * Is a painter model 
**/

int main(){
    UI* _ui = new UI;
    Model* _model = new Model;
    Controller* _c = new Controller(_model, _ui);
    _ui->setController(_c);
    _model->setController(_c);

    _ui->createDoc_click();

    _ui->_lineTool->onClick();
    _ui->getCanvas()->onClick();
    _ui->getCanvas()->onRelease();

    _ui->_circleTool->onClick();
    _ui->getCanvas()->onClick();
    _ui->getCanvas()->onRelease();

    _ui->_squareTool->onClick();
    _ui->getCanvas()->onClick();
    _ui->getCanvas()->onRelease();

    _ui->_rectangleTool->onClick();
    _ui->getCanvas()->onClick();
    _ui->getCanvas()->onRelease();
    
    _ui->_cursorTool->onClick();
    _ui->getCanvas()->onClick();
    _ui->getCanvas()->onRelease();
    
    _ui->_setRotationCenterTool->onClick();
    _ui->getCanvas()->onClick();
    _ui->getCanvas()->onRelease();

    _ui->_rotationTool->onClick();
    _ui->getCanvas()->onClick();
    _ui->getCanvas()->onRelease();

    _ui->_moveTool->onClick();
    _ui->getCanvas()->onClick();
    _ui->getCanvas()->onRelease();

    _ui->_scaleTool->onClick();
    _ui->getCanvas()->onClick();
    _ui->getCanvas()->onRelease();

    _ui->saveDoc_click();
    _ui->loadDoc_click();
    
    delete _c;
    return 0;
}