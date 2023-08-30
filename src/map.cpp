#include "map.h"
#include "label.h"
#include "signal.h"
#include <iostream>
#include <vector>
#include <iterator>
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

            LabelTypeA *label = new LabelTypeA(labelstr, box);

            this->LabelMap.insert_or_assign(labelstr, label);

            shelf->addBox(box);
            if (i == 1) {
                this->currentLabel = label;
            }
            if (i % 4 == 0) { // At every 4 iterations of boxes, we add them to a single shelf.
                this->shelfMap.insert_or_assign(shelf->getHash(), shelf);
                shelfVec.insert(shelfVec.end(), shelf);
                shelf = new Shelf();
            }
        }
        delete(shelf);
    }
}

void Map::makeTree() {
    this->tree = new MerkleTree<Shelf>(shelfVec);
}


void Map::clearMap() {
    this->tree->clearTree();
    delete (this->tree);
    for (auto shelf : this->shelfVec) {
        delete(shelf);
    }
    for (auto [key, value] : this->LabelMap) {
        delete(value);
    }
}

string Map::getLabelString() {
    return this->currentLabel->labelString;
}

string Map::getRootHash() {
    return this->tree->getHash();
}

void Map::printTree() {
    this->tree->preOrderPrint();
}

void Map::moveUp() {
    LabelTypeA *labelA = dynamic_cast<LabelTypeA*>(this->currentLabel);
    string nextLabelString = labelA->getTop();
    if (nextLabelString != "") {
        LabelTypeA *nextLabel = dynamic_cast<LabelTypeA*>(this->LabelMap[nextLabelString]);
        this->currentLabel = nextLabel;
    } else {
        cout << "No available label" << endl;
    }
}

void Map::moveDown() {
    LabelTypeA *labelA = dynamic_cast<LabelTypeA*>(this->currentLabel);
    string nextLabelString = labelA->getBottom();
    if (nextLabelString != "") {
        LabelTypeA *nextLabel = dynamic_cast<LabelTypeA*>(this->LabelMap[nextLabelString]);
        this->currentLabel = nextLabel;
    } else {
        cout << "No available label" << endl;
    }
}

void Map::moveRight() {
    LabelTypeA *labelA = dynamic_cast<LabelTypeA*>(this->currentLabel);
    string nextLabelString = labelA->getRight();
    if (nextLabelString != "") {
        LabelTypeA *nextLabel = dynamic_cast<LabelTypeA*>(this->LabelMap[nextLabelString]);
        this->currentLabel = nextLabel;
    } else {
        cout << "No available label" << endl;
    }
}

void Map::moveLeft() {
    LabelTypeA *labelA = dynamic_cast<LabelTypeA*>(this->currentLabel);
    string nextLabelString = labelA->getLeft();
    if (nextLabelString != "") {
        LabelTypeA *nextLabel = dynamic_cast<LabelTypeA*>(this->LabelMap[nextLabelString]);
        this->currentLabel = nextLabel;
    } else {
        cout << "No available label" << endl;
    }
}

void Map::makeChange() {
    auto it = this->tree->leafMap.begin();
    MerkleLeaf<Shelf> *leaf = dynamic_cast<MerkleLeaf<Shelf>*>(it->second);
    Shelf *shelf = leaf->content;
    string shelfString = shelf->getString();
    shelf->updateString(shelfString.append("1"));
    leaf->updateTree();
    tree->updateHash();
}