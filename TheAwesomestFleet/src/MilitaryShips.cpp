/*
 * Ships.cpp
 *
 *  Created on: 22 Mar 2016
 *      Author: JonLN64Q
 */

#include "AllShips.h"
#include <string>

using namespace std;

MilitaryShips::MilitaryShips() :Ships(){
	numberFighters = 0;
}

MilitaryShips::MilitaryShips(int typeIndex){
	setTypeIndex(typeIndex);
	if(typeIndex == CRUISER){
		numberFighters = 0;
		Initialize(300,2,10);
	}
	else if(typeIndex == FRIGATE){
		numberFighters = 10;
		Initialize(1000,7,20);
	}
	else if(typeIndex == DESTROYER){
		numberFighters = 25;
		Initialize(2000,19,30);
	}
	else{
		printf("Internal Error : Trying to use MilitaryShips Class to create object but failed. Wrong typeIndex!");
	}
}

MilitaryShips::~MilitaryShips() {}


int MilitaryShips::getNumberFighters(){return numberFighters;}

