/******************************
 * created by Abdelhakim SAID
 ******************************/

#ifndef __CLIENT_HPP
#define __CLIENT_HPP

class Bank;

/**
 * a class for the bank client.
 */
class Client {
protected:
    double arrivalTime;
public:
    explicit Client(double);
    double getArrivalTime();
};

#endif
