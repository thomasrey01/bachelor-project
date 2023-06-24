#include "map.h"
#include <iostream>
#include <vector>
#include <sstream>

void Map::readCSV(fstream *file)
{
    vector<vector<string>> content;
    vector<string> row;
    string line, word;
    Box(box);


    if (file->is_open())
    {
        while (getline(*file, line))
        {
            row.clear();
            stringstream str(line);

            getline(str, word, ',');
            Label *label = labelDecoder.decode(word);
            // while (getline(str, word, ','))
            //     cout << word << " ";
            cout << endl;
            content.push_back(row);
        }
    }
}