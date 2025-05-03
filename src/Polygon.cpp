#include "Polygon.h"

#include <cmath>

Polygon::Polygon() {
    x = 0.0;
    y = 0.0;
    sides = 5;

    length = 0.25;

    r = 0.0;
    g = 0.0;
    b = 0.0;
}


Polygon::Polygon(float x, float y, float r, float g, float b){
    this->x = x;
    this->y = y;
    sides = 5;
    length = 0.25;

    this->r = r;
    this->g = g;
    this->b = b;
}

void Polygon::draw() {
    glColor3f(r, g ,b);

    glBegin(GL_POLYGON);
        float inc = 2 * M_PI / sides;
        for (float theta = 0; theta <= 2 * M_PI; theta += inc) {
            glVertex2f(x + length * cos(theta), y + length * sin(theta));
        }
    glEnd();

}

bool Polygon::contains(float mx, float my) {
    if (mx >= x - length/2 && mx <= x + length/2 && my <= y + length/2 && my >= y - length/2) {
        return true;
    }
    return false;

}

float Polygon::getX() const {    // testing
    return x;
}

float Polygon::getY() const {
    return y;
}