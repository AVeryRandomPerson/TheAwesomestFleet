#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    vector < pair<string, int> > v;

    int value;
    string ship;
    ifstream infile;

    string input = "example.dat"; //this file located at the same folder as .cpp and .h files
    infile.open (input.c_str());

    while (infile >> ship >> value){

    v.push_back(pair<string, int> (ship, value));
    cout << ship << " " << value << endl;;
    }

    infile.close();
}
