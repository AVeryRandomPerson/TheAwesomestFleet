/*
 * Ships.h
 *
 *  Created on: 22 Mar 2016
 *      Author: JonLN64Q
 */

#ifndef SHIPS_H_
#define SHIPS_H_

#include <string>

using namespace std;

class Ships {
public:
	Ships();
	Ships(string name, int cost, int weight, int energy_conspumption);
	string getName();

	int getCost();
	int getWeight();
	int getEnergyConsumption();

	virtual ~Ships();


private:
	string name;
	int cost;
	int weight;
	int energyConsumption;

};

#endif
