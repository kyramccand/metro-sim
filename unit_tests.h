/*
 *  unit_tests.h
 *  Kyra McCandless
 *  2/6/26
 *
 *  CS 15 Project 1 MetroSim
 *
 *  Test that each method of the Passenger and PassengerQueue class function
 *  as expected.
 *
 */

#include "MetroSim.h"
#include <sstream>
#include <cassert>

using namespace std;

// Tests that passenger data is printed in the correct format
void printPassenger() {
    Passenger passenger(1, 2, 3); // Create a passenger
    // Collect print
    stringstream ss;
    passenger.print(ss);
    assert(ss.str() == "[1, 2->3]"); // Compare to expected result
}

// Tests that PassengerQueue data is printed in the correct format
void printPQ() {
    // Initialize a PassengerQueue with many Passengers
    PassengerQueue line;
    line.enqueue(Passenger(1, 2, 3));
    line.enqueue(Passenger(2, 3, 4));
    line.enqueue(Passenger(3, 2, 3));
    // Collect print
    stringstream ss;
    line.print(ss);
    assert(ss.str() == "[1, 2->3][2, 3->4][3, 2->3]"); // Compare to expected
}

// Tests for correct sizing of emtpy PassengerQueues
void sizeEmpty() {
    // Initialize empty PassengerQueue
    PassengerQueue line;
    assert(line.size() == 0); // Check that its size is 0
}

// Tests for correct sizing of emtpy PassengerQueues
void size() {
    // Initialize PassengerQueue with many Passengers
    PassengerQueue line;
    for (int i = 0; i < 100; i++) {
        line.enqueue(Passenger(i+1, 1, 2));
    }
    assert(line.size() == 100); // Check for proper size
}

// Tests enqueue on an empty PassengerQueue
// Afterwards, the PassengerQueue should have a size of 1 and display the
// data of the one Passenger we added.
void enqueuOne() {
    // Initialize an emtpy PassengerQueue
    PassengerQueue line;
    // Enqueue one Passenger
    line.enqueue(Passenger(0, 1, 2));
    stringstream ss;
    line.print(ss);
    // Check for expected conditions
    assert(line.size() == 1);
    assert(ss.str() == "[0, 1->2]");
}

// Tests enqueue repeatedly
// Afterwards, the PassengerQueue should have a size of however many times we
// added Passengers and should display the data for every Passenger in the
// proper order.
void enqueuRepeated() {
    // Initialize an emtpy PassengerQueue
    PassengerQueue line;
    // Enqueue one Passenger
    for (int i = 0; i < 5; i++) {
        line.enqueue(Passenger(i, 1, 2));
    }
    stringstream ss;
    line.print(ss);
    // Check for expected conditions
    assert(line.size() == 5);
    assert(ss.str() == "[0, 1->2][1, 1->2][2, 1->2][3, 1->2][4, 1->2]");
}

// Tests front on an empty PassengerQueue
// Attempts to access the front of an empty PassengerQueue
// This should result in a runtime error with the appropriate message
void frontEmpty() {
    // Initialize an emtpy PassengerQueue
    PassengerQueue line;
    bool runtime_error_thrown = false; // To store if a runtime error was thrown
    string error_message = ""; // To store the resulting message
    try {
        line.front(); // Access the front
    }
    catch (const runtime_error &e) { // Collect data about the error
        runtime_error_thrown = true;
        error_message = e.what();
    }
    // Check for expected error and message
    assert(runtime_error_thrown);
    assert(error_message == "cannot access front of empty queue");
}

// Tests front on a valid PassengerQueue
void frontValid() {
    // Initialize a valid PassengerQueue
    PassengerQueue line;
    line.enqueue(Passenger(0, 1, 2));
    // Get the front
    stringstream ss;
    line.front().print(ss);
    assert(ss.str() == "[0, 1->2]"); // Check for expected front
}

// Tests Station constructor and getName simultaneously
void stationWithName() {
    Station station("Station 1");
    assert(station.getName() == "Station 1");
}
