#ifndef SCRIBBLE_H
#define SCRIBBLE_H

#include "Shape.h"
#include "Point.h"
#include <vector>

class Scribble : public Shape {
private:
    std::vector<Point*> points;

public:
    Scribble();

    void addPoint(float x, float y, float r, float g, float b, int size);

    void draw() override;
    bool contains(float mx, float my) override;
    void setColor(float r, float g, float b) override;
    void resize(float scaleX, float scaleY) override;
    void move(float dx, float dy) override;
    Shape* clone() const override;

    ~Scribble();
};

#endif