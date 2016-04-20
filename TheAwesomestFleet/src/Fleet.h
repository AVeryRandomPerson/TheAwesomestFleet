/*
 * Ships.h
 *
 *  Created on: 22 Mar 2016
 *      Author: JonLN64Q
 */

#ifndef FLEET_H_
#define FLEET_H_

#include <cmath>
#include <map>
#include <string>

using namespace std;

// SHIP TYPE IDs
const int NO_TYPE = -1;
const int COLS_FERRY = 1;
const int COLS_LINER = 2;
const int COLS_CLOUD = 3;
const int SOLSS_RADIANT = 11;
const int SOLSS_EBULIENT = 12;
const int MILES_CRUISER = 21;
const int MILES_FRIGATE = 22;
const int MILES_DESTROYER =23;
const int MEDS_MEDIC = 31;

// SHIP CLASS IDs
const int NO_CLASS = -1;
const int COLS_CLASS = 0;
const int SOLSS_CLASS = 1;
const int MILES_CLASS = 2;
const int MEDS_CLASS =3;

map<int,string> ID_TO_NAME_MAP = {
  {NO_TYPE , "Undefined"},
  {COLS_FERRY , "Ferry"},
  {COLS_LINER , "Liner"},
  {COLS_CLOUD, "Cloud"},
  {SOLSS_RADIANT , "Radiant"},
  {SOLSS_EBULIENT , "Ebulient"},
  { MILES_CRUISER , "Cruiser"},
  {MILES_FRIGATE , "Frigate"},
  {MILES_DESTROYER , "Destroyer"},
  {MEDS_MEDIC , "Medic"}
};



class Ship {
	public:

		Ship(){}
		virtual ~Ship(){}

		// Getters
		bool isAlive(){return this->alive;}
		// #18
		bool isDestroyed(){return !(this->alive);}
		// #21
		bool isInfected(){return this->infected;}
		bool isGuarded(){return this->guarded;}
		bool isImmune(){return this->immune;}

		int getCost(){return this->cost;}
		int getWeight(){return this->weight;}
		int getEnergyConsumption(){return this->energyConsumption;}
		int getTypeID(){return this->typeID;}

		//	#17
		string getTypeName(){return this->typeName;}

		void setAlive(bool flag){ this->alive = flag;}
		void setInfected(bool flag){this->infected =flag;}
		void setGuarded(bool flag){this->guarded =flag;}
		void setImmune(bool flag){this->immune=flag;}
		void setCost(int newCost){this->cost = newCost;}
		void setWeight(int newWeight){this->weight = newWeight;}
		void setEnergyConsumption(int newConsumption){this->cost = newConsumption;}
		void setTypeID(int newTypeID){this->typeID = newTypeID;}
		void setID(int newID){this->ID = newID;}

		void setTypeNameByID(int typeID){this->typeName = ID_TO_NAME_MAP[typeID];}

		int getShipClassIDByTypeID(int typeID){
			// ClassID is taken as the tenth of any given typeID
			return floor(typeID/10);
		}

		void initializeShip(int cost, int weight ,int energyConsumption){
			setAlive(true);
			setInfected(false);
			setGuarded(false);
			setImmune(false);
			setCost(cost);
			setWeight(weight);
			setEnergyConsumption(energyConsumption);
		}

	private:
		int ID = 0;

		bool alive = true;
		bool infected = true;
		bool guarded = false;
		bool immune = false;

		int cost;
		int weight;
		int energyConsumption;
		int typeID;
		string typeName;


};

class ColonyShip : public Ship{
	public :
		ColonyShip(int typeID){
			if(typeID == COLS_FERRY){
				initializeShip(500,10,5);
				setColonistAmount(100);
			}
			else if(typeID == COLS_LINER){
				initializeShip(1000,20,7);
				setColonistAmount(250);
			}
			else if(typeID == COLS_CLOUD){
				initializeShip(2000,30,9);
				setColonistAmount(750);
			}
			else{
				initializeShip(0,0,0);
				setColonistAmount(0);
				setAlive(false);
			}
		}
		virtual ~ColonyShip(){}

