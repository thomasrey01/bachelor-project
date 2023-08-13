#ifndef MAP_H
#define MAP_H

#include <fstream>
#include <map>
#include "components.h"
#include "labeldecoder.h"
#include "merkle.h"

using namespace std;

class Map {
    private:
        map<string, Shelf*> shelfMap;
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