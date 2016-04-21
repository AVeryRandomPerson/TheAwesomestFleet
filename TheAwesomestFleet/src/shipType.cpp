// #17
//returns type of a ship

#include <iostream>
#include <map>
#include <string>
using namespace std;

typedef map<string, string> TStrStrMap;
typedef pair<string, string> TStrStrPair;

int main(int argc, char *argv[])
{
    TStrStrMap shipType;

	shipType.insert(TStrStrPair("Ferry", "Colony Ship"));
	shipType.insert(TStrStrPair("Liner", "Colony Ship"));
	shipType.insert(TStrStrPair("Cloud", "Colony Ship"));
	shipType.insert(TStrStrPair("Radiant", "Solar Sail Ship"));
	shipType.insert(TStrStrPair("Ebulient", "Solar Sail Ship"));
	shipType.insert(TStrStrPair("Cruiser", "Military Escort Ship"));
	shipType.insert(TStrStrPair("Frigate", "Military Escort Ship"));
	shipType.insert(TStrStrPair("Destroyer", "Military Escort Ship"));
	shipType.insert(TStrStrPair("Medic", "Medic Ship"));

    string inputToType;
	cout << "Enter a ship name to get its type: ";
	cin >> inputToType;

	string strValue = shipType[inputToType];
	if(strValue != ""){
		// Show value
		cout << "The type of this ship is: " << strValue;
	}
	else{
		TStrStrMap::iterator i;
		bool bFound=false;

		// Show key
		for(i = shipType.begin(); i!=shipType.end(); ++i){
			string strKey;
			strValue = inputToType;
			strKey= i->second;

			if( strValue  == strKey){
				// Return key
				cout << "The type of this ship is: " << i->first << endl;
				bFound = true;
			}
		}
		// If not found
		if(!bFound){
			cout << "Ship is not found! Please recheck again." << endl;
		}
	}
}
