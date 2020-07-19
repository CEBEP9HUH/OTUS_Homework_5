#pragma once

#include <memory>
#include "IModel.h"
#include "IUI.h"

/** 
*    @brief Toolset is an enum class which contains identifiers of every accessable tool
**/
enum class Toolset : unsigned long{
    cursorTool          = 0,
    lineTool            = 1,
    circleTool          = 2,
    squareTool          = 3,
    rectangleTool       = 4,
    rotationTool        = 100,
    scaleTool           = 101,
    moveTool            = 102,
    setRotationCenter   = 103
};

/** 
*   @brief Commands is an enum class which contains all accessable commands
**/
enum class Commands : unsigned long{
    saveCommand     = 1,
    loadCommand     = 2,
    createCommand   = 3
};

/**
*    @brief IController is an abstract class which defines pure virtual functions you have to realise to create your own controller compatible with Model and UI. 
**/
class IController{
protected:
    Toolset _currentTool = Toolset::cursorTool;
    std::shared_ptr<IModel> _model;
    std::shared_ptr<IUI> _ui;
public:
    IController(IModel* model, IUI* ui) : _model{model}, _ui{ui} {};
    virtual ~IController() {};
    std::shared_ptr<IModel>& getModel() {return _model;};
    std::shared_ptr<IUI>& getUI() {return _ui;};
    virtual void setCurrentTool(Toolset tool) = 0;
    virtual void useTool(const int fromX, const int fromY, const int toX = 0, const int toY = 0) = 0;
    virtual void sendCommand(Commands cmd, const std::string& path) = 0;
    virtual void updateCanvas() = 0;
};

/**  
 *  @brief IHasController is an abstract class which you have to inherit from in yours implementation of Model and UI classes with Controller supportion
 **/
class IHasController{
protected:
    IController* _controller;
public: 
    IHasController(){};
    virtual ~IHasController() {};
    void setController(IController* controller) {_controller = controller; };
};

/**
 * @brief IModelWithController is an abstract class which adds abbility to get Controller for Model class
**/
class IModelWithController: public IModel, public IHasController{
public:
    IModelWithController() : IModel{}, IHasController{} {};
    virtual ~IModelWithController() {};
};

/**
 * @brief IUIWithController is an abstract class which adds abbility to get Controller for UI class
**/
class IUIWithController: public IUI, public IHasController{
public:
    IUIWithController() : IUI{}, IHasController{} {};
    virtual ~IUIWithController() {};
};