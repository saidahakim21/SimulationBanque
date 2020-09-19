#include "program.hpp"

using namespace std;

int main() {

    int cashierNb = 3; 
    double* averageServiceTimes = new double[cashierNb];
    setCashierServiceTime(&averageServiceTimes, 3);


    Simulation simulation(cashierNb,3,200, averageServiceTimes); 
    simulation.run(); 

    return 0;
}

void setCashierServiceTime(double** arr, int arrSize) {
    for(int i=0 ; i<arrSize ; i++) {
        *(*arr+i) = 15;
    }
}


