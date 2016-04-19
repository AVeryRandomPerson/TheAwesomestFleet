//============================================================================
// Name        : TheAwesomestFleet.cpp
// Author      : Jon
// Version     :
//============================================================================

#include <cstdio>
#include "Fleet.h"

using namespace std;

int main() {
	printf("This will soon become a simulation program of space racing !\n");
	// Creating All Types of Ships for Any Possible Future Test Cases
	ColonyShip testingFerry(COLS_FERRY);
	ColonyShip testingLiner(COLS_LINER);
	ColonyShip testingCloud(COLS_CLOUD);

	SolarSailShip testingRadiant(SOLSS_RADIANT);
	SolarSailShip testingEbulient(SOLSS_EBULIENT);

	MilitaryEscortShip testingCruiser(MILES_CRUISER);
	MilitaryEscortShip testingFrigate(MILES_FRIGATE);
	MilitaryEscortShip testingDestroyer(MILES_DESTROYER);

	MedicShip testingMedic(MEDS_MEDIC);

	return 0;
}

