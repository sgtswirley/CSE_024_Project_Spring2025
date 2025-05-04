#ifndef APPLICATION_H
#define APPLICATION_H

#include <bobcat_ui/all.h>
#include "Toolbar.h"
#include "Canvas.h"
#include "ColorSelector.h"
#include "Enums.h"

class Application : public bobcat::Application_ {
private:
    bobcat::Window* window;
    Toolbar* toolbar;
    Canvas* canvas;
    ColorSelector* colorSelector;

    Shape* selectedShape;
    float lastMouseX;
    float lastMouseY;

public:
    Application();

    // These are the callbacks you bind with ON_MOUSE_DOWN, etc.
    void onCanvasMouseDown(bobcat::Widget* sender, float mx, float my);
    void onCanvasDrag(bobcat::Widget* sender, float mx, float my);
    void onToolbarChange(bobcat::Widget* sender);
    void onColorSelectorChange(bobcat::Widget* sender);
};

#endif