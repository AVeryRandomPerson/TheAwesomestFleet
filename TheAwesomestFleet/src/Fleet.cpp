//============================================================================
// Name        : TheAwesomestFleet.cpp
// Author      : Jon
// Version     :
//============================================================================

#include "Fleet.h"

#include <fstream>

using namespace std;

//Gets final population amount given the start time of arrival on planet, the final time of checking and the initial population
int getGrownAmount(int baseAmount, float arrivalTime, float comparedTime){
	float growthTime = floor(comparedTime - arrivalTime);
	int population = baseAmount;

	for(int i=0;i<growthTime;i++){
		population = floor(1.05 * population);
	}
	return population;
}

// Reads data from File and saves appropriately to vector data.
void readShipFile(vector<ColonyShip *> * ptrAllColonyShips,
		vector<SolarSailShip *> * ptrAllSolarSailShips,
		vector<MilitaryEscortShip *> * ptrAllMilitaryEscortShips,
		vector<MedicShip *> * ptrAllMedicShips,
		string corporationName
		){
    int value;
    string ship;
    string line;

    string filename =  corporationName + ".dat";
    ifstream myfile;

    myfile.open (filename.c_str());
    if (myfile){
        while (myfile >> ship >> value){
        	if(NAME_TO_CLASS_MAP[ship] == COLS_CLASS){
        		for(int i = 0; i< value; i++){
        			ptrAllColonyShips->push_back(new ColonyShip(NAME_TO_ID_MAP[ship]));
        		}
        	}
        	else if(NAME_TO_CLASS_MAP[ship] == SOLSS_CLASS){
        		for(int i = 0; i< value; i++){
        			ptrAllSolarSailShips->push_back(new SolarSailShip(NAME_TO_ID_MAP[ship]));
        		}
        	}
        	else if(NAME_TO_CLASS_MAP[ship] == MILES_CLASS){
    			for(int i = 0; i< value; i++){
    				ptrAllMilitaryEscortShips->push_back(new MilitaryEscortShip(NAME_TO_ID_MAP[ship]));
    			}
    		}
        	else if(NAME_TO_CLASS_MAP[ship] == MEDS_CLASS){
    			for(int i = 0; i< value; i++){
    				ptrAllMedicShips->push_back(new MedicShip(NAME_TO_ID_MAP[ship]));
    			}
    		}
        }
    }
    else{
    	cout << "[Announcement] "<< "Sorry commander. It seems your file is not found.";
    }

    myfile.close();
}

