#include "Canvas.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"
#include "Polygon.h"
#include "Scribble.h"
#include <algorithm>

Canvas::Canvas(int x, int y, int w, int h)
  : Canvas_(x, y, w, h),
    currScribble(nullptr)
{}

// Begin a new freehand stroke
void Canvas::startScribble(float x, float y, float r, float g, float b, int size) {
    currScribble = new Scribble();
    currScribble->addPoint(x, y, r, g, b, size);
    objects.push_back(currScribble);
}

// Continue the current stroke
void Canvas::updateScribble(float x, float y, float r, float g, float b, int size) {
    if (currScribble) {
        currScribble->addPoint(x, y, r, g, b, size);
    }
}

// Finish the current stroke
void Canvas::endScribble() {
    currScribble = nullptr;
}

// Add a rectangle
void Canvas::addRectangle(float x, float y, float r, float g, float b) {
    objects.push_back(new Rectangle(x, y, r, g, b));
}

// Add a circle
void Canvas::addCircle(float x, float y, float r, float g, float b) {
    objects.push_back(new Circle(x, y, r, g, b));
}

// Add a triangle
void Canvas::addTriangle(float x, float y, float r, float g, float b) {
    objects.push_back(new Triangle(x, y, r, g, b));
}

// Add a polygon
void Canvas::addPolygon(float x, float y, float r, float g, float b) {
    objects.push_back(new Polygon(x, y, r, g, b));
}

// Clear all objects
void Canvas::clear() {
    for (auto* obj : objects) {
        delete obj;
    }
    objects.clear();
    currScribble = nullptr;
}

// Draw everything
void Canvas::render() {
    for (auto* obj : objects) {
        obj->draw();
    }
}

// Hit‐test topmost object under (mx,my)
Shape* Canvas::getSelectedShape(float mx, float my) {
    for (int i = (int)objects.size() - 1; i >= 0; --i) {
        if (objects[i]->contains(mx, my)) {
            return objects[i];
        }
    }
    return nullptr;
}

// Move a specific shape
void Canvas::moveSelectedShape(Shape* shape, float dx, float dy) {
    if (shape) shape->move(dx, dy);
}

// Resize a specific shape
void Canvas::resizeSelectedShape(Shape* shape, float scaleX, float scaleY) {
    if (shape) shape->resize(scaleX, scaleY);
}

// Remove (and delete) a shape
void Canvas::removeShape(Shape* shape) {
    auto it = std::find(objects.begin(), objects.end(), shape);
    if (it != objects.end()) {
        delete *it;
        objects.erase(it);
    }
}

// Bring a shape to the front
void Canvas::bringToFront(Shape* shape) {
    auto it = std::find(objects.begin(), objects.end(), shape);
    if (it != objects.end()) {
        objects.erase(it);
        objects.push_back(shape);
    }
}

// Send a shape to the back
void Canvas::sendToBack(Shape* shape) {
    auto it = std::find(objects.begin(), objects.end(), shape);
    if (it != objects.end()) {
        objects.erase(it);
        objects.insert(objects.begin(), shape);
    }
}