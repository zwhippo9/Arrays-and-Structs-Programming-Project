// this program will take the number of miles per day from one of 5 people and calculate the average miles per day over the course of a week. The program will then display the average miles per day for each person in a chart that looks something like the output you are about to compute.


#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

const int N = 5; // Number of runners
const int D = 7; // Number of days

// Function prototypes
void getData(ifstream& inf, string names[], double runData[][D], int count);
void printData(string names[], double runData[][D], int count);

int main() {
    string names[N]; 
    double run[N][D] = {{0}}; 

    ifstream inputFile("data.txt");
    if (!inputFile) {
        cout << "Error opening file." << endl;
        return 1;
    }

    getData(inputFile, names, run, N); // Get data
    printData(names, run, N); // print data

    return 0;
}

// Function to get data
void getData(ifstream& inf, string names[], double runData[][D], int count) {
    for (int i = 0; i < count; i++) {
        if (!(inf >> names[i])) { // Read names
            cout << "Error reading name for runner " << i + 1 << endl;
            return;
        }
        for (int j = 0; j < D; j++) {
            if (!(inf >> runData[i][j])) { // Read data
                cout << "Error reading miles for " << names[i] << " on day " << j + 1 << endl;
                return;
            }
        }
    }
}

// Function to print data
void printData(string names[], double runData[][D], int count) {
    cout << setw(10) << "Name";


    for (int j = 0; j < D; j++) {
        cout << setw(10) << "Day" << j + 1;
    }
    cout << setw(10) << "Total" << setw(10) << "Avg" << endl; 

    // Print data for each runner
    for (int i = 0; i < count; i++) {
        double totalMiles = 0; 

        cout << setw(10) << names[i];
        for (int j = 0; j < D; j++) {
            cout << setw(10) << fixed << setprecision(2) << runData[i][j]; 

            totalMiles += runData[i][j]; 
        }
        double avgMiles = totalMiles / D; 

 // Calculate average miles run per day for the runner
        cout << setw(10) << totalMiles << setw(10) << fixed << setprecision(2) << avgMiles;

// Print total and average miles
        cout << endl;
    }
}