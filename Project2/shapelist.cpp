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
            // I saw this, https://stackoverflow.com/questions/37901353/how-can-i-move-an-element-to-the-end-of-a-vector
            // But then was like "that's too much" and just removed the pointer and restored it at the end of the list.
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
            // I saw this, https://stackoverflow.com/questions/37901353/how-can-i-move-an-element-to-the-end-of-a-vector
            // But then was like "that's too much" and just removed the pointer and restored it at the end of the list.
            remove(i);
            insert(0, temp);
        }
    }
}
void ShapeList::moveForward(Shape *sp) {
    // Front of Window is Back of Vector
    for(int i = 0; i < this->size(); i++){
        if(this->get(i) == sp){
            // Move to Back of Vector
            Shape* temp = this->get(i);
            // Tried using insert, didn't work. Found set in the documentation.
            // https://en.cppreference.com/w/cpp/container/set
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
            // Move to Front of Vector
            Shape* temp = this->get(i);
            // Tried using insert, didn't work. Found set in the documentation.
            // https://en.cppreference.com/w/cpp/container/set
            set(i, this->get(i-1));
            set(i-1, temp);
            break;
        }
    }
}

void ShapeList::draw(GWindow & gw) const {
    for(int i = 0; i < this->size(); i++){
        this->get(i)->draw(gw);
    }
}

Shape* ShapeList::getShapeAt(double x, double y) {
    // Pretty self explanatory, start at back of vector (or front of window) and check if that shape contains the point.
    // If it does, it's the front-most shape and we return it.
    for(int i = this->size()-1; i >= 0; i--){
        if(this->get(i)->contains(x,y)) {
            return this->get(i);
        }
    }
}