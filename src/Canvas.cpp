#include "Canvas.h"
#include "Circle.h"
#include "Point.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Polygon.h"
#include "Scribble.h"
#include "Enums.h"
#include <GL/freeglut.h>
#include <bobcat_ui/canvas.h>

Canvas::Canvas(int x, int y, int w, int h) : Canvas_(x, y, w, h) {
    curr = nullptr;
}

void Canvas::addPoint(float x, float y, float r, float g, float b, int size) {
    shapes.push_back(new Point(x, y, r, g, b, size));

}

void Canvas::addCircle(float x, float y, float radius, float r, float g, float b) {
    shapes.push_back(new Circle(x, y, radius, r, g ,b));
    shapes.push_back(CIRCLE);

}

void Canvas::addTriangle(float x, float y, float base, float height, float r, float g, float b) {
    shapes.push_back(new Triangle(x, y, base, height, r, g, b));
    shapes.push_back(TRIANGLE);

}

void Canvas::addRectangle(float x, float y, float width, float height, float r, float g, float b) {
    shapes.push_back(new Rectangle(x, y, width, height, r, g, b));
    shapes.push_back(RECTANGLE);

}

void Canvas::addPolygon(float x, float y, int sides, float length, float r, float g, float b) {
    shapes.push_back(new Polygon(x, y, sides, length, r, g, b));
    shapes.push_back(POLYGON);

}
void Canvas::clear() {
    for (unsigned int i = 0; i < shapes.size(); i++) {
        delete shapes[i];
    }
    shapes.clear();

}

void Canvas::undo(){
    if (shapes.size() > 0) {
        delete shapes[shapes.size() -1];
        shapes.pop_back();
    }
}



void Canvas::render() {
    for (unsigned int i = 0; i < shapes.size(); i++) {
        shapes[i]->draw();
    }

    if (curr){
        curr->draw();
    }
}

void Canvas::startScribble() {
    curr = new Scribble();
}

void Canvas::updateScribble(float x, float y, float r, float g, float b, int size){
    if (curr){
        curr->addPoint(x, y, r, g, b, size);
    }
}

void Canvas::endScribble(){
    shapes.push_back(curr);
    curr = nullptr;
}