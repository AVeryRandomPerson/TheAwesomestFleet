/*
 * Ships.cpp
 *
 *  Created on: 22 Mar 2016
 *      Author: JonLN64Q
 */

#include "Ships.h"
#include <string>

using namespace std;

Ships::Ships() {}
Ships::~Ships() {}

Ships::Ships(string name, int cost, int weight, int energyConsumption){
	this->name = name;
	this->cost = cost;
	this->weight = weight;
	this->energyConsumption = energyConsumption;
}

string Ships::getName(){	return name;}
int Ships::getCost(){	return cost;}
int Ships::getWeight(){	return weight;}
int Ships::getEnergyConsumption(){	return energyConsumption;}

