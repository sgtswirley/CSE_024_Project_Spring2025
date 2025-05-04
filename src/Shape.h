#ifndef SHAPE_H
#define SHAPE_H

#include <GL/freeglut.h>
#include <GL/gl.h>

    class Shape {
    public:
    virtual void draw() = 0;
    virtual bool contains(float mx, float my) = 0;
    virtual void setColor(float r, float g, float b) = 0;

    // Needed for resizing shapes
    virtual void resize(float scaleX, float scaleY) = 0;

    // Needed for moving shapes
    virtual void move(float dx, float dy) = 0;

    // Needed for undo/redo (deep copy)
    virtual Shape* clone() const = 0;

    // Required for deleting derived shapes safely
    virtual ~Shape() {}
};

#endif