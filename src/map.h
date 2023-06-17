#ifndef MAP_H
#define MAP_H

#include <fstream>
#include <map>
#include "box.h"
#include "labeldecoder.h"

using namespace std;

class Map {
    private:
        map<string, Box> coordMap;
        fstream *mapFile;
        void readCSV(fstream *file);
        LabelDecoder labelDecoder;

    public:
        Map(fstream *file)
        {

            labelDecoder = LabelDecoder();
            this -> mapFile = file;
            readCSV(file);

        }
};

#endif