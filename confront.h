#ifndef CONFRONT_H
#define CONFRONT_H

#include "strategy.h"
#include <stdlib.h>    
#include <chrono>
#include <random>

using namespace std;

class Confrontation {
    public:
        int outcome1, outcome2;

        Confrontation(Strategy *one, Strategy *two, unsigned numRounds);

        void setpayoff(int, int, int, int);

        void startConfrontation();

        void reset(Strategy *one, Strategy *two, unsigned numRounds);


    private:
        Strategy *one, *two;
        vector<bool> histOfOne, histOfTwo;
        unsigned numRounds;
        int cc,dc,cd,dd;
        void payoff(bool, bool, int *, int *); 
};





#endif
