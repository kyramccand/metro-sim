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
        void move();
        void print(ostream &output);
    private:
        vector<Station *> stations;
        int curr_station;
        void boardPassengers(int station_num);
        void depositPassengers(int station_num);
};

#endif