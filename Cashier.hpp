#ifndef __CASHIER_HPP
#define __CASHIER_HPP

#include <iostream>

#include "Bank.hpp"
#include "Depart.hpp"
#include "Client.hpp"
#include "Simulation.hpp"

class Simulation; 

class Cashier{
protected:
    int number;
    double averageServiceTime;
    Client currentClient;
    bool servingClient;
    int clientNb;
    double occupationTime;

public:
    Cashier();
    explicit Cashier(double, int);
    ~Cashier();

    double getAverageServiceTime();
    int getClientNb();
    int getNumber();

    bool isFree();
    void serve(Client, Simulation*);
    void wait();

    double getOccupationRate(double simulationDuration);
};

#endif
