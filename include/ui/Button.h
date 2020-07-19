#pragma once

#include <string>
#include "ICallback.h"

/**
 * @brief Button class for get user's input
**/
template<typename callbackSignature = std::function<void(void)> >
class Button : public ICallback<callbackSignature> {
private:
    std::string _caption;
    int _posX, _posY;
    int _width, _height;
public:

    Button() : _posX{0}, _posY{0}, _width{0}, _height{0} {};
    Button(const callbackSignature callbackFunction) : ICallback<callbackSignature>{callbackFunction}, _posX{0}, _posY{0}, _width{0}, _height{0} {};
    Button(const int posX, const int posY,
            const int width, const int height) :    _posX{posX}, 
                                                    _posY{posY}, 
                                                    _width{width}, 
                                                    _height{height} {};

    virtual ~Button() {};
    void onClick() {
        this->callback();
    }
    void setCaption(const std::string& caption){
        _caption = caption;
    }
    void setPos(const int posX, const int posY){
        _posX = posX;
        _posY = posY;
    }
    void setSize(const int width, const int height){
        _width = width;
        _height = height;
    }
};