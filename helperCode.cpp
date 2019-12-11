// Title: Lab 5 - helperCode.cpp
//
// Purpose: Implements the PrintGrid helper function used for testing
//
// Class: CSC 2430 Winter 2020
// Author: Max Benson
//
#include <iostream>
#include <sstream>
#include <assert.h>
#include "helperCode.h"

// Print the current state of a grid.
// Parameters:
//      grid - a grid struct
// Returns:
//      nothing
void PrintGrid(const Grid& grid) {
    int shipCount;

    shipCount = grid.GetShipsDeployed();
    cout << "Number of ships:  deployed = " << shipCount << ", sunk = " << grid.GetShipsSunk() << endl;
    for (int i = 0; i < shipCount; i ++ ){
        Ship ship;

        grid.GetShip(i, ship);
        cout << "Ship #" << i << ":";
        cout << "  name = " << ship.name;
        cout << ",\tsize = " << ship.size;
        cout << ",  isVertical = " << ship.isVertical;
        cout << ",  startRow = " << ship.startRow;
        cout << ",  startColumn = " <<  (char)('A'+ship.startColumn);
        cout << ",  hits = " << ship.hits << endl;
    }

    // Display the grid
    cout << " 0123456789" << endl;
    for (int row = 0; row < COUNT_ROWS; row ++ ) {
        ostringstream osstrm;
        string line;

        osstrm << row;
        line = osstrm.str();
        for (int column = 0; column < COUNT_COLUMNS; column ++) {
            int i;
            SquareStatus squareStatus;
            Ship ship;

            squareStatus = grid.GetSquareStatus(row, column);
            switch(squareStatus) {
                case WATER:
                    line += ' ';
                    break;
                case SHIP:
                    i = grid.FindShip(row, column);
                    if (i >= 0) {
                        grid.GetShip(i, ship);
                        line += ship.name[0];
                    }
                    else {
                        assert(false);
                    }
                    break;
                case MISS:
                    line += 'X';
                    break;
                case HIT:
                    line += '#';
                    break;
                case SUNK:
                    line += '@';
                    break;
                default:
                    assert(false);
                    break;
            }
        }
        cout << line << endl;
    }
}

