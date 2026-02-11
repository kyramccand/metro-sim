/*
 *  Station.h
 *  Kyra McCandless
 *  2/8/26
 *
 *  CS 15 Project 1 MetroSim
 *
 *  Station is a class that represents an train station with a Passengers
 *  organized into a PassengerQueue.
 */


#ifndef __STATION_H__
#define __STATION_H__

#include "Passenger.h"
#include "PassengerQueue.h"
#include <iostream>
#include <string>

using namespace std;

class Station {
    public:
        Station(string station_name);
        string getName();
        PassengerQueue getPassengers();
        void addPassenger(Passenger passenger);
        Passenger popFrontPassenger();
        void print(ostream &output);
    private:
        PassengerQueue passengers;
        string name;
        int num_passengers;
};

#endif