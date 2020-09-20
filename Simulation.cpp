#include "Simulation.hpp"

using namespace std;

Simulation::Simulation(int cashierNb, double averageArrivalTime, double expectedTime, double* averageServiceTimes) :DES(0)
{
    _cashierNb = cashierNb;
    _averageArrivalTime = averageArrivalTime;
    _expectedTime = expectedTime;
    _averageServiceTimes = averageServiceTimes;
    _bank = nullptr; 
}

Simulation::~Simulation() = default;

Bank* Simulation::getBank() {
    return _bank;
}

void Simulation::run(){

    // Init seed for Poisson random generator
    Poisson::init();
    
    // Create bank with parameters
    _bank = new Bank(_expectedTime, _cashierNb, _averageArrivalTime, _averageServiceTimes);

    // Arrrival time calculation 
    double simulationTime =0;
    while(simulationTime <= _expectedTime){

        double arrivalTime = Poisson::next(_averageArrivalTime);
        simulationTime += arrivalTime;  

        if(simulationTime < _expectedTime){
            ClientArrival *ca = new ClientArrival(simulationTime, this);
            addEvent(ca);
        }
    }

    // Traitement of events(arrival)
    for(_eventIterator = _events.begin() ; _eventIterator != _events.end() ; ++_eventIterator) {
        Event *e = *_eventIterator;
        // Change the current time of the simulation to the time of the event
        _time = e->getTime();
        cout << _time << ":  \t";
        // Process event
        e->process();
    }
}
void Simulation::displayStatistics() {

    Cashier* cashiers = _bank->getCashiers(); 

    cout << "=============\nResultats de la simulation:" << endl << endl;

    cout << "PARAMETRES D'ENTREE:" << endl;
    cout << "La simulation a une duree prevue de " << _expectedTime << endl;
    cout << _cashierNb << " caissiers servent les clients en moyenne sur une duree de : [ ";
    for(int i=0 ; i<_cashierNb ; i++) {
        cout << cashiers[i].averageServiceTime() << " ";
    }
    cout << "] (1 valeur pour chaque caissier)" << endl;
    cout << "Les clients arrivent en moyenne toutes les " << _averageArrivalTime << " unites de temps" << endl << endl;

    // Simulation stats
    
    cout << "RESULTATS EN SORTIE:" << endl;
    cout << "La simulation a reellement dure " << _time << endl << endl;
    

    // Cashier stats
    cout << "Les caissiers ont ete occupes [ ";
    for(int i=0 ; i< _cashierNb ; i++) {
        cout << cashiers[i].getOccupationRate(_time)*100 << " ";
    }
    cout << "] % de leur temps" << endl << endl;

    // Client stats
    cout << "[ ";
    for(int i=0 ; i<_cashierNb ; i++) {
        cout << cashiers[i].getClientNb() << " ";
    }
    /*
    cout << "] clients ont ete servis sur la duree totale de la simulation" << endl;
    cout << "Il y a donc eu " << _bank->waitingTimes.size() << " clients servis au total" << endl;

    cout << "Les clients ont attendu en moyenne ";
    double sum = 0;
    for (vector<double>::iterator it = waitingTimes.begin() ; it != waitingTimes.end(); ++it) {
        sum += *it;
    }
    cout << (sum/waitingTimes.size()) << " unites de temps" << endl << endl;
*/
    // Queue stats
    
    cout << "La taille maximale de la file d'attente [ ";
    cout << _bank->getWaitingList()->maxLength() << "] " << endl;
    
    cout << "La longeur maximale de la file d'attente [ ";
    cout << _bank->getWaitingList()->averageLength() << "]" << endl;
    
}
