#ifndef POLYGON_H
#define POLYGON_H


#include "Shape.h"

class Polygon : public Shape{

    float x;
    float y;
    int sides;
    float length;
    float r;
    float g;
    float b;

public:
    Polygon();

    Polygon(float x, float y, float r, float g, float b);
    void draw() override;
    bool contains(float mx, float my) override;

    float getX() const override;    // testing
    float getY() const override;
};

#endif