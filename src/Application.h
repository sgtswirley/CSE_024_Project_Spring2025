
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
    float lastMouseX, lastMouseY;

public:
    Application();

    
    void onCanvasMouseDown  (bobcat::Widget* sender, float mx, float my);
    void onCanvasDrag       (bobcat::Widget* sender, float mx, float my);
    void onCanvasMouseUp    (bobcat::Widget* sender, float mx, float my);


    void onToolbarChange        (bobcat::Widget* sender);
    void onColorSelectorChange  (bobcat::Widget* sender);
};

#endif