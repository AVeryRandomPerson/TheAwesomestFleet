// #16
//returns cost of a ship

#include <iostream>
#include <map>
#include <string>
using namespace std;

typedef map<string, int> TStrIntMap;
typedef pair<string, int> TStrIntPair;

int main(int argc, char *argv[])
{
    TStrIntMap shipCost;

	shipCost.insert(TStrIntPair("Ferry", 500));
	shipCost.insert(TStrIntPair("Liner", 1000));
	shipCost.insert(TStrIntPair("Cloud", 2000));
	shipCost.insert(TStrIntPair("Radiant", 50));
	shipCost.insert(TStrIntPair("Ebulient", 250));
	shipCost.insert(TStrIntPair("Cruiser", 300));
	shipCost.insert(TStrIntPair("Frigate", 1000));
	shipCost.insert(TStrIntPair("Destroyer", 2000));
	shipCost.insert(TStrIntPair("Medic", 1000));

	string inputCost;
	cout << "Enter a ship name to get its cost: ";
	cin >> inputCost;

    int x;
	int intValue = shipCost[inputCost];
	if(intValue != 0){
		// Show value
		cout << "Cost for each ship: " << intValue;
	}
	else{
		TStrIntMap::iterator i;
		bool bFound=false;

		// Show key
		for(i = shipCost.begin(); i!=shipCost.end(); ++i){
			int strKey;
			intValue = x;
			strKey= i->second;

			if( intValue  == strKey){
				// Return key
				cout << "Cost for each ship: " << i->first << endl;
				bFound = true;
			}
		}
		// If not found
		if(!bFound){
			cout << "Ship is not found! Please recheck again." << endl;
		}
	}
}
