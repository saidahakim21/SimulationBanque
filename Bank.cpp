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

    cashiers = new Cashier[this->cashierNb];
    waitingList = new WaitingList(this);
    for(int i=0 ; i<this->cashierNb ; i++) {
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
    return this->averageArrivalTime;
}

double Bank::getExpectedTime() {
    return this->expectedTime;
}

int Bank::getCashierNb() {
    return this->cashierNb;
}

Cashier* Bank::freeCashier() {
    // Iterate through the cashiers, if one is free, return it
    for(int i=0 ; i < this->cashierNb ; i++) {
        if(this->cashiers[i].isFree()) {
            return &(this->cashiers[i]);
        }
    }

    return nullptr;
}

WaitingList* Bank::getWaitingList() {
    return this->waitingList;
}

void Bank::addWaitingTime(double t) {
    this->waitingTimes.push_back(t);
}

double Bank::realDuration() {
    return _time;
}

void Bank::displayStats() {
    cout << "=============\nResultats de la simulation:" << endl << endl;

    cout << "PARAMETRES D'ENTREE:" << endl;
    cout << "La simulation a une duree prevue de " << this->expectedTime << endl;
    cout << this->cashierNb << " caissiers servent les clients en moyenne sur une duree de : [ ";
    for(int i=0 ; i<this->cashierNb ; i++) {
        cout << this->cashiers[i].getAverageServiceTime() << " ";
    }
    cout << "] (1 valeur pour chaque caissier)" << endl;
    cout << "Les clients arrivent en moyenne toutes les " << this->averageArrivalTime << " unites de temps" << endl << endl;

    // Simulation stats
    cout << "RESULTATS EN SORTIE:" << endl;
    cout << "La simulation a reellement dure " << _time << endl << endl;

    // Cashier stats
    cout << "Les caissiers ont ete occupes [ ";
    for(int i=0 ; i<this->cashierNb ; i++) {
        cout << this->cashiers[i].getOccupationRate()*100 << " ";
    }
    cout << "] % de leur temps" << endl << endl;

    // Client stats
    cout << "[ ";
    for(int i=0 ; i<this->cashierNb ; i++) {
        cout << this->cashiers[i].getClientNb() << " ";
    }
    cout << "] clients ont ete servis sur la duree totale de la simulation" << endl;
    cout << "Il y a donc eu " << this->waitingTimes.size() << " clients servis au total" << endl;

    cout << "Les clients ont attendu en moyenne ";
    double sum = 0;
    for (vector<double>::iterator it = this->waitingTimes.begin() ; it != this->waitingTimes.end(); ++it) {
        sum += *it;
    }
    cout << (sum/this->waitingTimes.size()) << " unites de temps" << endl << endl;

    // Queue stats
    
    cout << "La taille maximale de la file d'attente [ ";
    cout << getWaitingList()->maxLength() << "] " << endl;
    
    cout << "La longeur maximale de la file d'attente [ ";
    cout << getWaitingList()->averageLength() << "]" << endl;
}
