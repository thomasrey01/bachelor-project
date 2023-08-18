#include "map.h"
#include "label.h"
#include <iostream>
#include <vector>
#include <sstream>

void Map::readCSV(fstream *file)
{
    string line, word;


    if (file->is_open())
    {
        float x0, x1, y0, y1, z;
        int face;
        int i = 0;

        Shelf *shelf = new Shelf();
        string labelstr;

        getline(*file, line); // discard the first line
        while (getline(*file, line))
        {
            i++;
            stringstream str(line);

            getline(str, word, ',');

            labelstr = word;


            getline(str, word, ',');
            x0 = stof(word);

            getline(str, word, ',');
            x1 = stof(word);

            getline(str, word, ',');
            y0 = stof(word);

            getline(str, word, ',');
            y1 = stof(word);

            getline(str, word, ',');
            z = stof(word);

            getline(str, word, ',');
            face = stoi(word);


            Box::coord left;
            left.x = x0;
            left.y = y0;
            Box::coord right;
            right.x = x1;
            right.y = y1;

            Box box(left, right, face, z);

            LabelTypeA label(labelstr, box);

            // this->LabelMap.insert_or_assign(labelstr, &label);
            this->LabelMap.insert_or_assign(labelstr, &label);

            shelf->addBox(box);
            if (i % 4 == 0) {
                this->shelfMap.insert_or_assign(shelf->getHash(), shelf);
                shelf = new Shelf();
            }
            cout << box.getHeight() << endl;
            cout << shelf->getString() << endl;
            break;
        }
    }
}