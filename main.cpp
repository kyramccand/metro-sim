/*
 *
 */

#include "MetroSim.h"

using namespace std;

void query(istream &input, MetroSim *sim);
void handlePassenger(int d_num, int a_num, MetroSim *sim);

int main(int argc, char *argv[]) {

    // Check for expected command line arguments
    if (argc < 3) {
        cout << "Usage: ./MetroSim stationsFile outputFile [commandsFile]" <<
        endl;
        exit(EXIT_FAILURE);
    }

    // Extract filenames
    string stations_file = argv[1];
    string output_file = argv[2];
    
    // Initialize simulation
    MetroSim metrosim;
    metrosim.read_stations(argv[1]); // Populate stations

    // Begin reading commands
    // query(cin, &metrosim);
    
    return 0;
}

void query(istream &input, MetroSim *sim) {
    char q; // Represents the query
    bool quit = false;
    // Continue prompting until the user wants to quit
    while (not quit) {
        cout << "Command? "; // Prompt user
        input >> q; // Read from input stream
        if (q == 'p') { // Respond to the p query
            int depart_num;
            int arrive_num;
            input >> depart_num >> arrive_num;
            handlePassenger(depart_num, arrive_num, sim);
        }
        else if (q == 'm') { // Respond to the m query
            char next_q;
            input >> next_q;
            if (next_q == 'f') {
                cout << "Thanks for playing MetroSim. Have a nice day!" << endl;
                quit = true;
            }
            else if (next_q == 'm') {
                sim->moveTrain();
            }
        }
    }
}

void handlePassenger(int d_num, int a_num, MetroSim *sim) {
    Passenger passenger(0, d_num, a_num);
    sim->addPassenger(passenger);
}
