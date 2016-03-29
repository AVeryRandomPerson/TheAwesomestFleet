/*
 * Ships.cpp
 *
 *  Created on: 22 Mar 2016
 *      Author: JonLN64Q
 */

#include "AllShips.h"
#include <string>

using namespace std;

Ships::Ships() {
	this->typeIndex = -1;
	this->cost = 0;
	this->weight = 0;
	this->energyConsumption = 0;
}

Ships::Ships(int cost, int weight, int energyConsumption){
	this->cost = cost;
	this->weight = weight;
	this->energyConsumption = energyConsumption;
}

Ships::~Ships() {}

int Ships::getTypeIndex(){	return typeIndex;}
int Ships::getCost(){	return cost;}
int Ships::getWeight(){	return weight;}
int Ships::getEnergyConsumption(){	return energyConsumption;}

void Ships::setTypeIndex(int typeIndex){this->typeIndex = typeIndex;}
void Ships::setCost(int cost){this->cost = cost;}
void Ships::setWeight(int weight){this->weight = weight;}
void Ships::setEnergyConsumption(int energyConsumption){this->energyConsumption = energyConsumption;}

void Ships::Initialize(int cost, int weight, int energyConsumption){
	setCost(cost);
	setWeight(weight);
	setEnergyConsumption(energyConsumption);
}
