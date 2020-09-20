#include "Simulation.hpp"

using namespace std;

/**
 * Constructor for Simulation class
 * @param nbCashiers number of cashier in the bank
 * @param averageAT average time till next client arrival
 * @param expectedT estimated time for the simulation duration
 * @param averageST average time of service per Client
 */
Simulation::Simulation(int nbCashiers, double averageAT, double expectedT, double* averageST) :SED(0)
{
    cashierNb = nbCashiers;
    averageArrivalTime = averageAT;
    expectedTime = expectedT;
    averageServiceTimes = averageST;
    bank = nullptr;
}

Simulation::~Simulation() = default;

Bank* Simulation::getBank() {
    return bank;
}

void Simulation::run(){

    // Init seed for Poisson random generator
    Poisson::init();
    
    // Create bank with parameters
    bank = new Bank(expectedTime, cashierNb, averageArrivalTime, averageServiceTimes);

    // Arrrival time calculation 
    double simulationTime =0;
    while(simulationTime <= expectedTime){

        double arrivalTime = Poisson::next(averageArrivalTime);
        simulationTime += arrivalTime;  

        if(simulationTime < expectedTime){
            Arrival *ca = new Arrival(simulationTime, this);
            addEvent(ca);
        }
    }

    // Traitement of events(arrival)
    for(eventIterator = events.begin() ; eventIterator != events.end() ; ++eventIterator) {
        Event *e = *eventIterator;
        // Change the current time of the simulation to the time of the event
        time = e->getTime();
        cout << time << ":  \t";
        // Process event
        e->process();
    }
}
void Simulation::displayStatistics() {

    Cashier* cashiers = bank->getCashiers();

    cout << "*******************\nSimulation Results: *********" << endl << endl;

    cout << "INPUTS :" << endl;
    cout << "The simulation is expected to take : " << expectedTime << endl;
    cout << cashierNb << " The average Cashiers service time is : [ ";
    for(int i=0 ; i<cashierNb ; i++) {
        cout << cashiers[i].getAverageServiceTime() << " ";
    }
    cout << "] (1 Value per Cashier)" << endl;
    cout << "The average time between each two client arrival is : " << averageArrivalTime << " unites de temps" << endl << endl;

    // Simulation stats
    
    cout << "OUTPUTS : " << endl;
    cout << "The simulation has actually took :" << time << endl << endl;
    

    // Cashier stats
    cout << "Cashiers have been occupied for  [ ";
    for(int i=0 ; i< cashierNb ; i++) {
        cout << cashiers[i].getOccupationRate(time)*100 << " ";
    }
    cout << "] % of theire time (1 Value by Cashier)" << endl << endl;

    // Client stats
    cout << "[ ";
    for(int i=0 ; i<cashierNb ; i++) {
        cout << cashiers[i].getClientNb() << " ";
    }

    cout << "] clients have been served during the simulation << endl;
    cout << "Wich make " << bank->waitingTimes.size() << " clients served in total" << endl;

    cout << "The average waiting time for clients :  ";
    double sum = 0;
    for (vector<double>::iterator it = waitingTimes.begin() ; it != waitingTimes.end(); ++it) {
        sum += *it;
    }
    cout << (sum/waitingTimes.size()) << " unites de temps" << endl << endl;
*/
    // Queue stats
    
    cout << "The Maximum Queue line size is : [ ";
    cout << bank->getQueue()->maxLength() << "] " << endl;
    
    cout << "The average Queue line size is : [ ";
    cout << bank->getQueue()->averageLength() << "]" << endl;
    
}
