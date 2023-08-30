#include "label.h"
/*
 * These methods decode the label and adds those values to the correct
 * label field.
*/

void LabelTypeA::decodeLabel(string label) {
    this->faclity = label[0];
    string aisle = "";
    aisle.push_back(label[1]);
    aisle.push_back(label[2]);
    this->aisle = stoi(aisle);
    string column = "";
    column.push_back(label[4]);
    column.push_back(label[5]);
    this->column = stoi(column);
    string height = "";
    height.push_back(label[7]);
    this->height = stoi(height);
}

void Label::decodeLabel(string label) {
    this->labelString = label;
}

/*
 * Group of methods to get neighbouring labels, this checks if the shelf 
 * sits at a boundary or not and returns an empty string if it does.
*/

string Label::getRight() { return ""; }
string Label::getLeft() { return ""; }
string Label::getTop() { return ""; }
string Label::getBottom() { return ""; }

string LabelTypeA::getRight() {
    if (this->column >= this->maxLength) {
        return "";
    }
    string resString = "";
    resString.push_back(this->faclity);

    if (this->aisle < 10) {
        resString.append("0");
    }
    resString.append(to_string(this->aisle));
    resString.append("-");

    if (this->column + 1 < 10) {
        resString.append("0");
    }
    resString.append(to_string(this->column + 1));
    resString.append("-");
    
    resString.append(to_string(this->height));

    return resString;
}

string LabelTypeA::getLeft() {
    if (this->column <= 1) {
        return "";
    }
    string resString = "";
    resString.push_back(this->faclity);

    if (this->aisle < 10) {
        resString.append("0");
    }
    resString.append(to_string(this->aisle));
    resString.append("-");

    if (this->column - 1 < 10) {
        resString.append("0");
    }
    resString.append(to_string(this->column - 1));
    resString.append("-");
    
    resString.append(to_string(this->height));

    return resString;
}

string LabelTypeA::getTop() {
    if (this->height >= this->maxHeight) {
        return "";
    }
    string resString = "";
    resString.push_back(this->faclity);

    if (this->aisle < 10) {
        resString.append("0");
    }
    resString.append(to_string(this->aisle));
    resString.append("-");

    if (this->column< 10) {
        resString.append("0");
    }
    resString.append(to_string(this->column));
    resString.append("-");
    
    resString.append(to_string(this->height + 1));

    return resString;
}

string LabelTypeA::getBottom() {
    if (this->height <= 1) {
        return "";
    }
    string resString = "";
    resString.push_back(this->faclity);

    if (this->aisle < 10) {
        resString.append("0");
    }
    resString.append(to_string(this->aisle));
    resString.append("-");

    if (this->column + 1 < 10) {
        resString.append("0");
    }
    resString.append(to_string(this->column));
    resString.append("-");
    
    resString.append(to_string(this->height - 1));

    return resString;
}