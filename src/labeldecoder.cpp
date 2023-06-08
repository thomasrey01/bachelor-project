#include "labeldecoder.h"

Label *LabelDecoder::decode(labelType type, string label)
{
    // Taking into account the two types of labels: A01-01-1 and B-18-01
    if (label.length() <= 0) {
        std::cerr << "Cannot decode empty label\n";
        return nullptr;
    }
    Label *lab;
    lab->type = type;
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

    return lab;
}