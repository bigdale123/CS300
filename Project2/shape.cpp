#include <string>
#include "gwindow.h"
#include "shape.h"


Shape::Shape() {
    setColor("BLACK");
}

void Shape::setLocation(double x, double y) {
    this->x = x;
    this->y = y;
}

void Shape::move(double dx, double dy) {
    x += dx;
    y += dy;
}

void Shape::setColor(string color) {
    this->color = color;
}

Line::Line(double x1, double y1, double x2, double y2) {
    this->x = x1;
    this->y = y1;
    this->dx = x2 - x1;
    this->dy = y2 - y1;
}

void Line::draw(GWindow & gw) {
    gw.setColor(color);
    gw.drawLine(x, y, x + dx, y + dy);
}

bool Line::contains(double x, double y) {
    // If a point is plugged in using the same slope as the given line, and has the same y intercept, then the point must lie on the line.
    double line_slope = this->dy/this->dx; // Slope of this line
    double line_offset = this->y - line_slope*this->x; // y-int of this line
    double point_offset = y - line_slope*x; // y-int of this line
    if(line_offset == point_offset) {
        return true;
    }
    else{
        return false;
    }
}

Rect::Rect(double x, double y, double width, double height) {
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
}

void Rect::draw(GWindow & gw) {
    gw.setColor(color);
    gw.fillRect(x, y, width, height);
}

bool Rect::contains(double x, double y) {
    // Probably not necessary, but reference:
    // https://math.stackexchange.com/questions/2157931/how-to-check-if-a-point-is-inside-a-square-2d-plane
    if ((this->x <= x && x <= this->x + this->width) && (this->y <= y && y <= this->y + this->height)) {
        return true;
    }
    else{
        return false;
    }
}

Square::Square(double x, double y, double size) {
    this->x = x;
    this->y = y;
    this->size = size;
}

void Square::draw(GWindow & gw) {
    gw.setColor(color);
    gw.fillRect(x, y, size, size);
}

bool Square::contains(double x, double y) {
    // Self Explanatory, same as rectangle
    if ((this->x <= x && x <= this->x + this->size) && (this->y <= y && y <= this->y + this->size)) {
        return true;
    }
    else{
        return false;
    }
}

Oval::Oval(double x, double y, double width, double height) {
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
}

void Oval::draw(GWindow & gw) {
    gw.setColor(color);
    gw.fillOval(x, y, width, height);
}

bool Oval::contains(double x, double y) {
    //https://math.stackexchange.com/questions/76457/check-if-a-point-is-within-an-ellipse
    double ellipse_test = (pow(x-this->x,2)/pow(this->width,2)) + (pow(y-this->y,2)/pow(this->height,2));
    if (ellipse_test <= 1) {
        return true;
    }
    else {
        return false;
    }
}