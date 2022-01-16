#ifndef STRATEGY_H
#define STRATEGY_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Strategy {
    public:
        Strategy(bool (*func)(vector<bool> opponHist));

        bool act(vector<bool> opponHist);

    private:
        bool (*myStrategy)(vector<bool> opponHist);
};



#endif