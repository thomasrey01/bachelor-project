#include "map.h"
#include <iostream>
#include <fstream>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

using namespace std;


int main(int argc, char *argv[])
{
    if (argc != 2) {
        cout << "Invalid arguments\n ";
        cout << "Usage " << argv[0] << " <path to csv>\n";
        exit(1);
    }
    fstream file (argv[1], ios::in);

    if (!file.is_open()) {
        cout << "Error opening file\n";
        exit(1);
    }

    Map map(&file);
    
    // map.readCSV(argv[1]);
}