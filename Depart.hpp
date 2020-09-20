/******************************
 * created by Yacine ZABAT
 ******************************/
#ifndef __DEPART_H
#define __DEPART_H
#include <iostream>

#include "Simulation.hpp"
#include "Cashier.hpp"
#include "Client.hpp"
#include "Event.hpp"

class Cashier;
class Simulation; 


class Depart: public Event {
protected:
    int number;
    Cashier* cashier;
    Client client;
    Simulation* simulation; 
public:
    explicit Depart(double, Cashier*, int, Client, Simulation*);
    /**
     * processing the event
     */
    void process();
};

#endif //__DEPART_H
