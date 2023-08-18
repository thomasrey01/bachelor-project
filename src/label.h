#ifndef MAPLABEL_H
#define MAPLABEL_H

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
        Box box;

    public:
        Label() {}
        virtual void decodeLabel(string label);
        // virtual string getRight();
        // virtual string getLeft();
        // virtual string getTop();
        // virtual string getBottom();
        Box getBox();
};

class LabelTypeA : public Label {

    public:
        LabelTypeA(string label, Box box) {
            
            this->labelString = label;
            this->box = box;
            decodeLabel(label);
        }

        void decodeLabel(string label);

        string getRight();
        
};

#endif