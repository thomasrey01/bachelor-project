#include "box.h"



bool Box::operator==(const Box &b)
{
    // Since it is only the y values that change, we can just check those.
    return this->bottomLeft.y == b.bottomLeft.y && this->topRight.y == b.topRight.y;
}