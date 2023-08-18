#include "label.h"

void LabelTypeA::decodeLabel(string label) {
    this->faclity = label[0];
    string aisle = "";
    aisle.append(to_string(label[1]));
    aisle.append(to_string(label[2]));
    this->aisle = stoi(aisle);
    string column = "";
    column.append(to_string(label[4]));
    column.append(to_string(label[5]));
    this->column = stoi(column);
    string height = "";
    height.append(to_string(label[7]));
    this->height = stoi(height);
}

void Label::decodeLabel(string label) {
    this->labelString = label;
}

// string LabelTypeA::getRight() {

// }