#include "Scribble.h"
#include <GL/freeglut.h>
#include <GL/gl.h>

Scribble::Scribble() {
    x = 0.0;
    y = 0.0;
    r = 0.0;
    g = 0.0;
    b = 0.0;
    size = 7;
}

Scribble::Scribble(float x, float y, float r, float g, float b, int size) : Scribble() {
    this->x = x;
    this->y = y;
    this->r = r;
    this->g = g;
    this->b = b;
    this->size = size;

}

void Scribble::draw() const {
    glColor3f(r, g, b);
    glPointSize(size);

    glBegin(GL_POINTS);
        glVertex2d(x, y);
    glEnd();
}

float Scribble::getX() const {
    return x;
}

float Scribble::getY() const {
    return y;
}

float Scribble::getR() const {
    return r;
}

float Scribble::getG() const {
    return g;
}

float Scribble::getB() const {
    return b;
}

int Scribble::getSize() const {
    return size;
}