#pragma once

#include <memory>
#include "Canvas.h"

/**
 * @brief IUI is an abstract class which provides you required minimum to create UI class
**/
class IUI{
protected:
    using canvas_t = Canvas<std::function<void(const int, const int, const int, const int)> >;
    std::shared_ptr<canvas_t> _canvas;
public:
    IUI(){
        using namespace std::placeholders;
        _canvas = std::make_shared<canvas_t>(canvas_t(std::bind(&IUI::canvasEvent, this, _1, _2, _3, _4)));
    };
    virtual ~IUI() {};
    virtual void canvasEvent(const int fromX, const int fromY, const int toX, const int toY) = 0;
    virtual void deletePrimitive() = 0;
    std::shared_ptr<canvas_t> getCanvas() {return _canvas;};
};