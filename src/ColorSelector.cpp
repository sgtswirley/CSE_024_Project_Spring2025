#include "ColorSelector.h"
#include <FL/Enumerations.H>
#include <bobcat_ui/button.h>
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


    if (sender == redButton) {
        color = RED;
    }
    else if (sender == orangeButton) {
        color = ORANGE;
    }
    else if (sender == yellowButton) {
        color = YELLOW;
    }
    else if (sender == greenButton) {
        color = GREEN;
    }
    else if (sender == blueButton) {
        color = BLUE;
    }
    else if (sender == indigoButton) {
        color = INDIGO;
    }
    else if (sender == violetButton) {
        color = VIOLET;
    }
    else if (sender == inputButton) {       // added
        color = CHANGE;
    }


    if (onChangeCb) {
        onChangeCb(this);
    }

    visualizeSelectedColor();
    redraw();
}

Color ColorSelector::getColor() const {
    if (color == RED) {
        return Color(255/255.0, 0/255.0, 0/255.0);
    }
    else if (color == ORANGE) {
        return Color(255/255.0, 127/255.0, 0/255.0);
    }
    else if (color == YELLOW) {
        return Color(255/255.0, 255/255.0, 0/255.0);
    }
    else if (color == GREEN) {
        return Color(0/255.0, 255/255.0, 0/255.0);
    }
    else if (color == BLUE) {
        return Color(0/255.0, 0/255.0, 255/255.0);
    }
    else if (color == INDIGO) {
        return Color(75/255.0, 0/255.0, 130/255.0);
    }
    else if (color == VIOLET) {
        return Color(148/255.0, 0/255.0, 211/255.0);
    }
    else if (color == CHANGE) {     // ADDED v
        if (redInput->empty()){
            redInput->value(0);
        };
        if (greenInput->empty()){
            greenInput->value(0);
        };
        if (blueInput->empty()){
            blueInput->value(0);
        };
        int red = redInput->value();
        int green = greenInput->value();
        int blue = blueInput->value();

        if (red <= 0) {
            redInput->value(0);
            red = 0;
        } else if (red >= 255) {
            redInput->value(255);
            red = 255;
        }
        if (green <= 0) {
            greenInput->value(0);
            green = 0;
        } else if (green >= 255) {
            greenInput->value(255);
            green = 255;
        }
        if (blue <= 0) {
            blueInput->value(0);
            blue = 0;
        } else if (blue >= 255) {
            blueInput->value(255);
            blue = 255;
        }
        inputButton->color(fl_rgb_color(red, green, blue));  
        return Color(red/255.0 ,green/255.0, blue/255.0);
    }                                 // added ^
    else {
        return Color();
    }
}

ColorSelector::ColorSelector(int x, int y, int w, int h) : Group(x, y, w, h) {
    redButton = new Button(x + 0, y + 50, 50, 50, "");                 // moved all buttons down by  50
    orangeButton = new Button(x + 50, y + 50, 50, 50, "");
    yellowButton = new Button(x + 100, y + 50, 50, 50, "");
    greenButton = new Button(x + 150, y + 50, 50, 50, "");
    blueButton = new Button(x + 200, y + 50, 50, 50, "");
    indigoButton = new Button(x + 250, y + 50, 50, 50, "");
    violetButton = new Button(x + 300, y + 50, 50, 50, "");

    
    inputButton = new Button (x + 300, y + 0, 50, 50);              // added
    redInput = new IntInput(x + 0, y + 25, 100, 25, "INT RED");         // added
    greenInput = new IntInput(x + 100, y + 25, 100, 25, "INT GREEN");   // added
    blueInput = new IntInput(x + 200, y + 25, 100, 25, "INT BLUE");     // added

    color = RED;

    redButton->color(fl_rgb_color(255, 0, 0));
    redButton->labelcolor(FL_WHITE);
    orangeButton->color(fl_rgb_color(255, 127, 0));
    orangeButton->labelcolor(FL_WHITE);
    yellowButton->color(fl_rgb_color(255, 255, 0));
    yellowButton->labelcolor(FL_WHITE);
    greenButton->color(fl_rgb_color(0, 255, 0));
    greenButton->labelcolor(FL_WHITE);
    blueButton->color(fl_rgb_color(0, 0, 255));
    blueButton->labelcolor(FL_WHITE);
    indigoButton->color(fl_rgb_color(75, 0, 130));
    indigoButton->labelcolor(FL_WHITE);
    violetButton->color(fl_rgb_color(148, 0, 211));
    violetButton->labelcolor(FL_WHITE);

    inputButton->color(fl_rgb_color(255, 255, 255));    // added  v
    inputButton->label("COLOR\nSELECT");   
    redInput->align(FL_ALIGN_TOP);
    greenInput->align(FL_ALIGN_TOP);
    blueInput->align(FL_ALIGN_TOP);
    redInput->labelcolor(FL_RED);
    greenInput->labelcolor(FL_GREEN);
    blueInput->labelcolor(FL_BLUE);
    redInput->value(255);
    greenInput->value(255);
    blueInput->value(255);                              // added ^

    visualizeSelectedColor();

    ON_CLICK(redButton, ColorSelector::onClick);
    ON_CLICK(orangeButton, ColorSelector::onClick);
    ON_CLICK(yellowButton, ColorSelector::onClick);
    ON_CLICK(greenButton, ColorSelector::onClick);
    ON_CLICK(blueButton, ColorSelector::onClick);
    ON_CLICK(indigoButton, ColorSelector::onClick);
    ON_CLICK(violetButton, ColorSelector::onClick);
    ON_CLICK(inputButton, ColorSelector::onClick);  // added

}