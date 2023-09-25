#include <iostream>
#include "gwindow.h"
#include "shape.h"
#include "shapelist.h"
#include <vector>

int main() {
    GWindow gw;
    double width = gw.getWidth();
    double height = gw.getHeight();
    Rect *rp = new Rect(width/4, height/4, width/2, height/2);
    Oval *op = new Oval(width/4, height/4, width/2, height/2);
    rp->setColor("BLUE");
    op->setColor("GRAY");
    ShapeList shapes;
    shapes.add(new Line(0, height/2, width/2, 0));
    shapes.add(new Line(width/2, 0, width, height/2));
    shapes.add(new Line(width, height/2, width/2, height));
    shapes.add(new Line(width/2, height, 0, height/2));
    shapes.add(new Square(width/2, 0, height/2));
    shapes.add(rp);
    shapes.add(op);
    //shapes.printShapeList();
    shapes.moveBackward(op);
    if(shapes.getShapeAt(width/4,height/4) == rp){
        std::cout << "Pogging" << std::endl;
    }

    for (Shape *sp : shapes) {
        sp->draw(gw);
    }
    for (Shape *sp : shapes) {
        delete sp;
    }
    shapes.clear();
    return 0;
}