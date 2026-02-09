/*
 *
 */

#include "MetroSim.h"

void MetroSim::read_stations(string filename) {
    ifstream infile;
    infile.open(filename);
    if (infile.fail()) {
        cerr << "Error: could not open file " << filename;
        exit(EXIT_FAILURE);
    }

    string line;

    while (getline (infile, line)) {
        cout << line << endl;
    }

    infile.close();
}
