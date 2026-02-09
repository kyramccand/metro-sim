/* TODO: Write header comment
 *
 */

#include "Station.h"

Station::Station(string station_name) {
    name = station_name;
}

string Station::getName() {
    return name;
}

PassengerQueue Station::getArrivals(int station_num) {
    PassengerQueue queue;
    return queue;
}

PassengerQueue Station::getDepartures(int station_num) {
    PassengerQueue queue;
    return queue;
}

void Station::addPassenger(Passenger passenger) {
    departures.enqueue(passenger);
}

void Station::clear() {
    return;
}

void Station::print(ostream &output) {
    output << "{";
    departures.print(output);
    output << "}";
   
}