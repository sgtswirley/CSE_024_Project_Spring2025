#include "Application.h"
#include "Enums.h"
#include <iostream>

using namespace bobcat;

Application::Application() {
    window = new Window(25, 75, 400, 400, "Paint App");

    selectedShape = nullptr;
    lastMouseX = 0;
    lastMouseY = 0;

    toolbar       = new Toolbar(0,   0,   50, 400);
    canvas        = new Canvas(50,  0,  350, 350);
    colorSelector = new ColorSelector(50, 350, 350, 50);
    colorSelector->box(FL_BORDER_BOX);

    window->add(toolbar);
    window->add(canvas);
    window->add(colorSelector);

    ON_MOUSE_DOWN(canvas,    Application::onCanvasMouseDown);
    ON_DRAG(canvas,          Application::onCanvasDrag);
    ON_CHANGE(toolbar,       Application::onToolbarChange);
    ON_CHANGE(colorSelector, Application::onColorSelectorChange);

    window->show();
}

void Application::onCanvasMouseDown(bobcat::Widget* sender, float mx, float my) {
    TOOL tool = toolbar->getTool();
    Color color = colorSelector->getColor();

    switch (tool) {
        case PENCIL:
            canvas->addPoint(mx, my, color.getR(), color.getG(), color.getB(), 7);
            canvas->redraw();
            break;
        case ERASER: {
            Shape* target = canvas->getSelectedShape(mx, my);
            if (target) {
                canvas->removeShape(target);
                canvas->redraw();
            }
            break;
        }
        case RECTANGLE:
            canvas->addRectangle(mx, my, color.getR(), color.getG(), color.getB());
            canvas->redraw();
            break;
        case CIRCLE:
            canvas->addCircle(mx, my, color.getR(), color.getG(), color.getB());
            canvas->redraw();
            break;
        case TRIANGLE:
            canvas->addTriangle(mx, my, color.getR(), color.getG(), color.getB());
            canvas->redraw();
            break;
        case POLYGON:
            canvas->addPolygon(mx, my, color.getR(), color.getG(), color.getB());
            canvas->redraw();
            break;
        case MOUSE:
            selectedShape = canvas->getSelectedShape(mx, my);
            lastMouseX = mx;
            lastMouseY = my;
            break;
        case FRONT:
            selectedShape = canvas->getSelectedShape(mx, my);
            if (selectedShape) {
                canvas->bringToFront(selectedShape);
                canvas->redraw();
            }
            break;
        case BACK:
            selectedShape = canvas->getSelectedShape(mx, my);
            if (selectedShape) {
                canvas->sendToBack(selectedShape);
                canvas->redraw();
            }
            break;
    }
}

void Application::onCanvasDrag(bobcat::Widget* sender, float mx, float my) {
    if (toolbar->getTool() == MOUSE && selectedShape) {
        float dx = mx - lastMouseX;
        float dy = my - lastMouseY;
        selectedShape->move(dx, dy);
        canvas->redraw();
        lastMouseX = mx;
        lastMouseY = my;
    }
}

void Application::onToolbarChange(bobcat::Widget* sender) {
    ACTION action = toolbar->getAction();
    if (action == CLEAR) {
        canvas->clear();
        canvas->redraw();
    } else if (action == INCREASE && selectedShape) {
        selectedShape->resize(1.1f, 1.1f);
        canvas->redraw();
    } else if (action == DECREASE && selectedShape) {
        selectedShape->resize(0.9f, 0.9f);
        canvas->redraw();
    }
}

void Application::onColorSelectorChange(bobcat::Widget* sender) {
    Color color = colorSelector->getColor();
    if (selectedShape) {
        selectedShape->setColor(color.getR(), color.getG(), color.getB());
        canvas->redraw();
    }
}