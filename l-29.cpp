// COMSC 210 | Lab 29 + 30 + 31 | Annie Morales
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
using namespace std;

// A function defined to simulate a small factory changing each production cycle
// Parameters: map of departments, number of intervals
// Function prototype
void factory_sim(map<string, array<list<string>, 3>> &factory, int interval);

// Define main function
// Initialize a map to store factory information stored in an array of lists for:
// ingredients, cookie batches, and employees

int main (){
    // main program 
    srand(time(0));
    map<string, array<list<string>, 3>> factory; // map of factory

    ifstream file("factory_data.txt");
    if (!file){
        cout << "Error opening file." << endl; // Outputs error
        return 1; // Exits program
    }

    string department;
    while (getline(file, department)){
        if (department.empty()) continue;
        array<list<string>, 3> data; // array of lists for ingredients, cookies, employees
        string line;

        // Read each ingredient
        while (getline(file, line) && !line.empty()){
            if (line.empty()) break;
            data[0].push_back(line);
        }

        // Read cookies
        while (getline(file, line) && !line.empty()){
            if (line.empty()) break;
            data[1].push_back(line);
        }

        // Read employees
        while (getline(file, line) && !line.empty()){
            if (line.empty()) break;
            data[2].push_back(line);
        }

        // Populate the map with department as key and data array as value
        factory[department] = data;
    }
    //cout << "File has been read and will now close...\n\n";
    file.close();
    cout << "\n====================================================";
    cout << "\n** Initial Factory Stats **\n";
    cout << "====================================================\n";
    // Will out put three departments: baking, packaging, sales
    for (const auto &dept : factory){
        cout << "\nDepartment: " << dept.first << "\n";
        cout << " Stock" << "(" << dept.second[0].size() << "):" << setw (11);
        for (const auto &ing : dept.second[0]){
            cout << ing << " " ;
        }
        cout << "\n Cookies" << "(" << dept.second[1].size() << "):" << setw (15);
        for (const auto &cook : dept.second[1]){
            cout << cook << " ";
        }
        cout << "\n Employees" << "(" << dept.second[2].size() << "):" << setw (9);
        for (const auto &emp : dept.second[2]){
            cout << emp << " ";
        }
        cout << "\n---------------------------------------------\n";
    }

    // Time-based simulation for factory starts
    // For 25 intervals, interate through each department in the map and simulate changes
    factory_sim(factory, 25);
    
    // Random events that may impact the factory during simulation which are defined in factory_sim:
    // Hired/fired worker, new cookie batches, change in stock, cookies packed, etc...
    // New factory stats are outputted at the end of each interval.
    cout << "\n====================================================";
    cout << "\n** New Factory Stats **\n";
    cout << "====================================================" << endl;
    for (const auto &dept : factory){
        cout << "\nDepartment: " << dept.first << "\n";
        cout << "Cookie batches total: " << dept.second[1].size() << "\n";
        cout << "Employees: " << dept.second[2].size() << "\n";
        cout << "Items in stock: " << dept.second[0].size() << "\n";
        cout << "-------------------------";
    }
    // End of main function and simulation of the factory
    cout << "\nEnd of simulation after 25 cycles!\n\n";
    return 0;
}

// Void function definition to simulate factory
void factory_sim(map<string, array<list<string>, 3>> &factory, int interval){
    // void program defining the factory 
    // The random events occur in the factory and intervals are counted until 25 is reached.
    cout << "\n====================================================" << endl;
    cout << "** Simulating 25 Factory Cycles **";
    cout << "\n====================================================";
    for (int i = 1; i <= interval; ++i){
        cout << "\n\n ---- Factory Cycle " << i << " ----\n";

        for (auto &dept : factory){
            int event = rand() % 11; // Picks a random event (0-10)

            switch (event){
                case 0: // New cookie batch produced
                    dept.second[1].push_back("cookie_batch_" + to_string(i));
                    cout << "New cookie batch in " << dept.first << " department.\n";
                    break;
                case 1: // Items used
                if (!dept.second[0].empty()){
                    dept.second[0].pop_back();
                    cout << "Items used in " << dept.first << " department.\n";
                } else {
                    cout << dept.first << ": No more items available!\n";
                }
                    break;
                case 2: // Hire new employee
                dept.second[2].push_back("employee_" + to_string(i));
                cout << "New employee hired in " << dept.first << " department.\n";
                    break;
                case 3: // Firing employees
                if (!dept.second[2].empty()){
                    dept.second[2].pop_back();
                    cout << "An employee was let go in " << dept.first << " department.\n";
                } else {
                    cout << dept.first << ": No employees to let go!\n";
                }
                    break;
                case 4: // Packaging cookies
                if (!dept.second[1].empty()){
                    dept.second[1].pop_back();
                    cout << "A cookie batch was packaged in " << dept.first << " department.\n";
                } else {
                    cout << dept.first << ": No cookie batches to package!\n";
                }
                    break;
                case 5: // Random inspection
                cout << "Random inspection in " << dept.first << " department. All good!\n";
                    break;
                case 6: // Error in department
                cout << "A minor error has occured in the " << dept.first << " department. Issue quickly resolved.\n";
                    break;
                case 7: // Supply issue
                cout << "A supplier had an issue with delivery to the " << dept.first << " department.\n";
                    break;
                case 8: // Regulation check
                cout << "A regulation check's done in the " << dept.first << " department. It's all up to standard.\n";
                    break;
                case 9: // Stock check
                cout << "Stock's checked in the " << dept.first << " department. Everything's accounted for.\n";
                    break;
                case 10: // Product defect
                cout << "There has been a defective product in the " << dept.first << " department.\n";
                    break;
            }
        }
    }
}