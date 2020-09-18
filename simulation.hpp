/*********************************
 *
 * Renaud Déniel et Vincent Monot
 *
 *********************************/

#ifndef __SIMULATION_HPP
#define __SIMULATION_HPP

#include <iostream>
#include <set>
#include <random>

#include "Poisson.h"
#include "Bank.hpp"
#include "Event.hpp"

void genRandomDoubles(double min, double max, double** arr, int arrSize);
void displayStats(Bank);

#endif
