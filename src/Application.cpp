#include "Application.h"
#include "Enums.h"


using namespace bobcat;
using namespace std;

void Application::onCanvasMouseDown(bobcat::Widget* sender, float mx, float my) {
    TOOL tool = toolbar->getTool();
    Color color = colorSelector->getColor();

    if (tool == PENCIL) {
        canvas->addPoint(mx, my, color.getR(), color.getG(), color.getB(), 7);
        canvas->redraw();
    }
    else if (tool == ERASER) {
        canvas->addPoint(mx, my, 1.0, 1.0, 1.0, 14);
        canvas->redraw();
    }
    else if (tool == CIRCLE) { 
        canvas->addCircle(mx, my, color.getR(), color.getG(), color.getB());
        canvas->redraw();
    }
    else if (tool == RECTANGLE) {
        canvas->addRectangle(mx, my, color.getR(), color.getG(), color.getB());
        canvas->redraw();
    }
    else if (tool == TRIANGLE) {
        canvas->addTriangle(mx, my, color.getR(), color.getG(), color.getB());
        canvas->redraw();
    }
    else if (tool == POLYGON) {
        canvas->addPolygon(mx, my, color.getR(), color.getG(), color.getB());
        canvas->redraw();
    }
    else if (tool == MOUSE) {
        Shape* selectedShape = canvas->getSelectedShape(mx, my);
    }
    else if (tool == PLUS) {
        cout << "Plus";
    }
    else if (tool == MINUS) {
        cout << "Minus";
    }
    else if (tool == FRONT) {
        cout << "Do front";
    }
    else if (tool == BACK) {
        cout << "Do back";
    }


}

void Application::onCanvasDrag(bobcat::Widget* sender, float mx, float my) {
    TOOL tool = toolbar->getTool();
    Color color = colorSelector->getColor();

    if (tool == PENCIL) {
        canvas->addPoint(mx, my, color.getR(), color.getG(), color.getB(), 7);
        canvas->redraw();
    }
    else if (tool == ERASER) {
        canvas->addPoint(mx, my, 1.0, 1.0, 1.0, 14);
        canvas->redraw();
    }
}

void Application::onToolbarChange(bobcat::Widget* sender) {
    ACTION action = toolbar->getAction();

    if (action == CLEAR) {
        canvas->clear();
        canvas->redraw();
    }
}

Application::Application() {
    window = new Window(25, 75, 430, 400, "Paint");

    toolbar = new Toolbar(0, 0, 80, 400);
    canvas = new Canvas(80, 0, 350, 350);
    colorSelector = new ColorSelector(50, 350, 350, 50);
    colorSelector->box(FL_BORDER_BOX);

    window->add(toolbar);
    window->add(canvas);
    window->add(colorSelector);

    ON_MOUSE_DOWN(canvas, Application::onCanvasMouseDown);
    ON_DRAG(canvas, Application::onCanvasDrag);
    ON_CHANGE(toolbar, Application::onToolbarChange);
    // ON_MOUSE_UP(canvas, Application::onCanvasMouseUp);

    window->show();
}