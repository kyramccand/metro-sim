/*
 *  Passenger.h
 *  Kyra McCandless
 *  2/6/26
 *
 *  CS 15 Project 1 MetroSim
 *
 *  Passenger is a class that represents an passenger with an ID, a starting
 *  station, and an ending station. Passenger objects are constructed with this
 *  information, which clients can access or display but not edit.
 */

#ifndef __PASSENGER_H__
#define __PASSENGER_H__

#include <iostream>

class Passenger {
   public:
    Passenger(int id, int startingStation, int endingStation);
    int getId();
    int getStartingStation();
    int getEndingStation();
    void print(std::ostream &output);

   private:
    int id;
    int startingStation;
    int endingStation;
};

#endif

