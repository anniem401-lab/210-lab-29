// COMSC 210 | Lab 29 | Annie Morales
// IDE used: Visual Studio Code

// Include necessary headers for file handling, map, array, list, data structures, etc.
#include <array>
#include <iostream>
#include <iomanip>
#include <map>
#include <list>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
// Including additional headers that may need to be addded
using namespace std;

// A function defined to simulate a factory changing each production cycle
// Parameters: map of departments, number of intervals
// Function prototype
// Void function to simulate factory: 
void factory_sim(map<string, array<list<string>, 3>> &factory, int interval);

// Define main function
// Initialize a map to store factory information stored in an array of lists for:
// ingredients, cookie batches, and employees

int main (){
    // main program 
    srand(time(0));
    map<string, array<list<string>, 3>> factory; // map of factory

    // Open an external file to read data about the facotry and popoulate the map
    // Opening file "factory_data.txt"...
    // If file doesn't open, output error and close out.
    ifstream file("factory_data.txt");
    if (!file){
        cout << "Error opening file." << endl; // Outputs error
        return 1; // Exits program
    }
    // Else: Ingredients, cookies, and employees are read from each line while in file.

    // Closing file after data is read...
    file.close();
    // file closed

    cout << "** Factory Stats **\n" ;
    cout << "Ingredients: ";
    cout << "Cookies: ";
    cout << "Employees: ";

    // Time-based simulation for factory starts
    // For 25 intervals, interate through each department in the map and simulate changes
    factory_sim(factory, 25);
    
    // Random events that may impact the factory during simulation which are defined in factory_sim:
    // Hired/fired worker, new cookie batches, change in stock, cookies packed, etc...
    // New factory stats are outputted at the end of each interval.
    cout << "** New Factory Stats **\n";
    cout << "Cookies produced: ";
    // etc...

    // Wait or pause breifly to simulate the passage of time between intervals

    // End of main function and simulation of the factory
    return 0;
}

// Void function definition to simulate factory
void factory_sim(map<string, array<list<string>, 3>> &factory, int interval){
    // void program defining the factory 
    // The random events occur in the factory and intervals are counted until 25 is reached.
}
