// #11
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int main () {
  // counting elements in array:
    string shipList[] = {"Frigate","Cloud","Liner","Liner","Medic","Destroyer","Ebulient","Ferry"};   // 8 elements

    cout << "Colony ships consist of: \n";
    int countColonyShip = count (shipList, shipList+8, "Ferry");
    cout << "Ferry has " << countColonyShip << " in this fleet.\n";

  // counting elements in container:
    vector<string> myvector (shipList, shipList+8);
    countColonyShip = count (myvector.begin(), myvector.end(), "Liner");
    cout << "Liner has " << countColonyShip  << " in this fleet.\n";

    countColonyShip = count (myvector.begin(), myvector.end(), "Cloud");
    cout << "Cloud has " << countColonyShip  << " in this fleet.\n";
}
