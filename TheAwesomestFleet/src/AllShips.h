/*
 * Ships.h
 *
 *  Created on: 22 Mar 2016
 *      Author: JonLN64Q
 */

#ifndef ALLSHIPS_H_
#define ALLSHIPS_H_

#include <string>

using namespace std;

class Ships {
	public:
		Ships();
		Ships(int typeIndex, int cost, int weight, int energy_conspumption);

		int getTypeIndex();
		int getCost();
		int getWeight();
		int getEnergyConsumption();

		virtual ~Ships();


	private:
		int typeIndex;
		int cost;
		int weight;
		int energyConsumption;
		string name;

};

class ColonyShips : public Ships{
	public:
		ColonyShips();
		ColonyShips(int typeIndex, int cost, int weight, int energy_conspumption, int colonistAmount);

		int getColonistAmount();

		virtual ~ColonyShips();

	private:
		int colonistAmount;
};




#endif
