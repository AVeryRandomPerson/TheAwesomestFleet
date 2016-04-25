/*
 * Ships.h
 *
 *  Created on: 22 Mar 2016
 *      Author: JonLN64Q
 */

#ifndef FLEET_H_
#define FLEET_H_

#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iterator>
#include <map>
#include <string>
#include <vector>

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

static int shipIDSeed = 0;

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

map<string,int> NAME_TO_ID_MAP = {
  {"Undefined",NO_TYPE },
  {"Ferry",COLS_FERRY},
  {"Liner",COLS_LINER},
  {"Cloud",COLS_CLOUD},
  {"Radiant",SOLSS_RADIANT},
  {"Ebulient",SOLSS_EBULIENT},
  {"Cruiser",MILES_CRUISER},
  {"Frigate",MILES_FRIGATE},
  {"Destroyer",MILES_DESTROYER},
  {"Medic",MEDS_MEDIC}
};

map<string,int> NAME_TO_CLASS_MAP = {
  {"Undefined",NO_CLASS},
  {"Ferry",COLS_CLASS},
  {"Liner",COLS_CLASS},
  {"Cloud",COLS_CLASS},
  {"Radiant",SOLSS_CLASS},
  {"Ebulient",SOLSS_CLASS},
  { "Cruiser",MILES_CLASS},
  {"Frigate",MILES_CLASS},
  {"Destroyer",MILES_CLASS},
  {"Medic",MEDS_CLASS}
};


class Ship {
	public:
		Ship(int typeID){
			setID();
			setTypeID(typeID);
			setTypeNameByID(typeID);
		}
		virtual ~Ship(){}

		// Getters
		bool isAlive(){return this->alive;}
		// #18
		bool isDestroyed(){return !(this->alive);}
		// #21
		bool isInfected(){return this->infected;}
		bool isGuarded(){return this->guarded;}

		// #16
		int getCost(){return this->cost;}
		// #15
		int getWeight(){return this->weight;}
		// #14
		int getEnergyConsumption(){return this->energyConsumption;}
		int getTypeID(){return this->typeID;}
		int getID(){return this->ID;}

		//	#17
		string getTypeName(){return this->typeName;}

		void setAlive(bool flag){ this->alive = flag;}
		void setInfected(bool flag){this->infected =flag;}
		void setGuarded(bool flag){this->guarded =flag;}
		void setCost(int newCost){this->cost = newCost;}
		void setWeight(int newWeight){this->weight = newWeight;}
		void setEnergyConsumption(int newConsumption){this->energyConsumption = newConsumption;}
		void setTypeID(int newTypeID){this->typeID = newTypeID;}
		void setID(){
			// New ID is given to the ship as defined is this function.
			shipIDSeed++;
			this->ID = shipIDSeed;
		}

		void setTypeNameByID(int typeID){this->typeName = ID_TO_NAME_MAP[typeID];}

		int getShipClassIDByTypeID(int typeID){
			// ClassID is taken as the tenth of any given typeID
			return floor(typeID/10);
		}

		void initializeShip(int cost, int weight ,int energyConsumption){
			setAlive(true);
			setInfected(false);
			setGuarded(false);
			setCost(cost);
			setWeight(weight);
			setEnergyConsumption(energyConsumption);
		}

	private:
		int ID = 0;

		bool alive = true;
		bool infected = true;
		bool guarded = false;

		int cost;
		int weight;
		int energyConsumption;
		int typeID;
		string typeName;


};

