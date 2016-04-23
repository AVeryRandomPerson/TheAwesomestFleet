#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void openFile( vector < pair <string, int> > &v);
void print_vector( vector < pair<string, int> > &v);


int main(){

    string ship;
    int value;
    vector < pair< string, int> > v;
    openFile(v);
    print_vector(v);


    return 0;
    }

void openFile( vector < pair <string, int> > &v){
    //vector < pair<string, int> > v;

    int value;
    string ship;
    ifstream infile;

    string input = "example.dat"; //this file located at the same folder as .cpp and .h files
    infile.open (input.c_str());

    while (infile >> ship >> value){

    v.push_back(pair<string, int> (ship, value));
  //  cout << ship << " " << value << endl;
    }

    infile.close();
}

void print_vector( vector < pair<string, int> > &v){

        for(int i = 0; i < v.size(); i ++){
                cout << v[i].first << ", " << v[i].second << endl;
        }
}
