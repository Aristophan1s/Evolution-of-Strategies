#include <iostream>
#include "strategy.h"
#include "confront.h"
#include "ecosystem.h"
#include <stdlib.h>    
#include <chrono>
#include <random>
#include <stack>
#include <string>

using namespace std;

bool allDefect(vector<bool> opponHist);
bool allCoop(vector<bool> opponHist);
bool titForTat(vector<bool> opponHist);
bool titForTwoTat(vector<bool> opponHist);
bool grim(vector<bool> opponHist);
bool naiveProber(vector<bool> opponHist);
bool random(vector<bool> opponHist);

const string STRATNAMES[7] = {
    "All Cooperation", "All Defect", "Tit for Tat", "Tit for Two Tats", 
    "Grim Trigger", "Naive Prober", "Random"
};

Strategy STRATEGYS[7] = {Strategy(&allCoop), Strategy(&allDefect), 
Strategy(&titForTat), Strategy(&titForTwoTat), Strategy(&grim), 
Strategy(&naiveProber), Strategy(&random)};

int main(int argc, char *argv[]) {

    if (argc != 6) {
        cerr << "Usage: ./evo [Species A type] [numSpeciesA] [Species B type]" 
        << " [numSpecesB] [numGeneration]" << endl;
        exit(EXIT_FAILURE);
    }

    int spAIndex = stoi(argv[1]) , spBIndex = stoi(argv[3]);

    if ((spAIndex < 0 || spAIndex > 6) || (spBIndex < 0 || spBIndex > 6)) {
        cerr << "Species Index is not supported." << endl;
        exit(EXIT_FAILURE);
    }

    if (spAIndex == spBIndex) {
        cerr << "Species A and Species B must use different strategies" << endl;
        exit(EXIT_FAILURE);
    }


    Ecosystem myeco(stoi(argv[5]), &STRATEGYS[spAIndex], &STRATEGYS[spBIndex], 
    stoi(argv[2]), stoi(argv[4]));


    cout << "Species A uses the strategy of " << STRATNAMES[spAIndex] << endl
    << "Species B uses the strategy of " << STRATNAMES[spBIndex] << endl 
    << endl;
    

    myeco.run();

    return 0;
}

bool allDefect(vector<bool> opponHist) {
    (void) opponHist;
    return false;
}

bool titForTat(vector<bool> opponHist) {
    
    if (opponHist.size() == 0) {
        return true;
    } else {
        return opponHist.back();
    }
}

bool titForTwoTat(vector<bool> opponHist)
{
    if (opponHist.size() <= 1) {
        return true;
    } else {
        int sz = opponHist.size();
        stack<int> opponDefects;

        for (int i = 0; i < sz; i++) {
            if (!opponHist[i]) {
                opponDefects.push(i);
            }
        }

        if (opponDefects.size() == 2) {
            opponHist[opponDefects.top()] = true;
            opponDefects.pop();
            opponHist[opponDefects.top()] = true;
            opponDefects.pop();
            return false;
        } else {
            return true;
        }


    }
}

bool grim(vector<bool> opponHist)
{
    int sz = opponHist.size();
    bool rtn = true;

    for (int i = 0; i < sz; i++) {
        if (!opponHist[i]) {
            rtn = false; 
            i = sz;
        }
    }

    return rtn;
}

bool naiveProber(vector<bool> opponHist)
{
    bool normal = titForTat(opponHist);
    if (normal) {
        std::random_device rd;

        std::mt19937::result_type seed = rd() ^ (
                (std::mt19937::result_type)
                std::chrono::duration_cast<std::chrono::seconds>(
                    std::chrono::system_clock::now().time_since_epoch()
                    ).count() +
                (std::mt19937::result_type)
                std::chrono::duration_cast<std::chrono::microseconds>(
                    std::chrono::high_resolution_clock::now().time_since_epoch()
                    ).count() );

        std::mt19937 gen(seed);

        for( unsigned long j = 0; j < 100500; ++j )    
        {
            std::mt19937::result_type n;
            
            while( ( n = gen() ) > std::mt19937::max() -
                                        ( std::mt19937::max() - 5 ) % 100)
            { /* bad value retrieved so get next one */ }

            if (n % 100 < 5) normal = false; // There's a 5 percent probability
                                             // that the naive prober will 
                                             // defect occasionally 
            break;
        
        }



        
    }

    return normal;
}

bool allCoop(vector<bool> opponHist) {
    (void) opponHist;
    return true;
}

bool random(vector<bool> opponHist) {
    (void) opponHist;

    std::random_device rd;

    std::mt19937::result_type seed = rd() ^ (
            (std::mt19937::result_type)
            std::chrono::duration_cast<std::chrono::seconds>(
                std::chrono::system_clock::now().time_since_epoch()
                ).count() +
            (std::mt19937::result_type)
            std::chrono::duration_cast<std::chrono::microseconds>(
                std::chrono::high_resolution_clock::now().time_since_epoch()
                ).count() );

    std::mt19937 gen(seed);

    unsigned int rtnVal = 0;

    for( unsigned long j = 0; j < 100500; ++j )    
    {
        std::mt19937::result_type n;
        
        while( ( n = gen() ) > std::mt19937::max() -
                                    ( std::mt19937::max() - 5 ) % 47)
        { /* bad value retrieved so get next one */ }

        rtnVal = n;
        break;
    }

    return rtnVal % 2;

}