class ColonyShip : public Ship{
	public :
		ColonyShip(int typeID)
		: Ship(typeID)
		{
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
		SolarSailShip(int typeID)
		: Ship(typeID)
		{
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
		MilitaryEscortShip(int typeID)
		: Ship(typeID)
		{
			if(typeID == MILES_CRUISER){
				initializeShip(300,2,10);
				setNrFighters(0);
			}
			else if(typeID == MILES_FRIGATE){
				initializeShip(1000,7,20);
				setNrFighters(10);
			}
			else if(typeID == MILES_DESTROYER){
				initializeShip(2000,19,30);
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
		float nrProtected;

		void setNrFighters(int nrFighters){
			this->nrFighters = nrFighters;
			this->nrProtected = ((this->nrFighters)/2) + 1;
		}

};


class MedicShip : public Ship{
	public :
		MedicShip(int typeID)
		: Ship(typeID)
		{
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
		Fleet(vector<ColonyShip*> * allColonyShips,
					vector<SolarSailShip*> * allSolarSailShips,
					vector<MilitaryEscortShip*> * allMilitaryEscortShips,
					vector<MedicShip*> * allMedicShips,
					string CorporationName){
			this->allColonyShips = allColonyShips;
			this->allSolarSailShips = allSolarSailShips;
			this->allMilitaryEscortShips = allMilitaryEscortShips;
			this->allMedicShips = allMedicShips;
			setCorporationName(CorporationName);
			initialize();
		}
		virtual ~Fleet(){}

		bool isDefeated(){return this->defeated;}
		bool isDisqualified(){return this->disqualified;}
		bool validify(){
			bool hasEnoughEnergy = getEnergyConsumption() <= getEnergyProduced();
			bool compliesBudget = getCost() <= 10000;

			bool validity = hasEnoughEnergy && compliesBudget;
			setDisqualified(!validity);
			return validity;
		}

		// #7
		bool hasMedic(){return this->isImmune;}

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
		int countProtectedShips(){	return this->nrProtected;}



		float getArrivalTime(){return this->arrivalTime;}
		void launchFleet(){
			// First Half of Journey
			float timeFirstHalf;
			float timeSecondHalf;
 			timeFirstHalf = (3.3/2) * sqrt(getWeight());
 			// Second Half of Journey
			applyInvasionAndInfection();
			timeSecondHalf = (3.3/2) * sqrt(getWeight());
			float arrivalTime = timeFirstHalf + timeSecondHalf;

			setArrivalTime(arrivalTime);
		}

		// #8
		string getCorporationName(){return this->CorporationName;}

		// #9
		vector<ColonyShip *> protectedShips(){return this->allProtectedShips;}

		// #10
		vector<ColonyShip *> unprotectedShips(){return this->allUnprotectedShips;}

		// #11
		vector<ColonyShip *> colonyShips(){return *this->allColonyShips;}

		// #12
		vector<int> shipList(){return this->allShipIDs;}

		void setDefeated(bool flag){this->defeated = flag;}

		// #13
		void destroyShip(ColonyShip * targetDestruct){
			for(unsigned int i=0;i<allColonyShips->size();i++){
				if(allColonyShips->at(i) == targetDestruct){
					ColonyShip * temp = allColonyShips->at(i);


					targetDestruct->setAlive(false);
					this->weight -= targetDestruct->getWeight();
					this->energyConsumption -= targetDestruct->getEnergyConsumption();
					this->colonistAmount -= targetDestruct->getColonistAmount();
					allColonyShips->erase(allColonyShips->begin()+i);

					delete temp;
					break;
				}
			}
		}
		void destroyShip(int targetIndex){
			allColonyShips->at(targetIndex)->setAlive(false);
			this->weight -= allColonyShips->at(targetIndex)->getWeight();
			this->energyConsumption -= allColonyShips->at(targetIndex)->getEnergyConsumption();
			this->colonistAmount -= allColonyShips->at(targetIndex)->getColonistAmount();
			allColonyShips->erase(allColonyShips->begin()+targetIndex);
		}

		void infectShip(int targetIndex){
			allColonyShips->at(targetIndex)->setAlive(false);
			this->colonistAmount -= allColonyShips->at(targetIndex)->getColonistAmount();
		}

		void applyInvasionAndInfection(){
			srand(time(NULL));
			int nrUnprotectedShips = this->allUnprotectedShips.size();
			int nrTargetsRemaining = ceil((0.25*nrUnprotectedShips));

			while(nrTargetsRemaining > 0 && nrUnprotectedShips > 0){
				int targetIndex = rand() % (nrUnprotectedShips-1);
				destroyShip(targetIndex);
				nrTargetsRemaining--;
				nrUnprotectedShips--;
			}

			if(!hasMedic() && allColonyShips->size() > 0){
				int targetIndex = rand() % (this->allColonyShips->size() - 1);
				infectShip(targetIndex);
			}

		}
		void setArrivalTime(float arrivalTime){this->arrivalTime = arrivalTime;}
		void setDisqualified(bool flag) { this->disqualified = flag;}
	    bool operator < ( Fleet &nextFleet)
	    {
	    	cout << "Comparing ...";
	    	cout << getArrivalTime() << endl;
	        return (getArrivalTime() > nextFleet.getArrivalTime());
	    }

		void initialize(){
			this->weight = 0;
			this->cost = 0;
			this->energyConsumption = 0;
			this->energyProduced = 0;
			this->nrFighters = 0;
			this->nrProtected = 0;
			this->colonistAmount = 0;
			this->isImmune = (allMedicShips->size() > 0);

			for(unsigned int i=0; i<allMilitaryEscortShips->size();i++){
				this->weight += allMilitaryEscortShips->at(i)->getWeight();
				this->cost += allMilitaryEscortShips->at(i)->getCost();
				this->energyConsumption += allMilitaryEscortShips->at(i)->getEnergyConsumption();
				this->nrFighters += allMilitaryEscortShips->at(i) ->getNrFighters();
				this->nrProtected += allMilitaryEscortShips->at(i) ->getNrProtected(); // floor later;
				this->allShipIDs.push_back(allMilitaryEscortShips->at(i)->getID());
			}
			this->nrProtected = floor(this->nrProtected);

			int numberProtectable = this->nrProtected;
			for(unsigned int i=0; i<allColonyShips->size();i++){
				this->weight += allColonyShips->at(i)->getWeight();
				this->cost += allColonyShips->at(i)->getCost();
				this->energyConsumption += allColonyShips->at(i)->getEnergyConsumption();
				this->colonistAmount += allColonyShips->at(i)->getColonistAmount();

				if(numberProtectable > 0){
					allColonyShips->at(i)->setGuarded(true);
					this->protectedShipIDs.push_back(allColonyShips->at(i)->getID());
					this->allProtectedShips.push_back(allColonyShips->at(i));
					numberProtectable --;
				}
				else{
					this->unprotectedShipIDs.push_back(allColonyShips->at(i)->getID());
					this->allUnprotectedShips.push_back(allColonyShips->at(i));
				}
				this->colonyShipIDs.push_back(allColonyShips->at(i)->getID());
				this->allShipIDs.push_back(allColonyShips->at(i)->getID());
			}
			for(unsigned int i=0; i<allSolarSailShips->size();i++){
				this->weight += allSolarSailShips->at(i)->getWeight();
				this->cost += allSolarSailShips->at(i)->getCost();
				this->energyConsumption += allSolarSailShips->at(i)->getEnergyConsumption();
				this->energyProduced += allSolarSailShips->at(i)->getEnergyProduction();
				this->allShipIDs.push_back(allSolarSailShips->at(i)->getID());
			}


			for(unsigned int i=0; i<allMedicShips->size();i++){
				this->weight += allMedicShips->at(i)->getWeight();
				this->cost += allMedicShips->at(i)->getCost();
				this->energyConsumption += allMedicShips->at(i)->getEnergyConsumption();
				this->allShipIDs.push_back(allMedicShips->at(i)->getID());
			}

			//bubbleSorting
			for(unsigned int h=0;h<(allColonyShips->size());h++){
				ColonyShip * temp;
				for(unsigned int i=0;i<(allColonyShips->size()- 1);i++){
					if(allColonyShips->at(i)->getWeight() < allColonyShips->at(i+1)->getWeight()){
						temp = allColonyShips->at(i);
						allColonyShips->at(i) = allColonyShips->at(i+1);
						allColonyShips->at(i+1) = temp;
					}
				}
			}

		}



	private:
		vector<ColonyShip*> * allColonyShips;
		vector<SolarSailShip*> * allSolarSailShips;
		vector<MilitaryEscortShip*> * allMilitaryEscortShips;
		vector<MedicShip*> * allMedicShips;

		bool isImmune = false;
		bool disqualified = false;
		bool defeated = false;

		int weight;
		int cost;
		int energyConsumption;
		int energyProduced;
		int nrFighters;
		int colonistAmount;

		float nrProtected;
		float arrivalTime;

		string CorporationName;

		vector<int> protectedShipIDs;
		vector<int> unprotectedShipIDs;
		vector<int> colonyShipIDs;
		vector<int> allShipIDs;
		vector<ColonyShip *> allProtectedShips;
		vector<ColonyShip *> allUnprotectedShips;

		void setCorporationName(string  CorporationName){this->CorporationName = CorporationName;}
};


#endif

