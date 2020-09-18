/*********************************
 *
 * Vincent Monot
 *
 *********************************/

#ifndef __CASHIER_RELEASE_HPP
#define __CASHIER_RELEASE_HPP

#include <iostream>

#include "Bank.hpp"
#include "Cashier.hpp"
#include "Client.hpp"
#include "Event.hpp"

class Cashier;

class CashierRelease: public Event {
protected:
    int _number;
    Cashier* _cashier;
    Client _client;
public:
    explicit CashierRelease(double, Cashier*, int, Client, Bank*);
    void process();
};

#endif
