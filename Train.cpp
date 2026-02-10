/*
 *  Train.cpp
 *  Kyra McCandless
 *  2/6/26
 *
 *  CS 15 Project 1 MetroSim
 *
 *  This file contains an implementation of the Train class.
 *
 */

#include "Train.h"

Train::Train() {
    curr_station = 0;
}

Train::Train(int station_count) {
    num_stations = station_count;
    curr_station = 0;
}

void Train::move() {
    if (curr_station < num_stations - 1) {
        curr_station++;
    }
    else { // Catch the edge case of train having to loop around
        curr_station = 0;
    }
    return;
}

int Train::getStation() {
    return curr_station;
}

void Train::print(ostream &output) {
    return;
}

void Train::boardPassengers(int station_num) {
    return;
}

void Train::depositPassengers(int station_num) {
    return;
}