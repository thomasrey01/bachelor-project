#include "map.h"
#include "signal.h"
#include <iostream>
#include <fstream>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

using namespace std;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        cout << "Invalid arguments\n ";
        cout << "Usage " << argv[0] << " <path to csv>\n";
        exit(1);
    }
    fstream file(argv[1], ios::in);

    if (!file.is_open())
    {
        cout << "Error opening file\n";
        exit(1);
    }

    // The Map is the root class of this program.

    Map map(&file);
    string action;
    while(true) {
        cout << "Type \"help\" for a list of possible actions..." << endl;
        cout << "Current label is: " << map.getLabelString() << endl;
        cout << "Current top hash is: " << map.getRootHash() << endl;
        cin >> action;
        if (action == "help") {
            cout << "Type \"exit\" to exit program" << endl;
            cout << "Type \"right\" to move to the right label" << endl;
            cout << "Type \"left\" to move to the left label" << endl;
            cout << "Type \"up\" to move to the top label" << endl;
            cout << "Type \"down\" to move to the bottom label" << endl;
        }
        if (action == "exit") {
            break;
        }
        if (action == "up") {
            map.moveUp();
        } else if (action == "down") {
            map.moveDown();
        } else if (action == "left") {
            map.moveLeft();
        } else if (action == "right") {
            map.moveRight();
        } else if (action == "change") {
            map.makeChange();
        }
    }
    map.clearMap();
}