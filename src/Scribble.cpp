#include "Scribble.h"

Scribble::Scribble() {}

void Scribble::addPoint(float x, float y, float r, float g, float b, int size) {
    points.push_back(new Point(x, y, r, g, b, size));
}

void Scribble::draw() {
    for (Point* p : points) {
        p->draw();
    }
}

bool Scribble::contains(float mx, float my) {
    for (Point* p : points) {
        if (p->contains(mx, my)) return true;
    }
    return false;
}

void Scribble::setColor(float r, float g, float b) {
    for (Point* p : points) {
        p->setColor(r, g, b);
    }
}

void Scribble::resize(float scaleX, float scaleY) {
    for (Point* p : points) {
        p->resize(scaleX, scaleY);
    }
}

void Scribble::move(float dx, float dy) {
    for (Point* p : points) {
        p->move(dx, dy);
    }
}

Shape* Scribble::clone() const {
    Scribble* copy = new Scribble();
    for (Point* p : points) {
        copy->points.push_back(static_cast<Point*>(p->clone()));
    }
    return copy;
}

Scribble::~Scribble() {
    for (Point* p : points) {
        delete p;
    }
}