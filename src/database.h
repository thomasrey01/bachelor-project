#ifndef DB_H
#define DB_H

#include <fstream>

using namespace std;

class Database {

    private:
        fstream *mapFile;

    public:
        Database(fstream *file)
        {
            this->mapFile = file;
        }
        void read_database(string label);
        void create_database(fstream *csv);
};

#endif