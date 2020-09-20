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

    cout << "=============\nResultats de la simulation:" << endl << endl;

    cout << "PARAMETRES D'ENTREE:" << endl;
    cout << "La simulation a une duree prevue de " << expectedTime << endl;
    cout << cashierNb << " caissiers servent les clients en moyenne sur une duree de : [ ";
    for(int i=0 ; i<cashierNb ; i++) {
        cout << cashiers[i].getAverageServiceTime() << " ";
    }
    cout << "] (1 valeur pour chaque caissier)" << endl;
    cout << "Les clients arrivent en moyenne toutes les " << averageArrivalTime << " unites de temps" << endl << endl;

    // Simulation stats
    
    cout << "RESULTATS EN SORTIE:" << endl;
    cout << "La simulation a reellement dure " << time << endl << endl;
    

    // Cashier stats
    cout << "Les caissiers ont ete occupes [ ";
    for(int i=0 ; i< cashierNb ; i++) {
        cout << cashiers[i].getOccupationRate(time)*100 << " ";
    }
    cout << "] % de leur temps" << endl << endl;

    // Client stats
    cout << "[ ";
    for(int i=0 ; i<cashierNb ; i++) {
        cout << cashiers[i].getClientNb() << " ";
    }
    
    cout << "] clients ont ete servis sur la duree totale de la simulation" << endl;
    cout << "Il y a donc eu " << bank->getWaitingTime().size() << " clients servis au total" << endl;

    cout << "Les clients ont attendu en moyenne ";
    double sum = 0;
    for (vector<double>::iterator it = bank->getWaitingTime().begin() ; it != bank->getWaitingTime().end(); ++it) {
        sum += *it;
    }
    cout << (sum/bank->getWaitingTime().size()) << " unites de temps" << endl << endl;

    // Queue stats
    
    cout << "La taille maximale de la file d'attente [ ";
    cout << bank->getQueue()->maxLength() << "] " << endl;
    
    cout << "La longeur maximale de la file d'attente [ ";
    cout << bank->getQueue()->averageLength() << "]" << endl;
    
}
