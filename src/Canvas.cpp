#include "Canvas.h"      
#include "Rectangle.h"   
#include "Circle.h"     
#include "Triangle.h"   
#include "Polygon.h"     
#include "Scribble.h"    
#include <algorithm>     

Canvas::Canvas(int x, int y, int w, int h)
    : Canvas_(x, y, w, h) {}

void Canvas::addPoint(float x, float y, float r, float g, float b, int size) {
    Scribble* s = new Scribble();
    s->addPoint(x, y, r, g, b, size);
    objects.push_back(s);
}

void Canvas::addRectangle(float x, float y, float r, float g, float b) {
    objects.push_back(new Rectangle(x, y, r, g, b));
}

void Canvas::addCircle(float x, float y, float r, float g, float b) {
    objects.push_back(new Circle(x, y, r, g, b));
}

void Canvas::addTriangle(float x, float y, float r, float g, float b) {
    objects.push_back(new Triangle(x, y, r, g, b));
}

void Canvas::addPolygon(float x, float y, float r, float g, float b) {
    objects.push_back(new Polygon(x, y, r, g, b));
}

void Canvas::clear() {
    for (Shape* shape : objects) delete shape;
    objects.clear();
}

void Canvas::render() {
    for (Shape* shape : objects) shape->draw();
}

Shape* Canvas::getSelectedShape(float mx, float my) {
    for (int i = objects.size() - 1; i >= 0; --i) {
        if (objects[i]->contains(mx, my)) return objects[i];
    }
    return nullptr;
}

void Canvas::moveSelectedShape(Shape* shape, float dx, float dy) {
    if (shape) shape->move(dx, dy);
}

void Canvas::resizeSelectedShape(Shape* shape, float scaleX, float scaleY) {
    if (shape) shape->resize(scaleX, scaleY);
}

void Canvas::removeShape(Shape* shape) {
    auto it = std::find(objects.begin(), objects.end(), shape);
    if (it != objects.end()) {
        delete *it;
        objects.erase(it);
    }
}

void Canvas::bringToFront(Shape* shape) {
    auto it = std::find(objects.begin(), objects.end(), shape);
    if (it != objects.end()) {
        objects.erase(it);
        objects.push_back(shape);
    }
}

void Canvas::sendToBack(Shape* shape) {
    auto it = std::find(objects.begin(), objects.end(), shape);
    if (it != objects.end()) {
        objects.erase(it);
        objects.insert(objects.begin(), shape);
    }
}
