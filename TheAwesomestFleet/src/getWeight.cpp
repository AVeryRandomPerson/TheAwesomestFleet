// #15
//returns weight of a ship

#include <iostream>
#include <map>
#include <string>
using namespace std;

typedef map<string, int> TStrIntMap;
typedef pair<string, int> TStrIntPair;

int main(int argc, char *argv[])
{
    TStrIntMap shipWeight;

	shipWeight.insert(TStrIntPair("Ferry", 10));
	shipWeight.insert(TStrIntPair("Liner", 20));
	shipWeight.insert(TStrIntPair("Cloud", 30));
	shipWeight.insert(TStrIntPair("Radiant", 3));
	shipWeight.insert(TStrIntPair("Ebulient", 50));
	shipWeight.insert(TStrIntPair("Cruiser", 2));
	shipWeight.insert(TStrIntPair("Frigate", 7));
	shipWeight.insert(TStrIntPair("Destroyer", 19));
	shipWeight.insert(TStrIntPair("Medic", 1));

	string inputWeight;
	cout << "Enter a ship name to get its weight: ";
	cin >> inputWeight;

    int x;
	int intValue = shipWeight[inputWeight];
	if(intValue != 0){
		// Show value
		cout << "Weight of a ship: " << intValue;
	}
	else{
		TStrIntMap::iterator i;
		bool bFound=false;

		// Show key
		for(i = shipWeight.begin(); i!=shipWeight.end(); ++i){
			int strKey;
			intValue = x;
			strKey= i->second;

			if( intValue  == strKey){
				// Return key
				cout << "Weight of a ship: " << i->first << endl;
				bFound = true;
			}
		}
		// If not found
		if(!bFound){
			cout << "Ship is not found! Please recheck again." << endl;
		}
	}
}
