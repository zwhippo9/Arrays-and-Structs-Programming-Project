#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

//constants
const int n = 5; //number of runners
const int d = 7; //number of days

// struct
struct Runner {
    string name; //runner name
    double miles[d]; //miles per day
};

//function
void getData(ifstream& inf, Runner runners[], int count);
void printData(const Runner runners[], int count);

int main() {
    Runner runners[n]; //array of structs

    ifstream inputFile("beau.txt");
    if (!inputFile) {
        cout << "Error opening file." << endl;
        return 1;
    }

    getData(inputFile, runners, n);
    printData(runners, n);

    return 0;
}

//to get data
void getData(ifstream& inf, Runner runners[], int count) {
    for ( int i = 0; i < count; i++) {
        inf >> runners[i].name; //read name
        for(int j = 0; j < d; j++) {
            inf >> runners[i].miles[j]; //read miles per day
        }
    }
}

//to print data
void printData(const Runner runners[], int count) {
    cout << setw(6) << "Name"; 
    for (int j = 0; j < d; j++) {
        cout << setw(10) << "Day " << (j + 1);
}
    cout << setw(10) << "Total" << setw(12) << "Average" << endl;

    for (int i = 0; i < count; i++)  {
        double totalMiles = 0; //total miles for each runner
        cout << setw(10) << runners[i].name; //print name
        for (int j = 0; j < d; j++) {
           cout << setw(10) << fixed << setprecision(2) << runners[i].miles[j]; //print miles per day
        }
        double avgMiles = totalMiles / d; //average miles per day        
        cout << setw(10) << fixed << setprecision(2) << totalMiles; 
        cout << setw(10) << fixed << setprecision(2) << avgMiles << endl;
        cout << endl;
    }
}
