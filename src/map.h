#ifndef MAP_H
#define MAP_H

#include <fstream>
#include <map>
#include "triple.h"

using namespace std;

class Map {
    private:
        map<string, Triple> coordMap;
        fstream *mapFile;
        void readCSV(fstream *file);

    public:
        Map(fstream *file)
        {
            this -> mapFile = file;

        }
};

#endif