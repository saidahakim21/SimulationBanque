/*********************************
 *
 * Renaud Déniel
 *
 *********************************/

#ifndef __CLIENT_HPP
#define __CLIENT_HPP

class Bank;

class Client {
protected:
    double arrivalTime;
    Bank* bank;
public:
    explicit Client(double, Bank*);

    double arrivalTime();
};

#endif
