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
#include "DES.hpp"
#include "WaitingList.hpp"

class Cashier;
class WaitingList;

class Bank: public DES {
protected:
    double _averageArrivalTime;
    double _expectedTime;
    int _cashierNb;

    Cashier* _cashiers;
    WaitingList* _waitingLists;

    // Variable used to get stats about the simulation
    std::vector<double> _waitingTimes;

public:
    Bank(double, double, int, double, double*);
    ~Bank() override;

    void run() override;

    double averageArrivalTime();
    double expectedTime();
    int cashierNb();

    Cashier* freeCashier();
    WaitingList* waitingLists();
    WaitingList* shortestQueue();

    void addWaitingTime(double);
    double realDuration();

    void displayStats();
};

#endif
