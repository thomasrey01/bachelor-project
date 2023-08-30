#ifndef COMPONENTS_H
#define COMPONENTS_H
#include "utils/md5.h"
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

/*
 * Declaration of the different components of the warehouse.
*/

class Box
{

public:
    struct coord
    {
        double x;
        double y;
    };

    Box() {} // Empty constructor

    Box(struct coord left, struct coord right, int face, int z)
    {
        this->bottomLeft = left;
        this->topRight = right;
        this->face = face;
        this->z = z;
        height = abs(left.y - right.y);
    };

    vector<coord> getCoords();

    double getHeight();

    void setValues(struct coord left, struct coord right, int face, int z);

    bool operator==(Box const &b);

private:
    double height;
    double z;
    struct coord bottomLeft;
    struct coord topRight;
    int face;
};

class Shelf
{
    vector<Box> boxes;
    string heightString;

public:
    Shelf(vector<Box> boxes)
    {
        this->boxes = boxes;
        string heights = "";

        for (uint i = 0; i < boxes.size(); i++)
        {
            heights.append(to_string(boxes[i].getHeight()));
        }
        this->heightString = heights;
    }

    Shelf() {
        this->heightString = "";
    }

    void addBox(Box box);

    void updateString(string newString);
    string getString();
    string getHash();
};

#endif