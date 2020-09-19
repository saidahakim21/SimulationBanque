
#ifndef __CLIENT_HPP
#define __CLIENT_HPP

class Bank;

/**
 * a class for the bank client.
 */
class Client {
protected:
    double arrivalTime;
    Bank* bank;
public:
    explicit Client(double, Bank*);

    double getArrivalTime();
};

#endif
