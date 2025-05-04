#include "Polygon.h"
#include <GL/freeglut.h>
#include <cmath>

Polygon::Polygon() {
    x = y = 0;
    radius = 0.2f;
    sides = 6;
    r = g = b = 0;
}

Polygon::Polygon(float x, float y, float r, float g, float b) {
    this->x = x;
    this->y = y;
    this->radius = 0.2f;
    this->sides = 6; // default hexagon
    this->r = r;
    this->g = g;
    this->b = b;
}

void Polygon::draw() {
    glColor3f(r, g, b);
    glBegin(GL_POLYGON);
    for (int i = 0; i < sides; ++i) {
        float angle = 2 * M_PI * i / sides;
        float px = x + radius * cos(angle);
        float py = y + radius * sin(angle);
        glVertex2f(px, py);
    }
    glEnd();
}

bool Polygon::contains(float mx, float my) {
    // Simplified bounding box check (not perfect)
    return mx >= x - radius && mx <= x + radius &&
           my >= y - radius && my <= y + radius;
}

void Polygon::setColor(float r, float g, float b) {
    this->r = r;
    this->g = g;
    this->b = b;
}

void Polygon::resize(float scaleX, float scaleY) {
    radius *= (scaleX + scaleY) / 2.0f;
}

void Polygon::move(float dx, float dy) {
    x += dx;
    y += dy;
}

Shape* Polygon::clone() const {
    return new Polygon(x, y, r, g, b);
}