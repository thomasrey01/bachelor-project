#include "components.h"

bool Box::operator==(const Box &b)
{
    // Since it is only the y values that change, we can just check those.
    return this->bottomLeft.y == b.bottomLeft.y && this->topRight.y == b.topRight.y;
}

double Box::getHeight()
{
    return abs(this->topRight.y - this->bottomLeft.y);
}

void Box::setValues(struct coord left, struct coord right, int face, int z)
{
    this->bottomLeft = left;
    this->topRight = right;
    this->face = face;
    this->z = z;
    height = abs(left.y - right.y);
};

vector<Box::coord> Box::getCoords()
{
    vector<struct coord> vec = {this->bottomLeft, this->topRight};
    return vec;
}

string Shelf::getString()
{
    return this->heightString;
}

string Shelf::getHash()
{
    return md5(this->heightString);
}

void Shelf::addBox(Box box)
{
    this->boxes.insert(boxes.end(), box);
    this->heightString.append(to_string(box.getHeight()));
}
