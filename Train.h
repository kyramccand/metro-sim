/*
 *  Train.h
 *  Kyra McCandless
 *  2/8/26
 *
 *  CS 15 Project 1 MetroSim
 *
 *  Train is a class that represents an train with a current station, and
 *  Passengers organized into PassengerQueues based on their departing station.
 */

#ifndef __TRAIN_H__
#define __TRAIN_H__

#include "Station.h"
#include "Passenger.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Train {
    public:
        Train();
        Train(int station_count);
        void move();
        void print(ostream &output);
        int getStation();
    private:
        vector<PassengerQueue> passengers;
        int curr_station;
        int num_stations;
        void boardPassengers(Station *station);
        void depositPassengers(int station_num);
};

#endif