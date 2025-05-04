#include "Point.h"
#include <GL/freeglut.h>
#include <cmath>

Point::Point() : x(0), y(0), r(0), g(0), b(0), size(5) {}

Point::Point(float x, float y) : x(x), y(y), r(0), g(0), b(0), size(5) {}

Point::Point(float x, float y, float r, float g, float b)
    : x(x), y(y), r(r), g(g), b(b), size(5) {}

Point::Point(float x, float y, float r, float g, float b, int size)
    : x(x), y(y), r(r), g(g), b(b), size(size) {}

void Point::draw() {
    glColor3f(r, g, b);
    glPointSize(size);
    glBegin(GL_POINTS);
    glVertex2f(x, y);
    glEnd();
}

bool Point::contains(float mx, float my) {
    float dx = mx - x;
    float dy = my - y;
    return (dx * dx + dy * dy) <= (size / 200.0f) * (size / 200.0f); // small hitbox
}

void Point::setColor(float r, float g, float b) {
    this->r = r;
    this->g = g;
    this->b = b;
}

void Point::resize(float scaleX, float scaleY) {
    size *= (scaleX + scaleY) / 2.0f; // average scale
}

void Point::move(float dx, float dy) {
    x += dx;
    y += dy;
}

Shape* Point::clone() const {
    return new Point(x, y, r, g, b, size);
}

float Point::getX() const { return x; }
float Point::getY() const { return y; }
float Point::getR() const { return r; }
float Point::getG() const { return g; }
float Point::getB() const { return b; }
int Point::getSize() const { return size; }