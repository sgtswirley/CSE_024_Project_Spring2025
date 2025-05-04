#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.h"

class Triangle : public Shape {
private:
    float x, y;        // Center position
    float size;        
    float r, g, b;     

public:
    Triangle();
    Triangle(float x, float y, float r, float g, float b);

    void draw() override;
    bool contains(float mx, float my) override;
    void setColor(float r, float g, float b) override;
    void resize(float scaleX, float scaleY) override;
    void move(float dx, float dy) override;
    Shape* clone() const override;
};

#endif