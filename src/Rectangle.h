#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"

class Rectangle : public Shape {
private:
    float x, y;
    float width, height;
    float r, g, b;

public:
    Rectangle(); 
    Rectangle(float x, float y, float r, float g, float b);  

    void draw() override;
    bool contains(float mx, float my) override;
    void setColor(float r, float g, float b) override;
    void resize(float scaleX, float scaleY) override;
    void move(float dx, float dy) override;
    Shape* clone() const override;
};

#endif