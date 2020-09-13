
#include "simulation.hpp"

using namespace std;

int main(int argc,char** argv) {
    // Simulation parameters definitions
    double expectedTime = 1000;
    int cashierNb = 3;
    double averageArrivalTime = 5;
    double* averageServiceTimes = new double[cashierNb];

    // Init seed for Poisson random generator
    Poisson::init();

    // Generate random doubles to set the average service times for each cashier
    initServicesTimes(15, 15, &averageServiceTimes, cashierNb);

    // Create bank with parameters
    Bank bank(0, expectedTime, cashierNb, averageArrivalTime, averageServiceTimes);
    // Start the simulation
    bank.start();

    // Display the stats for the simulation
    bank.displayStats();
}

/* Generate random doubles between min and max in an array */
void initServicesTimes(double** arr, int arrSize,double fMin, double fMax)
{
    for(int i=0 ; i<arrSize ; i++)
    {
        double f = (double)rand() / RAND_MAX;
         *(*arr+i) = fMin + f * (fMax - fMin);
    }
}
