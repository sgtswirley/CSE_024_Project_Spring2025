#include "Triangle.h"
#include <GL/freeglut.h>
#include <cmath>

Triangle::Triangle() : x(0), y(0), size(0.3), r(0), g(0), b(0) {}

Triangle::Triangle(float x, float y, float r, float g, float b)
    : x(x), y(y), size(0.3), r(r), g(g), b(b) {}

void Triangle::draw() {
    glColor3f(r, g, b);
    glBegin(GL_TRIANGLES);
    for (int i = 0; i < 3; ++i) {
        float angle = 2 * 3.14159f * i / 3;
        glVertex2f(x + size * cos(angle), y + size * sin(angle));
    }
    glEnd();
}

bool Triangle::contains(float mx, float my) {
   
    float dx = mx - x;
    float dy = my - y;
    return dx * dx + dy * dy <= size * size;
}

void Triangle::setColor(float r, float g, float b) {
    this->r = r;
    this->g = g;
    this->b = b;
}

void Triangle::resize(float scaleX, float scaleY) {
    size *= (scaleX + scaleY) / 2.0f; 
}

void Triangle::move(float dx, float dy) {
    x += dx;
    y += dy;
}

Shape* Triangle::clone() const {
    return new Triangle(x, y, r, g, b);
}