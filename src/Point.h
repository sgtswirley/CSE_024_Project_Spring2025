#ifndef POINT_H
#define POINT_H

#include "Shape.h"

class Point : public Shape {
    float x, y;
    float r, g, b;
    int size;

public:
    Point();
    Point(float x, float y);
    Point(float x, float y, float r, float g, float b);
    Point(float x, float y, float r, float g, float b, int size);

    void draw() override;
    bool contains(float mx, float my) override;
    void setColor(float r, float g, float b) override;
    void resize(float scaleX, float scaleY) override;
    void move(float dx, float dy) override;
    Shape* clone() const override;

    float getX() const;
    float getY() const;
    float getR() const;
    float getG() const;
    float getB() const;
    int getSize() const;
};

#endif