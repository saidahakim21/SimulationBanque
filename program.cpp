#include "program.hpp"

using namespace std;

int main() {

    int cashierNb = 3; 
    double* averageServiceTimes = new double[cashierNb];
    setCashierServiceTime(&averageServiceTimes, cashierNb);



    Simulation simulation(cashierNb,30,1000, averageServiceTimes); 
    simulation.run(); 

    simulation.displayStatistics(); 

    return 0;
}

void setCashierServiceTime(double** arr, int arrSize) {
    for(int i=0 ; i<arrSize ; i++) {
        *(*arr+i) = 15;
    }
}