// Interacts with user to create a Fleet.
Fleet* userInterfaceCreateFleet(vector<ColonyShip *> * ptrAllColonyShips ,
		vector<SolarSailShip *>  * ptrAllSolarSailShips,
		vector<MilitaryEscortShip *>  * ptrAllMilitaryEscortShips,
		vector<MedicShip *>  * ptrAllMedicShips,
		string corporationName){
			int shipQty;
			string decision;

			cout << "Do you want us to review your fleets through a file? (y/n)";
			cin >> decision;

			if(decision.at(0) == 'y'){
				cout << "Understood. Searching for your file." << endl;

				readShipFile(ptrAllColonyShips,ptrAllSolarSailShips,ptrAllMilitaryEscortShips,ptrAllMedicShips,corporationName);
				Fleet * fleet = new Fleet(ptrAllColonyShips,ptrAllSolarSailShips,ptrAllMilitaryEscortShips,ptrAllMedicShips,corporationName);
				fleet->validify();

				cout << "[Announcement] Review Over. "<< "Cost of your fleet is : " << fleet->getCost() << endl;
				cout << "[Announcement] Review Over. "<< "Your fleet has enough energy to run" << endl;

				if(!fleet->isDisqualified()){
					cout << "[Announcement] "<< "Good Luck! " << corporationName << " , your fleet is valid and verified." << endl;
				}
				else{
					cout << endl;
					cout << "[Announcement] "<< "Sorry commander. Unfortunately your fleet appears to be invalid ! " << endl;
					cout << "[Announcement] " << corporationName << " Please check your fleet again. It must be within budget and have enough energy." << endl;
					fleet->setDisqualified(true);
				}
				cout << endl << endl;
				return fleet;
			}
			else{
				cout << "[Colony Ship Check] How many Ferry(ies) do you have?" << endl;
				cin >> shipQty;
				for(int i=0;i<shipQty;i++){
					ptrAllColonyShips->push_back(new ColonyShip(COLS_FERRY));
				}

				cout << endl;
				cout << "[Colony Ship Check] How many Liner(s) do you have?" << endl;
				cin >> shipQty;
				for(int i=0;i<shipQty;i++){
					ptrAllColonyShips->push_back(new ColonyShip(COLS_LINER));
				}
				cout << endl;
				cout << "[Colony Ship Check] How many Cloud(s) do you have?" << endl;
				cin >> shipQty;
				for(int i=0;i<shipQty;i++){
					ptrAllColonyShips->push_back(new ColonyShip(COLS_CLOUD));
				}
				cout << endl;
				cout << "[Solar Sail Ship Check] How many Radiant(s) do you have?" << endl;
				cin >> shipQty;
				for(int i=0;i<shipQty;i++){
					ptrAllSolarSailShips->push_back(new SolarSailShip(SOLSS_RADIANT));
				}
				cout << endl;
				cout << "[Solar Sail Ship Check] How many Ebulient(s) do you have?" << endl;
				cin >> shipQty;
				for(int i=0;i<shipQty;i++){
					ptrAllSolarSailShips->push_back(new SolarSailShip(SOLSS_EBULIENT));
				}
				cout << endl;
				cout << "[Military Escort Ship Check] How many Cruiser(s) do you have?" << endl;
				cin >> shipQty;
				for(int i=0;i<shipQty;i++){
					ptrAllMilitaryEscortShips->push_back(new MilitaryEscortShip(MILES_CRUISER));
				}
				cout << endl;
				cout << "[Military Escort Ship Check] How many Frigate(s) do you have?" << endl;
				cin >> shipQty;
				for(int i=0;i<shipQty;i++){
					ptrAllMilitaryEscortShips->push_back(new MilitaryEscortShip(MILES_FRIGATE));
				}
				cout << endl;
				cout << "[Military Escort Ship Check] How many Destroyer(s) do you have?" << endl;
				cin >> shipQty;
				for(int i=0;i<shipQty;i++){
					ptrAllMilitaryEscortShips->push_back(new MilitaryEscortShip(MILES_DESTROYER));
				}
				cout << endl;
				cout << "[Medic Ship Check] How many Medic(s) do you have?" << endl;
				cin >> shipQty;
				for(int i=0;i<shipQty;i++){
					ptrAllMedicShips->push_back(new MedicShip(MEDS_MEDIC));
				}
				cout << endl;
				Fleet * fleet = new Fleet(ptrAllColonyShips,ptrAllSolarSailShips,ptrAllMilitaryEscortShips,ptrAllMedicShips,corporationName);
				fleet->validify();
				if(!fleet->isDisqualified()){
					cout << "[Announcement] Review Over. "<< "Cost of your fleet is : " << fleet->getCost() << endl;
					cout << "[Announcement] Review Over. "<< "Your fleet has enough energy to run" << endl;
					cout << "[Announcement] "<< "Good Luck! " << corporationName << " , your fleet is valid and verified." << endl;
				}
				else{
					cout << endl;
					cout << "[Announcement] "<< "Sorry commander. Unfortunately your fleet appears to be invalid ! " << endl;
					cout << "[Announcement] " << corporationName << " Please check your fleet again. It must be within budget and have enough energy." << endl;
					fleet->setDisqualified(true);
				}
				cout << endl << endl;
				return fleet;
			}

}

