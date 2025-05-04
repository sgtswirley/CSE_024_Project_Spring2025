
#include "Application.h"
#include "Enums.h"
#include <iostream>

using namespace bobcat;

Application::Application() {
   
    window = new Window(25, 75, 400, 450, "Paint App");

   
    selectedShape = nullptr;
    lastMouseX = lastMouseY = 0;

    toolbar = new Toolbar(0,   0,   50, 400);
    canvas = new Canvas(50,  0,  350, 330);   
    colorSelector = new ColorSelector(50, 330, 350, 100); 

    colorSelector->box(FL_BORDER_BOX);

    // 4) Add to window
    window->add(toolbar);
    window->add(canvas);
    window->add(colorSelector);

    // 5) Bind events
    ON_MOUSE_DOWN(canvas,    Application::onCanvasMouseDown);
    ON_DRAG(canvas,          Application::onCanvasDrag);
    ON_MOUSE_UP(canvas,      Application::onCanvasMouseUp);
    ON_CHANGE(toolbar,       Application::onToolbarChange);
    ON_CHANGE(colorSelector, Application::onColorSelectorChange);

    // 6) Show window
    window->show();
}

void Application::onCanvasMouseDown(bobcat::Widget* , float mx, float my) {
    TOOL tool = toolbar->getTool();
    Color c   = colorSelector->getColor();

    switch (tool) {
      case PENCIL:
        canvas->startScribble(mx,my, c.getR(),c.getG(),c.getB(), 7);
        break;
      case ERASER: {
        Shape* hit = canvas->getSelectedShape(mx,my);
        if (hit) {
          canvas->removeShape(hit);
          canvas->redraw();
        }
        break;
      }
      case RECTANGLE:
        canvas->addRectangle(mx,my, c.getR(),c.getG(),c.getB());
        canvas->redraw();
        break;
      case CIRCLE:
        canvas->addCircle(mx,my, c.getR(),c.getG(),c.getB());
        canvas->redraw();
        break;
      case TRIANGLE:
        canvas->addTriangle(mx,my, c.getR(),c.getG(),c.getB());
        canvas->redraw();
        break;
      case POLYGON:
        canvas->addPolygon(mx,my, c.getR(),c.getG(),c.getB());
        canvas->redraw();
        break;
      case MOUSE:
        selectedShape = canvas->getSelectedShape(mx,my);
        lastMouseX = mx; lastMouseY = my;
        break;
      case FRONT:
        selectedShape = canvas->getSelectedShape(mx,my);
        if (selectedShape) { canvas->bringToFront(selectedShape); canvas->redraw(); }
        break;
      case BACK:
        selectedShape = canvas->getSelectedShape(mx,my);
        if (selectedShape) { canvas->sendToBack(selectedShape);  canvas->redraw(); }
        break;
      default: break;
    }
}

void Application::onCanvasDrag(bobcat::Widget* , float mx, float my) {
    TOOL tool = toolbar->getTool();
    Color c   = colorSelector->getColor();

    if (tool == PENCIL) {
      canvas->updateScribble(mx,my, c.getR(),c.getG(),c.getB(), 7);
      canvas->redraw();
    }
    else if (tool == MOUSE && selectedShape) {
      float dx = mx - lastMouseX;
      float dy = my - lastMouseY;
      selectedShape->move(dx, dy);
      canvas->redraw();
      lastMouseX = mx; lastMouseY = my;
    }
}

void Application::onCanvasMouseUp(bobcat::Widget* , float mx, float my) {
    if (toolbar->getTool() == PENCIL) {
      canvas->endScribble();
      canvas->redraw();
    }
}

void Application::onToolbarChange(bobcat::Widget* ) {
    ACTION action = toolbar->getAction();
    if      (action == CLEAR)    { canvas->clear();   canvas->redraw(); }
    else if (action == INCREASE && selectedShape) {
      selectedShape->resize(1.1f,1.1f); canvas->redraw();
    }
    else if (action == DECREASE && selectedShape) {
      selectedShape->resize(0.9f,0.9f); canvas->redraw();
    }
}

void Application::onColorSelectorChange(bobcat::Widget* ) {
    Color c = colorSelector->getColor();
    if (selectedShape) {
      selectedShape->setColor(c.getR(),c.getG(),c.getB());
      canvas->redraw();
    }
}