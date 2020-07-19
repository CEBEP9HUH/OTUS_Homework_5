#include "Model.h"

Model::~Model(){
    for(auto& primitive : _primitives){
        delete primitive;
    }
}

void Model::drawLine(const int fromX, const int fromY, const int toX, const int toY){
    _primitives.push_back(new Line(Point(fromX, fromY), Point(toX, toY)));
}

void Model::drawCircle(const int fromX, const int fromY, const int toX, const int toY){
    auto radius = Circle::calculateLength(fromX, fromY, toX, toY) / 2;
    _primitives.push_back(new Circle(Point(fromX, fromY), radius));
}

void Model::drawSquare(const int fromX, const int fromY, const int toX, const int toY){
    auto length = Rectangle::calculateLength(fromX, fromY, toX, toY);
    _primitives.push_back(new Square(Point(fromX, fromY), length));
}

void Model::drawRectangle(const int fromX, const int fromY, const int toX, const int toY){
    auto width = Rectangle::calculateLength(fromX, 0, toX, 0);
    auto height = Rectangle::calculateLength(0, fromY, 0, toY);
    _primitives.push_back(new Rectangle(Point(fromX, fromY), width, height));
}

void Model::select([[maybe_unused]]const int fromX, [[maybe_unused]]const int fromY){
    if(!_primitives.empty()){
        _selected = *_primitives.begin();
    }
    /* _selected =  shape which has been clicked on or nullptr otherwise */
}

void Model::setRotationCenter(const int rotCenterX, const int rotCenterY){
    _rotCenterX = rotCenterX;
    _rotCenterY = rotCenterY;
}

void Model::rotateSelected([[maybe_unused]]const int fromX, [[maybe_unused]]const int fromY, [[maybe_unused]]const int toX, [[maybe_unused]]const int toY){
    if(_selected != nullptr){
        double angle = 0;
        /* calculate angle of rotation from points */
        _selected->rotate(angle, _rotCenterX, _rotCenterY);
    }
}

void Model::moveSelected(const int fromX, const int fromY, const int toX, const int toY){
    if(_selected != nullptr){
        int deltaX = fromX - toX;
        int deltaY = fromY - toY;
        _selected->move(deltaX, deltaY);
    }
}

void Model::scaleSelected(const int fromX, const int fromY, const int toX, const int toY){
    if(_selected != nullptr){
        int scaleX = fromX - toX;
        int scaleY = fromY - toY;
        _selected->scale(scaleX, scaleY);
    }
}

void Model::saveDoc([[maybe_unused]]const std::string& path){
    std::cout << "Save document\n";
}

void Model::loadDoc([[maybe_unused]]const std::string& path){
    std::cout << "Load document\n";
}


void Model::createDoc([[maybe_unused]]const std::string& path){
    std::cout << "Create document\n";
}