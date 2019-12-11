// Title: Lab 5 - grid.cpp
//
// Purpose:  Convert the  Battleship "grid" ADT implemented in Lab 4 to
//           use a C++ class as well as firing functionality.
//
// Class: CSC 2430 Winter 2020
// Author: <please fill in>>
//

#include <iostream>
#include <assert.h>
#include "Grid.h"

// Class constructor
//  - calls Init to ensure the class
//

//***Add your implementation of the constructor here

//
// Public member functions
//

// Read the ship configuration for a grid from a text file stream.  Here's an example of
//      how the file is structured:
//          5
//          Submarine
//          3 1 0 0
//          Battleship
//          4 0 9 0
//          Destroyer
//          3 0 3 3
//          PatrolBoat
//          2 1 4 4
//          Carrier
//          5 1 4 5
//      where the first line is the count of ships.  Two lines are used to specify the
//      configuration of a ship.  The first line gives the ship's name.  The second line
//      contains four numbers specifying size, isVertical, startRow, and startColumn
// Parameters:
//      file - an open file stream
// Returns:
//      succcess/failure
// Possible Errors:
//     File read error
//     # of ships out of range
//     Value of isVertical, startRow or startColumn out of range
//     Ship placement would extend beyong grid
//     Ship placement would overlap ship that has already been placed

//***Add your implementation of LoadShips here

// Save the ship configuration for a grid to a text file stream.  For the file format
//      Refer to the header comment for Load.
// Parameters:
//      file - an open file stream
// Returns:
//      succcess/failure
// Possible Errors:
//     File write error

//***Add your implementation of SaveShips here

// Randomly place the indicated ships on an empty grid.
//      The grid is initialized and then random values of isVertical, startRow, and startColumn
//      are generated to place the ships.  If the random values would result in a placement that
//      does not fit within the grid or which overlaps an existing ship placement, new random
//      values will generated.  Multiple of attempts for each ship will be made until each of the
//      ships can be placed on the grid without extending beyond the grid boundaries or overlapping.
// Parameters:
//      ship - an array of ship structs with their name and size fields filled in -- other
//             fields of the ship structs are ignored
//      countShips - the number of ships in the array -- must not exceed SHIPS_MAX
// Returns:
//      nothing
// Possible Errors:
//      none

//***Add your implementation of RandomlyPlaceShips here

// Attempt to place a ship on the grid.  Checks that the placement would not cause
//      the ship to extend outside the grid or overlap another ship that has already
//      been placed on the grid.
// Parameters:
//      name - name of ship to be placed
//      size - number of squares the ship covers
//      isVertical - whether the ship should be placed vertically or horizontally
//      startRow - row of uppermost square (if isVertical) or leftmost square (if !isVertical)
//      startColumn - column of uppermost square (if isVertical) or leftmost square (if !isVertical)
// Returns:
//      true if the ship can be placed, false if it would extend outside grid or overlap another ship
// Possible Errors:
//      Too many ships deployed
//      Size or position of ship is not reasonable
//      Ship placement would extend outside gird
//      Ship placement would overlap another ship

//***Add your implementation of AddShip here


// Returns the number of ships that have been sunk
// Parameters:
//      none
// Returns:
//      number of ships
// Possible Errors:
//      none

//***Add your implementation of GetShipsSunk here


// Returns the number of ships placed on the grid
// Parameters:
//      none
// Returns:
//      number of ships
// Possible Errors:
//      none

//***Add your implementation of GetShipsDeployed here


// Retrieves information about the i-th ship.  Meant to used
// in a loop to fetch information about each the ships
// Parameters:
//      i - index of ship that ranges between 0 to number of ships deployed -1
//      ship - struct to be filled with information about ship
// Returns:
//      nothing
// Possible Errors:
//      asserts that index is within range

//***Add your implementation of GetShip here


// Determines if there is a ship covering the specified square.  If found, returns
// the configuration index of the ship
// Parameters:
//      row - row of the square
//      column - column of the square
// Returns:
//      < 0 if not found, otherwise returns the index of the ship
// Possible Errors:
//      none

//***Add your implementation of FindShip here

// Gets the status of the specified square
// Parameters:
//      row - row of the square
//      column - column of the square
// Returns:
//      status of the square
// Possible Errors:
//      asserts that row nad column are within range

//***Add your implementation of GetSquareStatus here

// Fires a shot on the specified square.  Updates the two dimensional array and determines the outcome
// Parameters:
//      row - row of the square
//      column - column of the square
//      outcome - upon return this is set equal to the outcome
// Returns:
//      true if shot lands within grid, false otherwise
// Possible Errors:
//      row or column is out of range

//
// Private member functions
//

// Initialize the grid struct
//      Set counts of deployed and sunk ships to zero
//      Set the SquareStatus of all grid squares equal to Water
// Parameters:
//      none
// Returns:
//      nothing
// Possible Errors:
//      none

//***Add your implementation of Init here

