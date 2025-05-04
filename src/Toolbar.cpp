#include "Toolbar.h"
#include <FL/Enumerations.H>
using namespace bobcat;

void Toolbar::deselectAllTools() {
    pencilButton->color(FL_BACKGROUND_COLOR);
    eraserButton->color(FL_BACKGROUND_COLOR);
    circleButton->color(FL_BACKGROUND_COLOR);
    triangleButton->color(FL_BACKGROUND_COLOR);
    rectangleButton->color(FL_BACKGROUND_COLOR);
    polygonButton->color(FL_BACKGROUND_COLOR);
    mouseButton->color(FL_BACKGROUND_COLOR);
    frontButton->color(FL_BACKGROUND_COLOR);
    backButton->color(FL_BACKGROUND_COLOR);
    sizeIncreaseButton->color(FL_BACKGROUND_COLOR);
    sizeDecreaseButton->color(FL_BACKGROUND_COLOR);

}

void Toolbar::visualizeSelectedTool() {
    if (tool == PENCIL) {
        pencilButton->color(FL_WHITE);
    }
    else if (tool == ERASER) {
        eraserButton->color(FL_WHITE);
    }
    else if (tool == CIRCLE) {
        circleButton->color(FL_WHITE);
    }
    else if (tool == TRIANGLE) {
        triangleButton->color(FL_WHITE);
    }
    else if (tool == RECTANGLE) {
        rectangleButton->color(FL_WHITE);
    }
    else if (tool == POLYGON) {
        polygonButton->color(FL_WHITE);
    }
    else if (tool == MOUSE) {
        mouseButton->color(FL_WHITE);
    }
    else if (tool == FRONT) {
        frontButton->color(FL_WHITE);
    }
    else if (tool == BACK) {
        backButton->color(FL_WHITE);
    }

}

void Toolbar::onClick(bobcat::Widget* sender) {
    deselectAllTools();

    action = NONE;

    if (sender == pencilButton) {
        tool = PENCIL;
    }
    else if (sender == eraserButton) {
        tool = ERASER;
    }
    else if (sender == circleButton) {
        tool = CIRCLE;
    }
    else if (sender == triangleButton) {
        tool = TRIANGLE;
    }
    else if (sender == rectangleButton) {
        tool = RECTANGLE;
    }
    else if (sender == polygonButton) {
        tool = POLYGON;
    }
    else if (sender == clearButton) {
        action = CLEAR;
    }
    else if (sender == mouseButton) {
        tool = MOUSE;
    }
    else if (sender == frontButton) {
        tool = FRONT;
    }
    else if (sender == backButton) {
        tool = BACK;
    }
    else if(sender == sizeIncreaseButton){
        action = INCREASE;
    }
    else if(sender == sizeDecreaseButton){
        action = DECREASE;
    }

    if (onChangeCb) {
        onChangeCb(this);
    }

    visualizeSelectedTool();
    redraw();
}

TOOL Toolbar::getTool() const {
    return tool;
}

ACTION Toolbar::getAction() const {
    return action;

}

Toolbar::Toolbar(int x, int y, int w, int h) : Group(x, y, w, h) {
    pencilButton = new Image(x, y, 40, 40, "./assets/pencil.png");
    eraserButton = new Image(x, y + 40, 40, 40, "./assets/eraser.png");
    circleButton = new Image(x, y + 80, 20, 20, "./assets/circle.png");
    triangleButton = new Image(x + 20, y + 80, 20, 20, "./assets/triangle.png");
    rectangleButton = new Image(x, y + 100, 20, 20, "./assets/rectangle.png");
    polygonButton = new Image(x + 20, y + 100, 20, 20, "./assets/polygon.png");
    frontButton = new Image(x, y + 120, 40, 40, "./assets/bring-to-front.png");
    backButton = new Image(x, y + 160, 40, 40, "./assets/send-to-back.png");
    clearButton = new Image(x, y + 200, 40, 40, "./assets/clear.png");
    mouseButton = new Image(x, y + 240, 40, 40, "./assets/mouse.png");
    sizeIncreaseButton = new Image(x, y + 280, 40, 40, "./assets/plus.png");
    sizeDecreaseButton = new Image(x, y + 320, 40, 40, "./assets/minus.png");


    tool = PENCIL;
    action = NONE;

    pencilButton->box(FL_BORDER_BOX);
    eraserButton->box(FL_BORDER_BOX);
    circleButton->box(FL_BORDER_BOX);
    triangleButton->box(FL_BORDER_BOX);
    rectangleButton->box(FL_BORDER_BOX);
    polygonButton->box(FL_BORDER_BOX);
    clearButton->box(FL_BORDER_BOX);
    mouseButton->box(FL_BORDER_BOX);
    frontButton->box(FL_BORDER_BOX);
    backButton->box(FL_BORDER_BOX);
    sizeIncreaseButton->box(FL_BORDER_BOX);
    sizeDecreaseButton->box(FL_BORDER_BOX);

    // undoButton->box(FL_BORDER_BOX);


    visualizeSelectedTool();

    ON_CLICK(pencilButton, Toolbar::onClick);
    ON_CLICK(eraserButton, Toolbar::onClick);
    ON_CLICK(circleButton, Toolbar::onClick);
    ON_CLICK(triangleButton, Toolbar::onClick);
    ON_CLICK(rectangleButton, Toolbar::onClick);
    ON_CLICK(polygonButton, Toolbar::onClick);
    ON_CLICK(clearButton, Toolbar::onClick);
    ON_CLICK(mouseButton, Toolbar::onClick);
    ON_CLICK(frontButton, Toolbar::onClick);
    ON_CLICK(backButton, Toolbar::onClick);
    ON_CLICK(sizeIncreaseButton, Toolbar::onClick);
    ON_CLICK(sizeDecreaseButton, Toolbar::onClick);

}