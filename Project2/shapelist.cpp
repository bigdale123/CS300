#include "gwindow.h"
#include "shape.h"
#include "shapelist.h"

void ShapeList::printShapeList() {
    std::cout << "{";
    for(int i = 0; i < this->size()-1; i++){
        std::cout << typeid(decltype(this->get(i))).name() << ", ";
    }
    std::cout << typeid(decltype(this->get(this->size()-1))).name() << "}" << std::endl;
}

void ShapeList::moveToFront(Shape *sp) {
    // Front of Window is Back of Vector
    for(int i = 0; i < this->size(); i++){
        if(this->get(i) == sp){
            Shape* temp = this->get(i);
            remove(i);
            insert(this->size(), temp);
        }
    }
}
void ShapeList::moveToBack(Shape *sp) {
    // Front of Window is Back of Vector
    for(int i = 0; i < this->size(); i++){
        if(this->get(i) == sp){
            Shape* temp = this->get(i);
            remove(i);
            insert(0, temp);
        }
    }
}
void ShapeList::moveForward(Shape *sp) {
    // Front of Window is Back of Vector
    for(int i = 0; i < this->size(); i++){
        if(this->get(i) == sp){
            Shape* temp = this->get(i);
            set(i, this->get(i+1));
            set(i+1, temp);
            break;
        }
    }
}
void ShapeList::moveBackward(Shape *sp) {
    // Front of Window is Back of Vector
    for(int i = 0; i < this->size(); i++){
        if(this->get(i) == sp){
            // Move to Back of Vector
            Shape* temp = this->get(i);
            set(i, this->get(i-1));
            set(i-1, temp);
            break;
        }
    }
}

Shape* ShapeList::getShapeAt(double x, double y) {
    for(int i = this->size()-1; i >= 0; i--){
        if(this->get(i)->contains(x,y)) {
            return this->get(i);
        }
    }
}