/*********************************
 *
 * Renaud Déniel
 *
 *********************************/

#ifndef __CASHIER_HPP
#define __CASHIER_HPP

#include <iostream>

#include "Bank.hpp"
#include "CashierRelease.hpp"
#include "Client.hpp"

class Bank;

class Cashier{
protected:
    int _number;
    double _averageServiceTime;
    Client _currentClient;
    bool _servingClient;
    int _clientNb;
    double _occupationTime;

    Bank* _bank;
public:
    Cashier();
    explicit Cashier(double, int, Bank*);
    ~Cashier();

    double averageServiceTime();
    int clientNb();
    int number();

    bool isFree();
    void serve(Client);
    void wait();

    double occupationRate();
};

#endif
