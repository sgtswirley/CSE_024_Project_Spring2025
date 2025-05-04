#include "Circle.h"
#include <GL/freeglut.h>
#include <cmath>

Circle::Circle() : x(0), y(0), radius(0.2), r(0), g(0), b(0) {}

Circle::Circle(float x, float y, float r, float g, float b)
    : x(x), y(y), radius(0.2), r(r), g(g), b(b) {}

void Circle::draw() {
    glColor3f(r, g, b);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; ++i) {
        float theta = i * 3.14159f / 180.0f;
        glVertex2f(x + radius * cos(theta), y + radius * sin(theta));
    }
    glEnd();
}

bool Circle::contains(float mx, float my) {
    float dx = mx - x;
    float dy = my - y;
    return dx * dx + dy * dy <= radius * radius;
}

void Circle::setColor(float r, float g, float b) {
    this->r = r;
    this->g = g;
    this->b = b;
}

void Circle::resize(float scaleX, float scaleY) {
    radius *= (scaleX + scaleY) / 2.0f; 
}

void Circle::move(float dx, float dy) {
    x += dx;
    y += dy;
}

Shape* Circle::clone() const {
    return new Circle(x, y, r, g, b);
}