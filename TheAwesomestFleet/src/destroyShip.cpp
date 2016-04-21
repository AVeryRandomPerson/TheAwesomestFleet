// #13
//removes ships i from the fleet
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    vector<string> myShip;

    string Frigate, Cloud, Liner, Destroyer, Medic, Ebulient;
    int i;

    myShip.push_back("Frigate");
    myShip.push_back("Ebulient");
    myShip.push_back("Medic");
    myShip.push_back("Cloud");
    myShip.push_back("Liner");
    myShip.push_back("Destroyer");

    cout << "Ships in a fleet:";
    for (unsigned i=0; i<myShip.size(); i++)
    cout << '\n' << myShip[i];
    cout << '\n' << endl;


    cout << "Destroy a ship from the fleet: ";
    cin >> i;

    myShip.erase (myShip.begin()+i);


    cout << endl << "Update ships in a fleet:";
    for (unsigned i=0; i<myShip.size(); i++)
    cout << '\n' << myShip[i];
    cout << '\n';

}
