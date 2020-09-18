/*********************************
 *
 * Renaud Déniel et Vincent Monot
 *
 *********************************/

#include "simulation.hpp"

using namespace std;

int main() {
    // Simulation parameters definitions
    double expectedTime = 1000;
    int cashierNb = 3;
    double averageArrivalTime = 5;
    double* averageServiceTimes = new double[cashierNb];

    // Init seed for Poisson random generator
    Poisson::init();

    // Generate random doubles to set the average service times for each cashier
    genRandomDoubles(15, 15, &averageServiceTimes, cashierNb);

    // Create bank with parameters
    Bank bank(0, expectedTime, cashierNb, averageArrivalTime, averageServiceTimes);
    // Start the simulation
    bank.run();

    // Display the stats for the simulation
    bank.displayStats();
}

/* Generate random doubles between min and max in an array */
void genRandomDoubles(double min, double max, double** arr, int arrSize) {
    uniform_real_distribution<double> unif(min, max);
    random_device rd;
    default_random_engine re(rd());
    for(int i=0 ; i<arrSize ; i++) {
        *(*arr+i) = unif(re);
    }
}
