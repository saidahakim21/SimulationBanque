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
Bank::Bank(double eT, int nbCashier, double averageAT, double* averageST){
    expectedTime = eT;
    cashierNb = nbCashier;
    averageArrivalTime = averageAT;

    cashiers = new Cashier[cashierNb];
    waitingList = new WaitingList(this);
    for(int i=0 ; i<cashierNb ; i++) {
        cashiers[i] = Cashier(averageST[i], i);
    }
}

Bank::~Bank() {
    delete [] cashiers;
    delete waitingList;
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

Cashier* Bank::getCashiers() {
    return cashiers;
}

WaitingList* Bank::getWaitingList() {
    return waitingList;
}

void Bank::addWaitingTime(double t) {
    waitingTimes.push_back(t);
}
