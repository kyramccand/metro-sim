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

using namespace std;

// Put any other necessary includes here


class MetroSim {

public:
    void read_stations(string filename);

private:
    // Put any other structs you need here
    Station *stations;
    int num_stations;
};

#endif
