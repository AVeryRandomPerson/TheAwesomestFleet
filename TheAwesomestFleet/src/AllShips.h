/*
 * Ships.h
 *
 *  Created on: 22 Mar 2016
 *      Author: JonLN64Q
 */

#ifndef ALLSHIPS_H_
#define ALLSHIPS_H_

#include <string>
#include <cstdio>

using namespace std;

class Ships {
	public:
		Ships();
		Ships(int cost, int weight, int energy_conspumption);

		int getTypeIndex();
		int getCost();
		int getWeight();
		int getEnergyConsumption();

		void setTypeIndex(int typeIndex);
		void setCost(int cost);
		void setWeight(int weight);
		void setEnergyConsumption(int energyConsumption);

		void Initialize(int cost, int weight, int energyConsumption);

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
		static const int FERRY=1;
		static const int LINER=2;
		static const int CLOUD=3;
		ColonyShips();
		ColonyShips(int typeIndex);

		int getColonistAmount();

		virtual ~ColonyShips();

	private:
		int colonistAmount;
};

class SolarSailShips : public Ships{
	public:
		static const int RADIANT=1;
		static const int EBULIENT=2;
		SolarSailShips();
		SolarSailShips(int typeIndex);

		int getEnergyGeneration();

		virtual ~SolarSailShips();

	private:
		int energyGeneration;
};

class MilitaryShips : public Ships{
	public:
		static const int CRUISER=1;
		static const int FRIGATE=2;
		static const int DESTROYER=3;

		MilitaryShips();
		MilitaryShips(int typeIndex);

		int getNumberFighters();

		virtual ~MilitaryShips();

	private:
		int numberFighters;
};

class MedicShips : public Ships{
	public:
		static const int MEDIC=1;

		MedicShips();
		MedicShips(int typeIndex);

		virtual ~MedicShips();

};


#endif
