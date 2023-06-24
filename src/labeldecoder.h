#ifndef LABELDECODER_H
#define LABELDECODER_H

#include <string>
#include <assert.h>
#include <iostream>

using namespace std;

enum labelType {
    extended=1,
    compact=2
};

enum facility {
    A, B, C, D, E, F, G, H
};

struct Label {
    enum facility fac;
    enum labelType type;
    int aisle, column, height;
};

class LabelDecoder {
    public: 
        Label *decode(string label);
};

#endif