#ifndef LABEL_H
#define LABEL_H

#include <string>
#include <iostream>
#include "components.h"

using namespace std;

class Label {
    protected:
        char faclity;
        int aisle;
        int column;
        int height;
        string labelString;

    public:
        virtual void decodeLabel(string label);
        Box getBox();
};

class LabelTypeA : public Label {
    public:
        LabelTypeA(string label) {
            this->labelString = label;

        }

        void decodeLabel(string label) {
            
        }
    
        Label *getRightSide() {

        }
};

#endif