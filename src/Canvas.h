#ifndef CANVAS_H
#define CANVAS_H

#include <bobcat_ui/all.h>
#include <bobcat_ui/canvas.h>
#include <vector>
#include <iostream>
#include "Scribble.h"
#include "Circle.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Polygon.h"
#include "Enums.h"

class Canvas : public bobcat::Canvas_ {
    std::vector<Shape*> shapes;

    Scribble* curr;

public:
    Canvas(int x, int y, int w, int h);

    void addPoint(float x, float y, float r, float g, float b, int size);

    void addScribble(float x, float y, float r, float g, float b, float size);

    void addCircle(float x, float y, float radius, float r, float g, float b);
    
    void addTriangle(float x, float y, float base, float height, float r, float g, float b);

    void addRectangle(float x, float y, float width, float height, float r, float g, float b);

    void addPolygon(float x, float y, int sides, float length, float r, float g, float b);
    
    void clear();
    
    void undo();

    void startScribble();

    void updateScribble(float x, float y, float r, float g, float b, int size);

    void endScribble();

    void render();

};

#endif