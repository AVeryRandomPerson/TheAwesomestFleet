// #12
//ship in the fleets

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void printShip(vector<string>shipList){

    string Frigate, Cloud, Liner, Destroyer, Medic, Ebulient;

    shipList.push_back("Frigate");
    shipList.push_back("Ebulient");
    shipList.push_back("Medic");
    shipList.push_back("Cloud");
    shipList.push_back("Liner");
    shipList.push_back("Destroyer");

    cout << "Ships in a fleet:";
    for (unsigned i=0; i<shipList.size(); i++)
    cout << '\n' << shipList[i];
    cout << '\n' << endl;


}
using namespace std;
int main(){

    vector<string> myShip;

    printShip(myShip);


/*    string insertShip;
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


    /*cout << "Insert ship to the fleet: ";
    cin >> insertShip;

    myShip.insert(myShip.begin()+0, insertShip);


    cout << endl << "Update ships in a fleet:";
    for (unsigned i=0; i<myShip.size(); i++)
    cout << ' ' << myShip[i];
    cout << '\n';
    */

}

