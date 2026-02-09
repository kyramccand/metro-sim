/*
 *
 */

#include "MetroSim.h"

using namespace std;

int main(int argc, char *argv[]) {
    
    MetroSim metrosim;
    metrosim.read_stations(argv[1]);
    
    return 0;
}
