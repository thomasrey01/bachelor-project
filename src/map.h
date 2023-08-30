#ifndef MAP_H
#define MAP_H

#include <fstream>
#include <map>
#include "components.h"
#include "label.h"
#include "merkle.h"

/*
 * Declaration of Map class, the constructor assigns the mapFile field to
 * the filestream pointer, reads the csv to for the shelfMap and LabelMap
 * and calls the makeTree method.
*/

class Map {
    private:
        std::map<std::string, Shelf*> shelfMap;
        std::vector<Shelf*> shelfVec;
        std::map<std::string, Label*> LabelMap;
        fstream *mapFile;
        Label *currentLabel;
        MerkleTree<Shelf> *tree;
        void readCSV(fstream *file);
        void makeTree();
        

    public:
        Map(fstream *file)
        {
            this -> mapFile = file;
            readCSV(file);
            makeTree();
        }
        string getRootHash();
        string getLabelString();
        void clearMap();
        void printTree();
        void moveUp();
        void moveDown();
        void moveRight();
        void moveLeft();
        void makeChange();
};

#endif