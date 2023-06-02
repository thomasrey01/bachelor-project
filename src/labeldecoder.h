#ifndef LABELDECODER_H
#define LABELDECODER_H

enum labelType {
    extended=1,
    compact=2
};

enum facility {
    A, B, C, D, E, F, G, H
};

struct Label {
    enum facility fac;
    enum labelType label;
    int aisle, column, height;
};

class LabelDecoder {
    public: 

        struct Label decode(int type, char label[]);
};

#endif