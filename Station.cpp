/*
 *  Station.cpp
 *  Kyra McCandless
 *  2/6/26
 *
 *  CS 15 Project 1 MetroSim
 *
 *  This file contains an implementation of the Station class.
 *
 */

#include "Station.h"

/*
* name:      Station
* purpose:   construct a Station from a name
* arguments: the string name of the station
* returns:   none
* effects:   assigns the name to station_name
* other:     none
*/

Station::Station(string station_name) {
    name = station_name;
    num_passengers = 0;
}

/*
* name:      getName
* purpose:   provide read only access to the name of a Station
* arguments: none
* returns:   the string name of the Station
* effects:   none
* other:     none
*/
string Station::getName() {
    return name;
}

/*
* name:      getPassengers
* purpose:   provide access to the arrivals at the Station
* arguments: none
* returns:   a PassengerQueue representing the line of Passengers
* effects:   none
* other:     none
*/
PassengerQueue Station::getPassengers() {
    return passengers;
}

/*
* name:      addPassenger
* purpose:   add a passenger to the line of arrivals
* arguments: the Passenger representing the passenger to add
* returns:   none
* effects:   none
* other:     none
*/
void Station::addPassenger(Passenger passenger) {
    passengers.enqueue(passenger);
}

/*
* name:      popFrontPassenger
* purpose:   remove the first passenger from the line of arrivals
* arguments: none
* returns:   the Passenger representing the passenger who was at the front
* effects:   none
* other:     none
*/
Passenger Station::popFrontPassenger() {
    Passenger frontPassenger = passengers.front(); // Save the first passenger
    passengers.dequeue(); // Remove the first passenger
    return frontPassenger;
}



/*
* name:      print
* purpose:   communicate information about the Station
* arguments: a reference to the output stream to communicate information to
* returns:   none
* effects:   none
* other:     none
*/
void Station::print(ostream &output) {
    output << name << " {";
    passengers.print(output);
    output << "}";
}