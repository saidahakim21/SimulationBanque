#ifndef __DEPART_H
#define __DEPART_H
#include <iostream>

#include "Bank.hpp"
#include "Cashier.hpp"
#include "Client.hpp"
#include "Event.hpp"

class Cashier;

/**
 * a class of a client depart event, extends Event
 */
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

#endif //__DEPART_H
