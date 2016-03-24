/*
 * Ships.cpp
 *
 *  Created on: 22 Mar 2016
 *      Author: JonLN64Q
 */

#include "AllShips.h"
#include <string>

using namespace std;

ColonyShips::ColonyShips() :Ships(){
	colonistAmount = 0;
}

ColonyShips::ColonyShips(int typeIndex, int cost, int weight, int energyConsumption, int colonistAmount):Ships(typeIndex,cost,weight,energyConsumption){
	this->colonistAmount = colonistAmount;
}

ColonyShips::~ColonyShips() {}

int ColonyShips::getColonistAmount(){return colonistAmount;}

