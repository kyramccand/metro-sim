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

// Tests adding a single Passenger to a Station
// Afterwards, the station should have one more passenger and the Passenger
// we added should be at the end of the line
void addOnePassengerStation() {
    Station station("Station"); // Initialize an empty station
    station.addPassenger(Passenger(0, 0, 0)); // Add one passenger
    // Collect print
    stringstream ss;
    station.print(ss);
    assert(ss.str() == "Station {[0, 0->0]}"); // Check for expected Passenger data
}

// Tests adding many Passengers to a Station
// Afterwards, the station should have have the number of Passengers we added
// and the correct data
void addManyPassengersStation() {
    Station station("Station"); // Initialize an empty station
    for (int i = 0; i < 4; i++) { // Add many passengers
        station.addPassenger(Passenger(0, 0, 0));
    }
    // Collect print
    stringstream ss;
    station.print(ss);
    // Check for expected Passenger data
    assert(ss.str() == "Station {[0, 0->0][0, 0->0][0, 0->0][0, 0->0]}");
}


// Tests correct number of passengers in an empty MetroSim
void numPassengersEmtpy() {
    MetroSim sim; // Intialize an empty MetroSim
    assert(sim.getNumPassengers() == 0); // Check that it is actually empty
}

// Tests correct number of passengers in a MetroSim with many Passengers at the
// same station
void numPassengersMany() {
    // Intialize an MetroSim with many Passengers at the same station
    MetroSim sim;
    sim.read_stations("test_stations1.txt");
    for (int i = 0; i < 100; i++) {
        sim.addPassenger(0, 0);
    }
    // Check that all passengers are counted
    assert(sim.getNumPassengers() == 100);
}

// Tests correct number of passengers in a MetroSim with many Passengers at many
// stations
void numPassengersManyAtMany() {
    // Intialize an MetroSim with many Passengers at many stations
    MetroSim sim;
    sim.read_stations("test_stations1.txt");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 100; j++) {
            sim.addPassenger(i, 0);
        }
    }
    // Check that all passengers are counted for
    assert(sim.getNumPassengers() == 500);
}

// Tests that the simulator can read stations with one word names
void readStationsOneWord() {
    // Initialize a MetroSim and read the test stations
    MetroSim sim;
    sim.read_stations("test_stations2.txt");
    // Collect the print
    stringstream ss;
    sim.print(ss);
    // Check for expected data
    assert(ss.str() == "TRAIN: [0] 1 {}\n"
                        "       [1] 2 {}\n"
                        "       [2] 3 {}\n"
                        "       [3] 4 {}\n"
                        "       [4] 5 {}\n");
}

// Tests that the simulator can read stations with multiple word names
void readStationsMultiWord() {
    // Initialize a MetroSim and read the test stations
    MetroSim sim;
    sim.read_stations("test_stations3.txt");
    // Collect the print
    stringstream ss;
    sim.print(ss);
    // Check for expected data
    assert(ss.str() == "TRAIN: [0] Station 1 {}\n"
                        "       [1] Station 2 {}\n");
}


// To test getStation, I temporarily set MetroSim's train member to public

// // Tests that the train starts at station 0
// void startsAtZero() {
//     MetroSim sim;
//     assert(sim.train.getStation() == 0);
// }

// Tests that the train accurately moves forwards once
// Starts the train at the beginning, attempts to move it forwards
// Afterwards, the train should be one spot forwards
void moveOnce() {
    // Initialize a MetroSim from test station data
    MetroSim sim;
    sim.read_stations("test_stations4.txt");
    sim.moveTrain(); // Move the train forwards once
    // Collect the print
    stringstream ss;
    sim.print(ss);
    // Check for expected data
    assert(ss.str() == "       [0] s1 {}\n"
                        "TRAIN: [1] s2 {}\n"
                        "       [2] s3 {}\n");
}

// Tests that the train loops around properly
// Starts train at the beginning and moves it forwards a bunch of times
// Afterwards, the train should have looped around and be in the expected
// position
void loopAround() {
    // Initialize a MetroSim and read the test stations
    MetroSim sim;
    sim.read_stations("test_stations4.txt");
    // Move the train forwards many times
    for (int i = 0; i < 100; i++) {
        sim.moveTrain();
    }
    // Collect the print
    stringstream ss;
    sim.print(ss);
    // Check for expected data
    assert(ss.str() == "       [0] s1 {}\n"
                        "TRAIN: [1] s2 {}\n"
                        "       [2] s3 {}\n");
}

