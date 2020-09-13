
#include "Bank.hpp"
#include "Queue.hpp"


/* Constructor for Bank, with all simulation parameters */
Bank::Bank(double start, double expectedTime, int cashierNb, double averageArrivalTime, double* averageServiceTimes)
    : SED(start)
{
    // Init attributes
    expectedTime = expectedTime;
    cashierNb = cashierNb;
    arrivalTimeInterval = averageArrivalTime;

    // Create cashiers and waiting lines
    cashiers = new Cashier[cashierNb];
    waitingList = Queue(this);

    for(int i=0 ; i<cashierNb ; i++)
    {
        cashiers[i] = Cashier(averageServiceTimes[i], i, this);
    }

    // Create first arrival event
    ClientArrival *ca = new ClientArrival(0.11111, this);
    addEvent(ca);
}

Bank::~Bank()
{
    delete [] cashiers;
}

void Bank::start()
{
    // For each event
    while (eventsList != NULL)
    {
        Event *e = eventsList->event;
        // Change the current time of the simulation to the time of the event
        time = e->getTime();
        cout << time << ":  \t";
        // Process event
        e->process();
        eventsList = eventsList->next;
    }
}

/* Returns the average arrival time */
double Bank::averageArrivalTime() {
    return arrivalTimeInterval;
}

/* Returns the expected time of the simulation */
double Bank::getExpectedTime() {
    return expectedTime;
}

/* Returns the number of cashiers in the bank */
int Bank::getCashierNb() {
    return cashierNb;
}

/* Returns a pointer to the first cashier waiting to serve clients (from 0 to n)
If there isn't any free Cashier, returns 0
*/
Cashier* Bank::getAvailableCashier() {
    // Iterate through the cashiers, if one is free, return it
    for(int i=0 ; i < cashierNb ; i++) {
        if(cashiers[i].isFree()) {
            return &(cashiers[i]);
        }
    }

    return nullptr;
}

void Bank::addWaitingTime(double t) {
    waitingTimes.push_back(t);
}

/* Returns the real duration of the simuation */
double Bank::realDuration() {
    return time;
}

void Bank::displayStats() {
    /*cout << "=============\nResultats de la simulation:" << endl << endl;

    cout << "PARAMETRES D'ENTREE:" << endl;
    cout << "La simulation a une duree prevue de " << expectedTime << endl;
    cout << cashierNb << " caissiers servent les clients en moyenne sur une duree de : [ ";
    for(int i=0 ; i<cashierNb ; i++) {
        cout << cashiers[i].averageServiceTime() << " ";
    }
    cout << "] (1 valeur pour chaque caissier)" << endl;
    cout << "Les clients arrivent en moyenne toutes les " << arrivalTimeInterval << " unites de temps" << endl << endl;

    // Simulation stats
    cout << "RESULTATS EN SORTIE:" << endl;
    cout << "La simulation a reellement dure " << time << endl << endl;

    // Cashier stats
    cout << "Les caissiers ont ete occupes [ ";
    for(int i=0 ; i<cashierNb ; i++) {
        cout << cashiers[i].occupationRate()*100 << " ";
    }
    cout << "] % de leur temps" << endl << endl;

    // Client stats
    cout << "[ ";
    for(int i=0 ; i<cashierNb ; i++) {
        cout << cashiers[i].clientNb() << " ";
    }
    cout << "] clients ont ete servis sur la duree totale de la simulation" << endl;
    cout << "Il y a donc eu " << waitingTimes.size() << " clients servis au total" << endl;

    cout << "Les clients ont attendu en moyenne ";
    double sum = 0;
    for (vector<double>::iterator it = waitingTimes.begin() ; it != waitingTimes.end(); ++it) {
        sum += *it;
    }
    cout << (sum/waitingTimes.size()) << " unites de temps" << endl << endl;

    cout << "] clients" << endl;
    cout << "Soit un moyenne de " << (sum/cashierNb) << " clients, toutes files confondues" << endl;*/
}
