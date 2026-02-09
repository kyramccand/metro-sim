/*
 *
 */

#ifndef _METROSIM_H_
#define _METROSIM_H_

#include "Passenger.h"
#include "PassengerQueue.h"
#include "Station.h"
#include "Train.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class MetroSim {

public:
    MetroSim();
    void read_stations(string stations_filename);
    void print(ostream &output);
private:
    vector<Station *> stations;
    Train train;
};

#endif
