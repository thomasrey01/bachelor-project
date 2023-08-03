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
    
    string getHash() {
        string heights = "";
        for (int i = 0; i < boxes.size(); i++) {
            heights.append(to_string(boxes[i].getHeight())); // Problem for the future:
            // floating point imprecision could impact hash of height. Fix later, I guess
            // round.

        }
        return md5(heights);
    }
};

#endif