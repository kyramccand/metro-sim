/*
 *
 */

#include "MetroSim.h"

using namespace std;

void query(istream &input, MetroSim *sim);

int main(int argc, char *argv[]) {

    if (argc < 3) {
        cout << "Usage: ./MetroSim stationsFile outputFile [commandsFile]" <<
        endl;
        exit(EXIT_FAILURE);
    }

    string stations_file = argv[1];
    string output_file = argv[2];
    
    MetroSim metrosim;
    metrosim.read_stations(argv[1]);
    // metrosim.print(cout);
    query(cin, &metrosim);
    
    return 0;
}

void query(istream &input, MetroSim *sim) {
    char q;
    bool quit = false;
    while (not quit) {
        cout << "Command? ";
        input >> q;
        if (q == 'p') {
            int depart_num;
            int arrive_num;
            input >> depart_num >> arrive_num;
        }
        else if (q == 'm') {
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
