#ifndef _shape_h
#define _shape_h

#include <string>
#include <cmath>
#include "gwindow.h"

class Shape {
    public:
        // Begin Boilerplate/Starter Code
        void setLocation(double x, double y);
        void move(double x, double y);
        void setColor(std::string color);
        virtual void draw(GWindow & gw) = 0;
        virtual bool contains(double x, double y) = 0; 
        // End Boilerplate/Starter Code
    protected:
        // Begin Boilerplate/Starter Code
        Shape();
        std::string color;
        double x,y;
        // End Boilerplate/Starter Code
};

class Line : public Shape {
    public:
        // Begin Boilerplate/Starter Code
        Line(double x1, double y1, double x2, double y2);
        virtual void draw(GWindow & gw);
        virtual bool contains(double x, double y);
        // End Boilerplate/Starter Code
    private:
        // Begin Boilerplate/Starter Code
        double dx;
        double dy;
        // End Boilerplate/Starter Code
};

class Rect : public Shape {
    public:
        // Begin Boilerplate/Starter Code
        Rect(double x, double y, double width, double height);
        virtual void draw(GWindow & gw);
        virtual bool contains(double x, double y);
        // End Boilerplate/Starter Code
    private:
        // Begin Boilerplate/Starter Code
        double width, height;
        // End Boilerplate/Starter Code
};

class Square : public Shape {
    public:
        Square(double x, double y, double size);
        virtual void draw(GWindow & gw);
        virtual bool contains(double x, double y);
    private:
        double size;

};

class Oval : public Shape {
    public:
        // Begin Boilerplate/Starter Code
        Oval(double x, double y, double width, double height);
        virtual void draw(GWindow & gw);
        virtual bool contains(double x, double y);
        // End Boilerplate/Starter Code
    private:
        // Begin Boilerplate/Starter Code
        double width, height;
        // End Boilerplate/Starter Code
};

#endif