#ifndef TRIPLE_H
#define TRIPLE_H

class Box {

    struct coord {
        double x;
        double y;
    };

    private:
        struct coord bottomLeft;
        struct coord topRight;
        int face;

    public:
        

        Box(struct coord left, struct coord right, int face) {
            this->bottomLeft = left;
            this->topRight = right;
            this->face = face;
        }

        bool operator==(Box const &b);
        
};

#endif