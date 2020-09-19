#include "Bank.hpp"

using namespace std;

/**
 * Constructor for Bank class
 * @param start starting time of the simulaiton
 * @param eT estimated time for the simulation duration
 * @param nbCashier number of cashier in the bank
 * @param averageAT average time till next client arrival
 * @param averageST average time of service per Client
 */
Bank::Bank(double start, double eT, int nbCashier, double averageAT, double* averageST)
    : DES(start) {
    expectedTime = eT;
    cashierNb = nbCashier;
    averageArrivalTime = averageAT;

    cashiers = new Cashier[cashierNb];
    waitingList = new WaitingList(this);
    for(int i=0 ; i<cashierNb ; i++) {
        cashiers[i] = Cashier(averageST[i], i, this);
    }

    ClientArrival *ca = new ClientArrival(0.11111, this);
    addEvent(ca);
}

Bank::~Bank() {
    delete [] cashiers;
    delete waitingList;
}

void Bank::run() {
    // iterate over generated Events using poisson suite
    for(_eventIterator = _events.begin() ; _eventIterator != _events.end() ; ++_eventIterator) {
        Event *e = *_eventIterator;
        // increment time
        _time = e->getTime();
        cout << _time << ":  \t";
        // process the event
        e->process();
    }
}

double Bank::getAverageArrivalTime() {
    return averageArrivalTime;
}

double Bank::getExpectedTime() {
    return expectedTime;
}

int Bank::getCashierNb() {
    return cashierNb;
}

Cashier* Bank::freeCashier() {
    // Iterate through the cashiers, if one is free, return it
    for(int i=0 ; i < cashierNb ; i++) {
        if(cashiers[i].isFree()) {
            return &(cashiers[i]);
        }
    }

    return nullptr;
}

WaitingList* Bank::getWaitingList() {
    return waitingList;
}

void Bank::addWaitingTime(double t) {
    waitingTimes.push_back(t);
}

double Bank::realDuration() {
    return _time;
}

void Bank::displayStats() {
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
    cout << "La simulation a reellement dure " << _time << endl << endl;

    // Cashier stats
    cout << "Les caissiers ont ete occupes [ ";
    for(int i=0 ; i<cashierNb ; i++) {
        cout << cashiers[i].getOccupationRate()*100 << " ";
    }
    cout << "] % de leur temps" << endl << endl;

    // Client stats
    cout << "[ ";
    for(int i=0 ; i<cashierNb ; i++) {
        cout << cashiers[i].getClientNb() << " ";
    }
    cout << "] clients ont ete servis sur la duree totale de la simulation" << endl;
    cout << "Il y a donc eu " << waitingTimes.size() << " clients servis au total" << endl;

    cout << "Les clients ont attendu en moyenne ";
    double sum = 0;
    for (vector<double>::iterator it = waitingTimes.begin() ; it != waitingTimes.end(); ++it) {
        sum += *it;
    }
    cout << (sum/waitingTimes.size()) << " unites de temps" << endl << endl;

    // Queue stats
    
    cout << "La taille maximale de la file d'attente [ ";
    cout << getWaitingList()->maxLength() << "] " << endl;
    
    cout << "La longeur maximale de la file d'attente [ ";
    cout << getWaitingList()->averageLength() << "]" << endl;
}
