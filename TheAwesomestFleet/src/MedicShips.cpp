/*
 * Ships.cpp
 *
 *  Created on: 22 Mar 2016
 *      Author: JonLN64Q
 */

#include "AllShips.h"
#include <string>

using namespace std;

MedicShips::MedicShips() :Ships(){}

MedicShips::MedicShips(int typeIndex){
	setTypeIndex(typeIndex);
	if(typeIndex == MEDIC){
		Initialize(1000,1,1);
	}
	else{
		printf("Internal Error : Trying to use MedicShips Class to create object but failed. Wrong typeIndex!");
	}
}

MedicShips::~MedicShips() {}
