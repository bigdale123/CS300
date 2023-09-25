#ifndef _shape_h
#define _shape_h

#include <string>
#include <cmath>
#include "gwindow.h"

/**
 * @class Shape
 * @brief This is the base class for all shapes in the shape library. It defines common properties and methods that all shapes share.
 */
class Shape {
    public:
        /**
         * @brief Sets the location (coordinates) of the shape.
         * @param x The x-coordinate.
         * @param y The y-coordinate.
         */
        void setLocation(double x, double y);


        /**
         * @brief Moves the shape by a specified amount along the x and y axes.
         * @param x The amount to move along the x-axis.
         * @param y The amount to move along the y-axis.
         */
        void move(double x, double y);


        /**
         * @brief Sets the color of the shape.
         * @param color A string representing the color.
         */
        void setColor(std::string color);


        /**
         * @brief Draws the shape on the specified graphics window.
         *        This is a pure virtual function and must be implemented by derived classes.
         * @param gw The graphics window on which to draw the shape.
         */
        virtual void draw(GWindow & gw) = 0;


        /**
         * @brief Checks if the shape contains the specified point (x, y).
         *        This is a pure virtual function and must be implemented by derived classes.
         * @param x The x-coordinate of the point to check.
         * @param y The y-coordinate of the point to check.
         * @return true if the shape contains the point, false otherwise.
         */
        virtual bool contains(double x, double y) = 0; 
        
    protected:
        /**
         * @brief Constructor for the Shape class. Initializes common properties.
         */
        Shape();
        std::string color;  // The color of the shape.
        double x,y;         // The x and y coordinates of the shape's location.
        
};



/**
 * @class Line
 * @brief Represents a line segment defined by two points. Derived from Shape.
 */
class Line : public Shape {
    public:
        /**
         * @brief Constructor for Line.
         * @param x1 The x-coordinate of the first point.
         * @param y1 The y-coordinate of the first point.
         * @param x2 The x-coordinate of the second point.
         * @param y2 The y-coordinate of the second point.
         */
        Line(double x1, double y1, double x2, double y2);


        /**
         * @brief Draws the shape on the specified graphics window.
         *        This is a pure virtual function and must be implemented by derived classes.
         * @param gw The graphics window on which to draw the shape.
         */
        virtual void draw(GWindow & gw);


        /**
         * @brief Checks if the shape contains the specified point (x, y).
         *        This is a pure virtual function and must be implemented by derived classes.
         * @param x The x-coordinate of the point to check.
         * @param y The y-coordinate of the point to check.
         * @return true if the shape contains the point, false otherwise.
         */
        virtual bool contains(double x, double y);
        
    private:
        double dx;      // The distance between the 2 X coordinates
        double dy;      // The distance between the 2 Y coordinates
        
};



/**
 * @class Rect
 * @brief Represents a rectangular shape defined by a position, width, and height. Derived from Shape.
 */
class Rect : public Shape {
    public:
        /**
         * @brief Constructor for Rect.
         * @param x The x-coordinate of the top-left corner of the rectangle.
         * @param y The y-coordinate of the top-left corner of the rectangle.
         * @param width The width of the rectangle.
         * @param height The height of the rectangle.
         */
        Rect(double x, double y, double width, double height);


        /**
         * @brief Draws the shape on the specified graphics window.
         *        This is a pure virtual function and must be implemented by derived classes.
         * @param gw The graphics window on which to draw the shape.
         */
        virtual void draw(GWindow & gw);


        /**
         * @brief Checks if the shape contains the specified point (x, y).
         *        This is a pure virtual function and must be implemented by derived classes.
         * @param x The x-coordinate of the point to check.
         * @param y The y-coordinate of the point to check.
         * @return true if the shape contains the point, false otherwise.
         */
        virtual bool contains(double x, double y);
        
    private:
        double width, height;       // The width and Height of the Rectangle
        
};



/**
 * @class Square
 * @brief Represents a square shape defined by a position and a side length. Derived from Shape.
 */
class Square : public Shape {
    public:
        /**
         * @brief Constructor for Square.
         * @param x The x-coordinate of the top-left corner of the square.
         * @param y The y-coordinate of the top-left corner of the square.
         * @param size The side length of the square.
         */
        Square(double x, double y, double size);


        /**
         * @brief Draws the shape on the specified graphics window.
         *        This is a pure virtual function and must be implemented by derived classes.
         * @param gw The graphics window on which to draw the shape.
         */
        virtual void draw(GWindow & gw);


        /**
         * @brief Checks if the shape contains the specified point (x, y).
         *        This is a pure virtual function and must be implemented by derived classes.
         * @param x The x-coordinate of the point to check.
         * @param y The y-coordinate of the point to check.
         * @return true if the shape contains the point, false otherwise.
         */
        virtual bool contains(double x, double y);

    private:
        double size;        // The length of any given side of the square

};


/**
 * @class Oval
 * @brief Represents an oval shape defined by a position, width, and height. Derived from Shape.
 */
class Oval : public Shape {
    public:
        /**
         * @brief Constructor for Oval.
         * @param x The x-coordinate of the center of the oval.
         * @param y The y-coordinate of the center of the oval.
         * @param width The width of the oval.
         * @param height The height of the oval.
         */
        Oval(double x, double y, double width, double height);


        /**
         * @brief Draws the shape on the specified graphics window.
         *        This is a pure virtual function and must be implemented by derived classes.
         * @param gw The graphics window on which to draw the shape.
         */
        virtual void draw(GWindow & gw);


        /**
         * @brief Checks if the shape contains the specified point (x, y).
         *        This is a pure virtual function and must be implemented by derived classes.
         * @param x The x-coordinate of the point to check.
         * @param y The y-coordinate of the point to check.
         * @return true if the shape contains the point, false otherwise.
         */
        virtual bool contains(double x, double y);

    private:
        double width, height;       // The width and Height of the Ellipse / Oval
        
};

#endif