		// #19
		int getColonistAmount(){return this->colonistAmount;}
		//#20
		void infect(){setInfected(true);}


	private:
		int colonistAmount;

		void setColonistAmount(int newAmount){this->colonistAmount = newAmount;}

};

class SolarSailShip : public Ship{
	public :
	SolarSailShip(int typeID){
			if(typeID == SOLSS_RADIANT){
				initializeShip(50,3,5);
				setEnergyProduction(50);
			}
			else if(typeID == SOLSS_EBULIENT){
				initializeShip(250,50,5);
				setEnergyProduction(500);
			}
			else{
				initializeShip(0,0,0);
				setEnergyProduction(0);
				setAlive(false);
			}
		}
		virtual ~SolarSailShip(){}

		// #22
		int getEnergyProduction(){return this->energyGenerated;}
		void infect(){setInfected(true);}


	private:
		int energyGenerated;

		void setEnergyProduction(int newEnergyGenerated){this->energyGenerated = newEnergyGenerated;}

};

class MilitaryEscortShip : public Ship{
	public :
	MilitaryEscortShip(int typeID){
			if(typeID == MILES_CRUISER){
				initializeShip(50,3,5);
				setNrFighters(0);
			}
			else if(typeID == MILES_FRIGATE){
				initializeShip(250,50,5);
				setNrFighters(10);
			}
			else if(typeID == MILES_DESTROYER){
				initializeShip(250,50,5);
				setNrFighters(25);
			}
			else{
				initializeShip(0,0,0);
				setAlive(false);
			}
		}
		virtual ~MilitaryEscortShip(){}

		int getNrFighters(){return this->nrFighters;}
		// #23
		int getNrProtected(){return this->nrProtected;}
		void infect(){setInfected(true);}


	private:
		int nrFighters;
		int nrProtected;

		void setNrFighters(int nrFighters){
			this->nrFighters = nrFighters;
			this->nrProtected = floor((this->nrFighters)/2) + 1;
		}

};


class MedicShip : public Ship{
	public :
	MedicShip(int typeID){
			if(typeID == MEDS_MEDIC){
				initializeShip(1000,1,1);
			}
			else{
				initializeShip(0,0,0);
				setAlive(false);
			}
		}
		virtual ~MedicShip(){}

	private:


};

class Fleet{
	public:
		Fleet(){

		}
		virtual ~Fleet(){}

		// #1
		int getWeight(){return this->weight;}
		// #4
		int getCost(){return this->cost;}
		// #2
		int getEnergyConsumption(){return this->energyConsumption;}
		// #5
		int getEnergyProduced(){return this->energyProduced;}
		// #3
		int getColonistAmount(){return this->colonistAmount;}
		// #6
		int countProtectedShips(){
			// Not 100% accurate atm.
			// Needs to return the number of protected ship (Not number of ships that can be protected).
			// * Min between nrProtected and Length(allColonyShips).
			return this->nrProtected;}

		// #7
		bool hasMedic(){
			// return if(size(allMedicShips) > 0);
		}

		string getCorperationName(){return this->corperationName;}

		void setAllColonyShips(ColonyShip *allColonyShips, SolarSailShip *allSolarSailShips, MilitaryEscortShip *allMilitaryEscortShips, MedicShip *allMedicShips){
			this->allColonyShips = allColonyShips;
			this->allSolarSailShips = allSolarSailShips;
			this->allMilitaryEscortShips = allMilitaryEscortShips;
			this->allMedicShips = allMedicShips;
		}

	private:
		ColonyShip *allColonyShips;
		SolarSailShip *allSolarSailShips;
		MilitaryEscortShip *allMilitaryEscortShips;
		MedicShip *allMedicShips;

		int weight;
		int cost;
		int energyConsumption;
		int energyProduced;
		int nrProtected;
		int colonistAmount;

		string corperationName;
};


#endif

