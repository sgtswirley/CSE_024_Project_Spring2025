#include "ColorSelector.h"
using namespace bobcat;

void ColorSelector::deselectAllColors() {
    redButton->label("");
    orangeButton->label("");
    yellowButton->label("");
    greenButton->label("");
    blueButton->label("");
    indigoButton->label("");
    violetButton->label("");
}

void ColorSelector::visualizeSelectedColor() {
    if (color == RED) {
        redButton->label("@+5square");
    }
    else if (color == ORANGE) {
        orangeButton->label("@+5square");
    }
    else if (color == YELLOW) {
        yellowButton->label("@+5square");
    }
    else if (color == GREEN) {
        greenButton->label("@+5square");
    }
    else if (color == BLUE) {
        blueButton->label("@+5square");
    }
    else if (color == INDIGO) {
        indigoButton->label("@+5square");
    }
    else if (color == VIOLET) {
        violetButton->label("@+5square");
    }
}

void ColorSelector::onClick(bobcat::Widget* sender) {
    deselectAllColors();

    if (color == RED) {
        color = RED;
    }
    else if (color == ORANGE) {
        color = ORANGE;
    }
    else if (color == YELLOW) {
        color = YELLOW;
    }
    else if (color == GREEN) {
        color = GREEN;
    }
    else if (color == BLUE) {
        color = BLUE;
    }
    else if (color == INDIGO) {
        color = INDIGO;
    }
    else if (color == VIOLET) {
        color = VIOLET;
    }
}