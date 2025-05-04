#ifndef POLYGON_H
#define POLYGON_H

#include "Shape.h"
#include <vector>

class Polygon : public Shape {
private:
    float x, y;
    float radius;
    int sides;
    float r, g, b;

public:
    Polygon();
    Polygon(float x, float y, float r, float g, float b);

    void draw() override;
    bool contains(float mx, float my) override;
    void setColor(float r, float g, float b) override;
    void resize(float scaleX, float scaleY) override;
    void move(float dx, float dy) override;
    Shape* clone() const override;
};

#endif