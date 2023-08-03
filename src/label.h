#ifndef LABEL_H
#define LABEL_H

#include <string>
#include <iostream>
#include "components.h"

using namespace std;

class Label {
    private:
        string labelString;
    
    public:
        Box getBox();
};

#endif