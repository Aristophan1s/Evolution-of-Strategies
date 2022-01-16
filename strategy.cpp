#include "strategy.h"

using namespace std;


Strategy::Strategy(bool (*func)(vector<bool> opponHist)) 
{
    myStrategy = func;
}

bool Strategy::act(vector<bool> opponHist) 
{
    return this->myStrategy(opponHist);
}