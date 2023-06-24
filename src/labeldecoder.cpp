#include "labeldecoder.h"

Label *LabelDecoder::decode(string label)
{ // TO FINISH LATER AFTER API AND ALL LABELS ARE GIVEN
    // Taking into account the two types of labels: A01-01-1 and B-18-01
    if (label.length() <= 0) {
        std::cerr << "Cannot decode empty label\n";
        return nullptr;
    }
    Label *lab;
    switch (label[0]) {
        case 'A':
            lab->fac = A;
            break;
        case 'B':
            lab->fac = B;
            break;
        case 'C':
            lab->fac = C;
            break;
        case 'D':
            lab->fac = D;
            break;
        case 'E':
            lab->fac = E;
            break;
        case 'F':
            lab->fac = F;
            break;
        case 'G':
            lab->fac = G;
            break;
        case 'H':
            lab->fac = H;
            break;
    }

    if (label[1] == '-') {
        lab->type = extended;
        lab->
    } else {
        lab->type = compact;
    }

    return lab;
}