// Simulates the race, given all Fleets in the game.
Fleet* startRace(vector<Fleet *> allFleets){
	for(unsigned int i =0; i<allFleets.size();){
		if(allFleets.at(i)->isDisqualified()){
					cout << endl << "[Announcement] "<<allFleets.at(i)->getCorporationName() <<" is disqualified.";
					allFleets.erase(allFleets.begin() + i);
					cout << i;
		}
		else{
			allFleets.at(i)->launchFleet();
			i++;
		}
	}
	cout << endl;
	for(unsigned int i =0; i<allFleets.size();i++){
		cout << "[Announcement] " << allFleets.at(i)->getCorporationName() << " is approved." << endl;
		}


	// Bubble Sorting;
	for(unsigned int h=0;h<(allFleets.size());h++){
		Fleet * temp;
		for(unsigned int i=0;i<(allFleets.size()- 1);i++){
			if(allFleets.at(i)->getArrivalTime() > allFleets.at(i+1)->getArrivalTime()){
				temp = allFleets.at(i);
				allFleets.at(i) = allFleets.at(i+1);
				allFleets.at(i+1) = temp;
			}
		}
	}
	cout << "================================================" << endl;
	cout << "[Announcement] "<< allFleets.at(0)->getCorporationName() << " Has arrived at planet Gaia !" << endl;
	for(unsigned int j =1; j < (allFleets.size()); j++){
		cout << "[Announcement] "<< allFleets.at(j)->getCorporationName() << " Has now arrived at planet Gaia too !" << endl;
		int inhabitantAmountNow = getGrownAmount(allFleets.at(j-1)->getColonistAmount(),allFleets.at(j-1)->getArrivalTime(),allFleets.at(j)->getArrivalTime());
		if(allFleets.at(j)->getColonistAmount() > (inhabitantAmountNow)){
			cout << "[Announcement] "<< allFleets.at(j)->getCorporationName() << " Has more population. They now own planet Gaia !" << endl;
			cout << "[Announcement] " << "The current population to beat as of this announcement is : " << allFleets.at(j)->getColonistAmount() << endl;
			allFleets.at(j-1)->setDefeated(true);
		}
		else{
			cout << "[Announcement] "<< allFleets.at(j)->getCorporationName() << "'s population could not contest against " << allFleets.at(j-1)->getCorporationName() <<  endl ;
			cout << "[Announcement] "<< allFleets.at(j-1)->getCorporationName() <<  " still owns planet Gaia and their population is growing !" << endl;
			cout << "[Announcement] " << "The current population to beat as of this announcement is : " << inhabitantAmountNow << endl;
			allFleets.at(j)->setDefeated(true);
		}

	}
	cout << "[Announcement] All Contesting Fleets Have Arrived !" << endl;
	Fleet * winner;
	for(unsigned int k = 0; k < (allFleets.size()); k++){
		if(!allFleets.at(k)->isDefeated()){
			winner = allFleets.at(k);
			break;
		}
	}
	return winner;
}


int main() {
	int nrFleets;
	cout <<"Greetings, commanders." << endl;
	cout <<"Before we begin, all fleets must be verified and registered." <<endl;
	cout<<"As referee I'd like to know how many of fleets are participating in this race to Gaia." << endl;
	cin >> nrFleets;


	cout << "Very well. Let us begin the inspection." << endl;
	cout << "_______________________________________________________________" << endl;
	vector<Fleet *> allFleets;
	for(int i=0; i<nrFleets; i++){
		string corporationName;

		cout << "Commander of Fleet [ #" << i+1 << " ] what is your Corporation name?" << endl;
		cin >> corporationName;
		vector<ColonyShip *> * ptrAllColonyShips = new vector<ColonyShip*>;
		vector<SolarSailShip *>  * ptrAllSolarSailShips = new vector<SolarSailShip*>;
		vector<MilitaryEscortShip *>  * ptrAllMilitaryEscortShips = new vector<MilitaryEscortShip*>;
		vector<MedicShip *>  * ptrAllMedicShips = new vector<MedicShip*>;
		Fleet * newFleet = new Fleet(ptrAllColonyShips,ptrAllSolarSailShips,ptrAllMilitaryEscortShips,ptrAllMedicShips,corporationName);
		newFleet = userInterfaceCreateFleet(ptrAllColonyShips,ptrAllSolarSailShips,ptrAllMilitaryEscortShips,ptrAllMedicShips,corporationName);
		newFleet->initialize();
		allFleets.push_back(newFleet);
	}
	cout << "[Announcement] "<< "All participating commanders have been checked." << endl;
	cout << "_______________________________________________________________" << endl;
	cout << "Race is Starting !";
	Fleet * winner = startRace(allFleets);
	cout << "[ANNOUNCEMENT] Winner is :" << winner->getCorporationName() << " Congratulations !!!" << endl;

	delete &allFleets;
	return 0;
}

