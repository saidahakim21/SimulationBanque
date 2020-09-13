/*********************************
 *
 * Renaud Déniel et Vincent Monot
 *
 *********************************/

#ifndef __BANK_HPP
#define __BANK_HPP

#include <iostream>
#include <set>
#include <vector>

#include "Cashier.hpp"
#include "ClientArrival.hpp"
#include "SED.hpp"
#include "Queue.hpp"

class Cashier;

class Bank: public SED {
protected:
    double arrivalTimeInterval;
    double expectedTime;
    int cashierNb;

    Cashier* cashiers;
    Queue waitingList;


    // Variable used to get stats about the simulation
    std::vector<double> waitingTimes;

public:
    Bank(double, double, int, double, double*);
    ~Bank() override;

    void start() override;

    double averageArrivalTime();
    double getExpectedTime();
    int getCashierNb();

    Cashier* getAvailableCashier();

    void addWaitingTime(double);
    double realDuration();

    void displayStats();
};

#endif
