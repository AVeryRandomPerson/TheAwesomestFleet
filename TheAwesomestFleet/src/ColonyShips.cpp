/*
 * Ships.cpp
 *
 *  Created on: 22 Mar 2016
 *      Author: JonLN64Q
 */

#include "AllShips.h"
#include <string>
#include <cstdio>

using namespace std;

ColonyShips::ColonyShips() :Ships(){
	colonistAmount = 0;
}

ColonyShips::ColonyShips(int typeIndex){
	setTypeIndex(typeIndex);
	if(typeIndex == FERRY){
		colonistAmount = 100;
		Initialize(500,10,5);
	}
	else if(typeIndex == LINER){
		colonistAmount = 250;
		Initialize(1000,20,7);
	}
	else if(typeIndex == CLOUD){
		colonistAmount = 750;
		Initialize(2000,30,9);
	}
	else{
		printf("Internal Error : Trying to use ColonyShips Class to create object but failed. Wrong typeIndex!");
	}
}

ColonyShips::~ColonyShips() {}

int ColonyShips::getColonistAmount(){return colonistAmount;}

