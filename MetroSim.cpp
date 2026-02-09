/*
 *  MetroSim.cpp
 *  Kyra McCandless
 *  2/6/26
 *
 *  CS 15 Project 1 MetroSim
 *
 *  This file contains an implementation of the MetroSim class.
 *
 */

#include "MetroSim.h"


/*
 * name:      MetroSim
 * purpose:   construct a Metrosim
 * arguments: none
 * returns:   none
 * effects:   creates an empty Train to represent the train
 * other:     none
 */ 
MetroSim::MetroSim() {
    
}

/*
 * name:      read_stations
 * purpose:   read station data from the file called filename
 * arguments: the string name of the file to read station data from
 * returns:   none
 * effects:   populates the station vector with station data
 * other:     none
 */ 
void MetroSim::read_stations(string filename) {
    ifstream infile; // Initialize the file stream
    infile.open(filename); // Attempt to open the file
    // Catch errors
    if (infile.fail()) {
        cerr << "Error: could not open file " << filename;
        exit(EXIT_FAILURE);
    }

    // Read line by line
    string line;
    while (getline (infile, line)) {
        // Add station
        stations.push_back(new Station(line));
    }
    infile.close();
}

/*
 * name:      print
 * purpose:   communicate information about the MetroSim
 * arguments: the output stream to communicate information to
 * returns:   none
 * effects:   none
 * other:     none
 */ 
void MetroSim::print(ostream &output) {
    // Print info about each station
    for (int i = 0; i < stations.size(); i++) {
        cout << "[" << i+1 << "] ";
        stations[i]->print(cout);
        cout << endl;
    }
}

/*
 * name:      moveTrain
 * purpose:   simulate the Train moving to the next station
 * arguments: none
 * returns:   none
 * effects:   none
 * other:     none
 */ 
void MetroSim::moveTrain() {
    train.move();
}
