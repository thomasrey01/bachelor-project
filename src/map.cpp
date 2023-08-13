#include "map.h"
#include <iostream>
#include <vector>
#include <sstream>

void Map::readCSV(fstream *file)
{
    vector<vector<string>> content;
    vector<string> row;
    string line, word;


    if (file->is_open())
    {
        int i = 0;
        while (getline(*file, line))
        {
            if (i == 10) {
                break;
            }
            i++;
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