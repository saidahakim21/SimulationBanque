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

class Depart: public Event {
protected:
    int number;
    Cashier* _cashier;
    Client _client;
public:
    explicit Depart(double, Cashier*, int, Client, Bank*);
    /**
     * processing the event
     */
    void process();
};

#endif
