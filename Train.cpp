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

/*
 * name:      Train
 * purpose:   construct a Train with no information specified
 * arguments: none
 * returns:   none
 * effects:   default sets the current station to the first station
 * other:     is called by default
 */
Train::Train() {
    curr_station = 0;
}

/*
 * name:      Train
 * purpose:   construct a Train from the number of stations it loops
 * arguments: the integer representing the number of stations
 * returns:   none
 * effects:   default sets the current station to the first station and updates
 *            the number of stations
 * other:     none
 */
Train::Train(int station_count) {
    num_stations = station_count;
    curr_station = 0;
}

/*
 * name:      move
 * purpose:   simulate the Train moving from one station to the next, picking up
 *            and dropping off Passengers, and looping around if necassary
 * arguments: none
 * returns:   none
 * effects:   updates the current station either by incremementing it or
 *            reseting it to 0 if needed
 * other:     none
 */
void Train::move() {
    if (curr_station < num_stations - 1) {
        curr_station++;
    }
    else { // Catch the edge case of train having to loop around
        curr_station = 0;
    }
    return;
}

/*
 * name:      getStation
 * purpose:   provide read only access to the station number the train is
 *            currently at
 * arguments: none
 * returns:   the integer representing the station number
 * effects:   none
 * other:     none
 */
int Train::getStation() {
    return curr_station;
}

/*
 * name:      print
 * purpose:   communicate information about the Train
 * arguments: the output stream to communicate information to
 * returns:   none
 * effects:   none
 * other:     none
 */
void Train::print(ostream &output) {
    return;
}

/*
 * name:      boardPassengers
 * purpose:   
 * arguments: 
 * returns:   
 * effects:   
 * other:     
 */
void Train::boardPassengers(int station_num) {
    return;
}

/*
 * name:      depositPassengers
 * purpose:   
 * arguments: 
 * returns:   
 * effects:   
 * other:     
 */
void Train::depositPassengers(int station_num) {
    return;
}