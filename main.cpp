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
     query(cin, &metrosim);
    
    return 0;
}

/*
 * name:      query
 * purpose:   prompt the user for commands to perform on the MetroSim, excecute
 *            those commands
 * arguments: a reference to the input stream to read commands from and the
 *            address of the MetroSim simulator
 * returns:   none
 * effects:   none
 * other:     none
 */
void query(istream &input, MetroSim *sim) {
    char q; // Represents the query
    bool quit = false;
    // Continue prompting until the user wants to quit
    while (not quit) {
        sim->print(cout);
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


/*
 * name:      handlePassenger
 * purpose:   handle the add passenger query
 * arguments: an integer representing the station the passenger is departing
 *            from, an integer representing the station the passenger is heading
 *            to, and the address of the MetroSim simulator
 * returns:   none
 * effects:   adds a passenger to boarding line at a given station
 * other:     none
 */
void handlePassenger(int d_num, int a_num, MetroSim *sim) {
    sim->addPassenger(d_num, a_num);
}
