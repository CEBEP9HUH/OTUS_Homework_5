#pragma once

#include <functional>

/**
 * @brief ICallback is an abstract class which provides ability to use calback functions (uses signature as a template) 
**/
template<typename signature = std::function<void(void)> >
class ICallback{
protected:
    signature _callBackFunction;
    ICallback(const signature callbackFunction) : _callBackFunction{callbackFunction} {};
    void setCallbackFunction(const signature callbackFunction){
        _callBackFunction = callbackFunction;
    }
    template<typename... Args>
    void callback(Args... args){
        _callBackFunction(args...);
    }
public:
    ICallback();
    virtual ~ICallback() {};
};