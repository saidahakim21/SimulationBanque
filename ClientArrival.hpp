/*********************************
 *
 * Vincent Monot
 *
 *********************************/

#ifndef __CLIENT_ARRIVAL_HPP
#define __CLIENT_ARRIVAL_HPP

#include <iostream>

#include "Poisson.h"
#include "Bank.hpp"
#include "Client.hpp"
#include "Event.hpp"

class ClientArrival: public Event {
public:
    explicit ClientArrival(double, Bank*);
    void process() override;
};

#endif
