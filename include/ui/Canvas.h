#pragma once

#include <iostream>
#include "ICallback.h"
#include "Context.h"


/**
 * @brief Canvas class for drawing on it
**/
template<typename callbackSignature = std::function<void(void)> >
class Canvas : public ICallback<callbackSignature> {
protected:
    struct Coords{
        int posX;
        int posY;
    } _clickCoord, _releaseCoord;
    Context _context;
public:
    Canvas(const callbackSignature callbackFunction) : ICallback<callbackSignature>{callbackFunction}, _clickCoord{0,0}, _releaseCoord{0,0} {};
    virtual ~Canvas() {};
    void onClick(){
        _clickCoord.posX = 1;
        _clickCoord.posY = 2;
        // clickCoord.posX = mouse.X;
        // clickCoord.posY = mouse.Y;
    };
    void onRelease(){
        _releaseCoord.posX = 10;
        _releaseCoord.posY = 20;
        // releaseCoord.posX = mouse.X;
        // releaseCoord.posY = mouse.Y;
        this->callback(_clickCoord.posX, _clickCoord.posY, _releaseCoord.posX, _releaseCoord.posY);
    };
    void redraw(Context& context){ _context = context;/* redraw context */ std::cout << "Redraw canvas\n";};
    Context& getContext() {return _context;};
};