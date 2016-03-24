//============================================================================
// Name        : TheAwesomestFleet.cpp
// Author      : Jon
// Version     :
//============================================================================

#include <iostream>
#include<cstdlib>
#include<cstdio>

#include "AllShips.h"
using namespace std;

int main() {
	printf("This will soon become a simulation program of space racing !\n");

	ColonyShips theColonist;
	theColonist = ColonyShips(1,1,1,1,1);
	printf("The Colonist : \nType : %d\nCost : %d\nWeight : %d\nEnergy Consumption : %d\nColonist Amount : %d",
				theColonist.getTypeIndex(),
				theColonist.getCost(),
				theColonist.getWeight(),
				theColonist.getEnergyConsumption(),
				theColonist.getColonistAmount());


	return 0;
}
