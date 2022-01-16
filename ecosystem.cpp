#include "ecosystem.h"

using namespace std;

bool isSpeciesA(float percentageA);

Ecosystem::Ecosystem(int nGen, Strategy *a, Strategy *b, int numOfA, int numOfB)
{
    speciesA = a;
    speciesB = b;
    numGen = nGen;
    numA = numOfA;
    numB = numOfB;
}

void Ecosystem::run()
{
    int itn = numGen, numRounds = 100;

    Confrontation currCon(speciesA, speciesB, numRounds);

    cout << "Generation 0: " << endl << "Species A: " << numA 
            << "  Species B: " << numB << endl << endl; 


    while(itn > 0) {
        int numAnew = 0, numBnew = 0, currGenA = numA, currGenB = numB;
        int totalP = currGenA + currGenB;



        while(totalP > 1) {
            Strategy *candidate1 = aORb(100. * ((float)currGenA / (float)totalP));
            totalP--;
            if (candidate1 == speciesA) {
                currGenA--;
            } else {
                currGenB--;
            }
            Strategy *candidate2 = aORb(100. * ((float)currGenA / (float)totalP));
            totalP--;
            if (candidate2 == speciesA) {
                currGenA--;
            } else {
                currGenB--;
            }

            currCon.reset(candidate1, candidate2, numRounds);
            currCon.startConfrontation();


            if (candidate1 == speciesA) {
                numAnew += currCon.outcome1;
            } else {
                numBnew += currCon.outcome1;
            }
            if (candidate2 == speciesA) {
                numAnew += currCon.outcome2;
            } else {
                numBnew += currCon.outcome2;
            }
 
            
        }

        totalP = numAnew + numBnew;
        numA = numAnew * 500 / totalP;
        numB = numBnew * 500 / totalP;



        cout << "Generation " << (numGen - itn + 1) << ": " 
        << endl << "Species A: " << numA << "  Species B: " << numB 
        << endl << endl; 

        
        if (numA == 0) {
            cout << "Species A went extinct" << endl;
            cout << "Simulation suspended." << endl << endl;
            itn = 0;
        } else if (numB == 0) {
            cout << "Species B went extinct" << endl;
            cout << "Simulation suspended." << endl << endl;
            itn = 0;
        } else {
            itn--;
        }
    }
}

Strategy *Ecosystem::aORb(float percentageA)
{
    bool isA = isSpeciesA(percentageA);

    if (isA) {
        return speciesA;
    } else {
        return speciesB;
    }

}

bool isSpeciesA(float percentageA)
{
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
                                    ( std::mt19937::max() - 5 ) % 100)
        { /* bad value retrieved so get next one */ }

        rtnVal = n % 100;
        break;
    
    }



    return ( (float) rtnVal < percentageA);
}

