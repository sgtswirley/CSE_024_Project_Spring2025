#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"

class Circle : public Shape {
private:
    float x, y;
    float radius;
    float r, g, b;

public:
    Circle();
    Circle(float x, float y, float r, float g, float b);

    void draw() override;
    bool contains(float mx, float my) override;
    void setColor(float r, float g, float b) override;
    void resize(float scaleX, float scaleY) override;
    void move(float dx, float dy) override;
    Shape* clone() const override;
};

#endif