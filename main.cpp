/*
 *
 */

#include <iostream>
#include <fstream>
#include <string>

#include "MetroSim.h"

using namespace std;

int main(int argc, char *argv[]) {
    cout << "Printing passenger...";
    Passenger passenger(1, 1, 2);
    passenger.print(cout);
    cout << endl;

    PassengerQueue line;
    line.enqueue(Passenger(1, 1, 2));
    line.enqueue(Passenger(2, 3, 4));
    line.enqueue(Passenger(3, 4, 5));
    cout << "Printing line...";
    line.print(cout);
    cout << endl;
    
    return 0;
}
