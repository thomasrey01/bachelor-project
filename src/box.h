#ifndef TRIPLE_H
#define TRIPLE_H
#include <cstdlib>

class Box {

    struct coord {
        double x;
        double y;
    };

    private:
        double height;
        struct coord bottomLeft;
        struct coord topRight;
        int face;

    public:
        
        Box(); // Empty constructor

        Box(struct coord left, struct coord right, int face) {
            this->bottomLeft = left;
            this->topRight = right;
            this->face = face;
            height = abs(left.y - right.y);
        }

        bool operator==(Box const &b);
        
};

#endif