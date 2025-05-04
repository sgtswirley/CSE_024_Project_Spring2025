#ifndef CANVAS_H
#define CANVAS_H

#include <bobcat_ui/all.h>
#include <vector>
#include "Shape.h"

class Canvas : public bobcat::Canvas_ {
private:
    std::vector<Shape*> objects;

public:
    Canvas(int x, int y, int w, int h);

    void addPoint(float x, float y, float r, float g, float b, int size);
    void addRectangle(float x, float y, float r, float g, float b);
    void addCircle(float x, float y, float r, float g, float b);
    void addTriangle(float x, float y, float r, float g, float b);
    void addPolygon(float x, float y, float r, float g, float b);

    void clear();
    void render();

    Shape* getSelectedShape(float mx, float my);
    void moveSelectedShape(Shape* shape, float dx, float dy);
    void resizeSelectedShape(Shape* shape, float scaleX, float scaleY);
    void removeShape(Shape* shape);
    void bringToFront(Shape* shape);
    void sendToBack(Shape* shape);
};

#endif