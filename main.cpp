// Title: Lab 5 - main.cpp
//
// Purpose: Program for testing the Battleship "grid" ADT.  In the Lab 5 version the
//          user can fire shots at a grid either manually, or by calling the cpuLogic module
//
// Class: CSC 2430 Winter 2020
// Author: Max Benson
//
#include <iostream>
#include "grid.h"
#include "cpulogic.h"
#include "helperCode.h"

// Forward Declaration
void UserDetermineShot(int& row, int& column);

//  Main program that drives the user interaction
//      Prompts the user for a saved ship configuration and loads the configuration
//      Let's the user choose either to manually or algorithmicall fire at the
//      grid.  Then, each time the user fires a shot, the display of the grid
//      is reprinted so the firing logic can be tested.
int main() {
    string mode;
    string command;
    string fileName;
    ifstream ifile;
    CpuLogic cpuLogic;
    Grid grid;

    // Get file naem for saved ship placement
    cout << "Enter file name for saved ship placement: ";
    cin >> fileName;

    // Load saved ship placement
    ifile.open(fileName);
    if (!ifile.is_open() || !grid.LoadShips(ifile)) {
        cout << "Unable to load ships from file" << endl;
        return 0;
    }
    ifile.close();

    // Display grid
    PrintGrid(grid);

    // Determine how shots should be fired
    do {
        cout << "Enter M to manually fire shots, A to algorithmically fire shots: ";
        cin >> mode;
    } while (mode != "M" && mode != "A");

    // IF user selected algorithmic firing, get random seed
    if (mode == "A") {
        int randomSeed;

        // Prompt for random seed to use
        cout << "Enter seed for random number generator: ";
        cin >> randomSeed;
        srand(randomSeed);
    }

    // Fire shots
    while (true) {
        bool success;
        int row;
        int column;
        Outcome outcome;

        // Figure out what to do
        do {
            cout << "Enter Q for quit, P for print grid, or F for fire a shot: ";
            cin >> command;
        } while (command != "Q" && command != "P" && command != "F");

        // If user chooses to quit
        if (command == "Q") {
            break;
        }

        // Print grid
        else if (command == "P") {
            PrintGrid(grid);
        }

        // Fire shots
        else {
            // Determine location of shot
            if (mode == "M") {
                UserDetermineShot(row, column);
            } else {
                cpuLogic.DetermineShot(row, column);
                cout << "Firing at (" << row << ", " << column << "), ";
            }

            // Fire the shot
            success = grid.FireShot(row, column, outcome);

            // Handle error
            if (!success) {
                cout << "Failed to fire shot" << endl;
                continue;
            }

            // Report outcome to cpuLogic
            if (mode == "A") {
                cpuLogic.ReportOutcome(row, column, outcome);
            }

            // Display outcome and updated grid
            switch (outcome) {
                case SHOT_MISSED:
                    cout << "outcome = SHOT_MISSED" << endl;
                    break;
                case SHIP_HIT:
                    cout << "outcome = SHIP_HIT" << endl;
                    break;
                case SHIP_SUNK:
                    cout << "outcome = SHIP_SUNK" << endl;
                    break;
                case SHOT_HERE_BEFORE:
                    cout << "outcome = SHOT_HERE_BEFORE" << endl;
                    break;
                case GAME_WON:
                    cout << "outcome = GAME_WON" << endl;
                    break;

            }
        }
    }
}

//  This function asks where the user wants to fire
//  Parameters:
//      row - selected row for shot
//      column - selected column for shot
//  Returns:
//      true
//  Possible Errors:
//      none
void UserDetermineShot(int& row, int& column) {
    // Get the location of the shot
    cout << "Enter row, and column of shot: ";
    cin >> row >> column;
}
