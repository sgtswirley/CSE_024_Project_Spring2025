#ifndef SCRIBBLE_H
#define POINT_H

class Scribble {
    float x;   
    float y; 
    float r;
    float g;
    float b;
    int size;

public:

    Scribble();
    Scribble(float x, float y, float r, float g, float b, int size);

    void draw() const;

    float getX() const;
    float getY() const;
    float getR() const;
    float getG() const;
    float getB() const;
    int getSize() const;
};

#endif