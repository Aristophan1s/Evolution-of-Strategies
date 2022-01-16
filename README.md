# Evolution-Algo

This repository holds my projects related to evolutionary algorithms.

Currently I implemented a program simulating iterative prisoners' dilemma that is similar to the one described in chapter 12 of The Selfish Gene by Richard Dawkins (40th Anniversary Edition). The pay off table for both cooperating is 3; for defecting while the opponent cooperating, 5; for cooperating while the opponent defecting, 0; and for both defecting, 1. The number of iterations is set to 100 rounds. 

The evolutionary part of this program is briefly: 

1. For each strategy, it will be instantiated as a species living in an ecosystem with another competing speices, which is the instatiation of another strategy. (Currently I only implemented the simulation of a 2-species competition)

2. In the beginning, the user will specify the strategies used by the two species and the respective population of the two species. 

3. During each generation, two individuals will be randomly selected from the remaining individuals in the ecosystem. The probability of an individual of Species A being selected is equal to the number of individuals of species A divided by the total population of both species; the same goes for the probability of an individual of Species B being selected. Note: it is important to mention that it is possible and in the some probable that individuals from the same species will be seleted. 

4. The two selected individuals will undergo a confrontation, which is a 100-round iterative prisoners' dilemma. The two individuals will be removed from the total population, while the outcome of their confrontation will be recorded and used to calculate the population of the next generation of the two species. For each generation the total population will be re-adjusted to 500. The user can enter the number of generations of the simulation. 

5. When there's no individuals that have not been selected from the current generation, the program will simulate the next generation according to the accumulated outcome of confrontations. 

Note: I have currently implemented 7 strategies, which are:
(1) All Cooperation, (2) All Defect, (3) Tit for Tat, (4) Tit for two Tats, (5) Grim Trigger, (6) Naive Prober and (7) Random.

Details of the strategies can be found in the following website:
http://www.prisoners-dilemma.com/common-strategy/

Usage: 

use `make` to compile and 
to run the executable, use 
`./evo [Species A type] [numSpeciesA] [Species B type] [numSpecesB] [numGeneration]`

The species types are represented as integers, and the indices for each strategy are (1) All Cooperation, (2) All Defect, (3) Tit for Tat, (4) Tit for two Tats, (5) Grim Trigger, (6) Naive Prober and (7) Random.

For example, 
`./evo 2 111 6 388 100` 
means 111 individuals of Species A which uses the strategy of Tit for Tat are put into the ecosystem with 388 individuals of Species B which uses the random strategy. The simulation will run for 100 generations. 

Please report any bugs to tianze.hua@tufts.edu