#ifndef MAPLABEL_H
#define MAPLABEL_H

#include <string>
#include <iostream>
#include "components.h"

using namespace std;

/*
 * Class declaration for Label and LabelTypeA
*/

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
        virtual string getRight();
        virtual string getLeft();
        virtual string getTop();
        virtual string getBottom();
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
        string getLeft();
        string getTop();
        string getBottom();

    private:
        const int maxHeight = 4;
        const int maxLength = 15;
        
};

#endif