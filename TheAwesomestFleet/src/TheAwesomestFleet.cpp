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

	//Creating an object of ColonyShips
	ColonyShips colonyShip1;
	colonyShip1 = ColonyShips(colonyShip1.FERRY);
	printf("The colonyShip1 : \nType : %d\nCost : %d\nWeight : %d\nEnergy Consumption : %d\nColonist Amount : %d\n",
			colonyShip1.getTypeIndex(),
			colonyShip1.getCost(),
			colonyShip1.getWeight(),
			colonyShip1.getEnergyConsumption(),
			colonyShip1.getColonistAmount());


	// Creating an object of SolarSailShips
	SolarSailShips solarSailShip1;
	solarSailShip1 = SolarSailShips(solarSailShip1.RADIANT);
	printf("The Radiant : \nType : %d\nCost : %d\nWeight : %d\nEnergy Consumption : %d\nGeneration Amount : %d\n",
			solarSailShip1.getTypeIndex(),
			solarSailShip1.getCost(),
			solarSailShip1.getWeight(),
			solarSailShip1.getEnergyConsumption(),
			solarSailShip1.getEnergyGeneration());

	// Creating an object of MilataryShips
	MilitaryShips militaryShip1;
	militaryShip1 = MilitaryShips(militaryShip1.DESTROYER);
	printf("The Destroyer : \nType : %d\nCost : %d\nWeight : %d\nEnergy Consumption : %d\nFighers Amount : %d\n",
			militaryShip1.getTypeIndex(),
			militaryShip1.getCost(),
			militaryShip1.getWeight(),
			militaryShip1.getEnergyConsumption(),
			militaryShip1.getNumberFighters());

	// Creating an object of MedicShips
	MedicShips medicShip1;
	medicShip1 = MedicShips(medicShip1.MEDIC);
	printf("The Medic : \nType : %d\nCost : %d\nWeight : %d\nEnergy Consumption : %d\n",
			medicShip1.getTypeIndex(),
			medicShip1.getCost(),
			medicShip1.getWeight(),
			medicShip1.getEnergyConsumption());


	return 0;
}
