/*
 * Ships.cpp
 *
 *  Created on: 22 Mar 2016
 *      Author: JonLN64Q
 */

#include "AllShips.h"
#include <string>

using namespace std;

SolarSailShips::SolarSailShips() :Ships(){
	energyGeneration = 0;
}

SolarSailShips::SolarSailShips(int typeIndex){
	setTypeIndex(typeIndex);
	if(typeIndex == RADIANT){
		energyGeneration = 50;
		Initialize(50,3,5);
	}
	else if(typeIndex == EBULIENT){
		energyGeneration = 250;
		Initialize(250,50,5);
	}
	else{
		printf("Internal Error : Trying to use SolarSailShips Class to create object but failed. Wrong typeIndex!");
	}
}

SolarSailShips::~SolarSailShips() {}


int SolarSailShips::getEnergyGeneration(){return energyGeneration;}

