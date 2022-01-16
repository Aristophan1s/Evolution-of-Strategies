#ifndef ECOSYSTEM_T
#define ECOSYSTEM_T

#include "confront.h"
#include "strategy.h"
#include "iostream"

using namespace std;



class Ecosystem {
    public:
        Ecosystem(int nGen, Strategy *a, Strategy *b, int numOfA, int numOfB);

        Strategy *aORb(float percentageA);
        void run();

    private:
        int numGen, numA, numB;
        Strategy *speciesA, *speciesB;
        
};



#endif