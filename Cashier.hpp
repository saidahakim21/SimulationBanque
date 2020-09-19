
#ifndef __CASHIER_HPP
#define __CASHIER_HPP

#include <iostream>

#include "Bank.hpp"
#include "Depart.hpp"
#include "Client.hpp"

class Bank;

class Cashier{
protected:
    int number;
    double averageServiceTime;
    Client currentClient;
    bool servingClient;
    int clientNb;
    double occupationTime;

    Bank* bank;
public:
    Cashier();
    explicit Cashier(double, int, Bank*);
    ~Cashier();

    double getAverageServiceTime();
    int getClientNb();
    int getNumber();

    bool isFree();
    void serve(Client);
    void wait();

    double getOccupationRate();
};

#endif
