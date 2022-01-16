#include "confront.h"

using namespace std;


Confrontation::Confrontation(Strategy *a, Strategy *b, unsigned nRounds)
{
    outcome1 = 0;
    outcome2 = 0;
    one = a;
    two = b;
    numRounds = nRounds;
    cc = 5;
    dc = 10;
    cd = 0;
    dd = 2;
}

void Confrontation::reset(Strategy *a, Strategy *b, unsigned nRounds)
{
    outcome1 = 0;
    outcome2 = 0;
    one = a;
    two = b;
    numRounds = nRounds;
    histOfOne.clear();
    histOfTwo.clear();
}

void Confrontation::setpayoff(int bothC, int defCoop, int coopDef, int bothD)
{
    cc = bothC;
    dc = defCoop;
    cd = coopDef;
    dd = bothD;
}

void Confrontation::startConfrontation()
{
    unsigned nRounds = this->numRounds;

    int currOut1, currOut2;
    bool currAct1, currAct2;

    for (unsigned i = 0; i < nRounds; i++) {
        currAct1 = one->act(histOfTwo);
        currAct2 = two->act(histOfOne);
        payoff(currAct1, currAct2 , &currOut1, &currOut2);
        histOfOne.push_back(currAct1);
        histOfTwo.push_back(currAct2);
        outcome1 += currOut1;
        outcome2 += currOut2;
    }
    
}

void Confrontation::payoff(bool action1, bool action2 , int *out1, int *out2)
{
    if (action1 && action2) {
        *out1 = cc;
        *out2 = cc;
    } else if (action1 && (!action2)) {
        *out1 = cd;
        *out2 = dc;
    } else if ((!action1) && action2) {
        *out1 = dc;
        *out2 = cd;
    } else {
        *out1 = dd;
        *out2 = dd;
    }
}