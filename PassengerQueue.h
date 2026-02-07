/*
 *  PassengerQueue.h
 *  Kyra McCandless
 *  2/6/26
 *
 *  CS 15 Project 1 MetroSim
 *
 *  PassengerQueue is a class that represents an a line of Passengers.
 *  PassengerQueue objects are constructed as emtpy, and clients can add
 *  Passengers to the back of the queue, remove Passengers from the front,
 *  measure the size, access the first Passenger, or print data about the
 *  PassengerQueue.
 */

#ifndef __PASSENGERQUEUE_H__
#define __PASSENGERQUEUE_H__

#include "Passenger.h"
#include <iostream>
#include <list>

class PassengerQueue {
public:
    Passenger front();
    void dequeue();
    void enqueue(const Passenger &passenger);
    int size();
    void print(std::ostream &output);
private:
    std::list<Passenger> queue;
};

#endif