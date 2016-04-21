// #14
//returns energy consumption of a ship
#include <iostream>
#include <map>
#include <string>
using namespace std;

typedef map<string, int> TStrIntMap;
typedef pair<string, int> TStrIntPair;

int main(int argc, char *argv[])
{
    TStrIntMap shipEnergy;

	shipEnergy.insert(TStrIntPair("Ferry", 5));
	shipEnergy.insert(TStrIntPair("Liner", 7));
	shipEnergy.insert(TStrIntPair("Cloud", 9));
	shipEnergy.insert(TStrIntPair("Radiant", 5));
	shipEnergy.insert(TStrIntPair("Ebulient", 5));
	shipEnergy.insert(TStrIntPair("Cruiser", 10));
	shipEnergy.insert(TStrIntPair("Frigate", 20));
	shipEnergy.insert(TStrIntPair("Destroyer", 30));
	shipEnergy.insert(TStrIntPair("Medic", 1));

	string input;
	cout << "Enter a ship name to get its energy consumption: ";
	cin >> input;

    int x;
	int intValue = shipEnergy[input];
	if(intValue != 0){
		// Show value
		cout << "Energy consumed: " << intValue;
	}
	else{
		TStrIntMap::iterator i;
		bool bFound=false;

		// Show key
		for(i = shipEnergy.begin(); i!=shipEnergy.end(); ++i){
			int strKey;
			intValue = x;
			strKey= i->second;

			if( intValue  == strKey){
				// Return key
				cout << "Energy consumed: " << i->first << endl;
				bFound = true;
			}
		}
		// If not found
		if(!bFound){
			cout << "Word not in map." << endl;
		}
	}
}
