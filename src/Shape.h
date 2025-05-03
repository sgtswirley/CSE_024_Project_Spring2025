#ifndef SHAPE_H
#define SHAPE_H

#include <GL/freeglut.h>
#include <GL/gl.h>


// Abstract Data Type
class Shape{

public:
    // This function is now pure virtual
    virtual void draw() = 0;

    virtual bool contains(float mx, float my) = 0;

    virtual float getX() const = 0;     // Added vitual
    virtual float getY() const = 0;
    // virtual void setPosition(float x, float y) = 0;


    virtual ~Shape(){}
};

#endif