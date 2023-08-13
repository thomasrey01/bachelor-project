#ifndef COMPONENTS_H
#define COMPONENTS_H
#include "utils/md5.h"
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

class Box {

    struct coord {
        double x;
        double y;
    };

    private:
        double height;
        double z;
        struct coord bottomLeft;
        struct coord topRight;
        int face;

    public:
        
        Box(); // Empty constructor

        Box(struct coord left, struct coord right, int face, int z) {
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
        
};

class Shelf {
    vector<Box> boxes;
    string heightString;
    
public:

    Shelf(vector<Box> boxes) {
        this->boxes = boxes;
        string heights = "";

        for (int i = 0; i < boxes.size(); i++) {
            heights.append(to_string(boxes[i].getHeight()));
        }
        this->heightString = heights;
    }

    string getString();
    string getHash();
};

#endif