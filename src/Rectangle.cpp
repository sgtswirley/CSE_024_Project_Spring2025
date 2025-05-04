#include "Rectangle.h"
#include <GL/freeglut.h>

Rectangle::Rectangle() 
    : x(0), y(0), width(0.4f), height(0.4f), r(0), g(0), b(0) {}

Rectangle::Rectangle(float x, float y, float r, float g, float b)
    : x(x), y(y), width(0.4f), height(0.4f), r(r), g(g), b(b) {}

void Rectangle::draw() {
    glColor3f(r, g, b);
    glBegin(GL_POLYGON);
    glVertex2f(x - width / 2, y + height / 2);
    glVertex2f(x + width / 2, y + height / 2);
    glVertex2f(x + width / 2, y - height / 2);
    glVertex2f(x - width / 2, y - height / 2);
    glEnd();
}

bool Rectangle::contains(float mx, float my) {
    return mx >= x - width / 2 && mx <= x + width / 2 &&
           my >= y - height / 2 && my <= y + height / 2;
}

void Rectangle::setColor(float r, float g, float b) {
    this->r = r;
    this->g = g;
    this->b = b;
}

void Rectangle::resize(float scaleX, float scaleY) {
    width *= scaleX;
    height *= scaleY;
}

void Rectangle::move(float dx, float dy) {
    x += dx;
    y += dy;
}

Shape* Rectangle::clone() const {
    return new Rectangle(x, y, r, g, b);
}