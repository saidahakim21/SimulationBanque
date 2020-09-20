/******************************
 * created by Yacine ZABAT
 ******************************/

#include "Depart.hpp"

using namespace std;

/**
 * Constructor with parameters:
 * @param time     time of the event
 * @param ca pointer to Cashier that released the client
 * @param cl Client object
 * @param sim Simulation object
 */
Depart::Depart(double time, Cashier* ca, int n, Client cl, Simulation* sim): Event(time), cashier(ca), client(cl) {
    number = n;
    simulation = sim;
}

void Depart::process() {
    Bank* bank =  simulation->getBank();
    if(bank->getQueue()[number].size()>0) {
        cout << "Cashier " << cashier->getNumber() << " serves next client" << endl;
        // pop the first client from waiting list
        Client c = bank->getQueue()[number].removeFirst();
        //for the stats
        bank->addWaitingTime(simulation->getTime() - c.getArrivalTime());

        // serving the client
        cashier->serve(c, simulation);

    }
        // otherwise, cashier waits for a new client
    else {
        cout << "Cashier " << cashier->getNumber() << " waits" << endl;
        cashier->wait();
    }
    
}