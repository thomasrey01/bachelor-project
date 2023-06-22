#include "map.h"
#include <iostream>
#include <vector>
#include <sstream>

void Map::readCSV(fstream *file)
{
    vector<vector<string>> content;
    string line;

    vector<string> row;

    if (file->is_open()) {
        while (getline(*file, line)) {
            stringstream str(line);
            Label lab;
            coordMap
        }
    }

}