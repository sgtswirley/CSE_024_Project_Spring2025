#include "Triangle.h"
#include <GL/freeglut.h>

Triangle::Triangle() {
    x = 0.0;
    y = 0.0;
    base = 0.4;
    height = 0.4;
    r = 0.0;
    g = 0.0;
    b = 0.0;
    
}

Triangle::Triangle(float x, float y, float r, float g, float b) {
    this->x = x;
    this->y = y;
    base = 0.4;
    height = 0.4;
    this->r = r;
    this->g = g;
    this->b = b;
}

void Triangle::draw() {
    glColor3f(r, g, b);

    glBegin(GL_POLYGON);
        glVertex2d(x - base/2, y - height/2);
        glVertex2d(x, y + height/2);
        glVertex2d(x + base/2, y - height/2);
    glEnd();
}

bool Triangle::contains(float mx, float my) {
    if (mx >= x - base/2 && mx <= x + base/2 && my <= y + height/2 && my >= y - height/2) {
        return true;
    }
    return false;
}

float Triangle::getX() const {    // testing
    return x;
}

float Triangle::getY() const {
    return y;
}