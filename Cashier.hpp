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
    int _number;
    double _averageServiceTime;
    Client _currentClient;
    bool _servingClient;
    int _clientNb;
    double _occupationTime;

public:
    Cashier();
    explicit Cashier(double, int);
    ~Cashier();

    double averageServiceTime();
    int getClientNb();
    int getNumber();

    bool isFree();
    void serve(Client, Simulation*);
    void wait();

    double getOccupationRate(double simulationDuration);
};

#endif
