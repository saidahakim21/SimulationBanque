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
    double _arrivalTime;
    Bank* _bank;
public:
    explicit Client(double, Bank*);

    double arrivalTime();
};

#endif
