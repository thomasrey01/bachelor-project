#ifndef MAP_H
#define MAP_H

#include <fstream>
#include <map>
#include "components.h"
#include "label.h"
#include "merkle.h"


class Map {
    private:
        std::map<std::string, Shelf*> shelfMap;
        std::map<std::string, Label*> LabelMap;
        fstream *mapFile;
        void readCSV(fstream *file);
        MerkleTree<Shelf> *tree;

    public:
        Map(fstream *file)
        {
            this -> mapFile = file;
            readCSV(file);
        }
};

#endif