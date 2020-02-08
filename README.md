# LAB 5 - Battleship Game, Part 2 - Firing Shots
## Goal
Continue developing the code infrastructure needed for the Battleship game.  You will convert your _Grid_ ADT to a C++ class, and then extend its functionally by adding a method to fire a shot.  You will also implement a class called _CpuLogic_ that determines where your CPU game opponent should fire its next shot.  This lab will allow you to practice implementing C++ classes.

## Sample Run

In this lab we will continue to test game component functionality using a command line user interface.  The user is first prompted for a ship configuration fire.  The ship configuration will be loaded into a _Grid_, and then the user is given the choice of firing shots manually or algorithmically. In the finished game, manual firing is what you as the user will do, algorithmic firing is what your CPU opponent will use.

In the runs that we display below, we  use a file that contains only two ships:

![twoShips.txt](/images/image1.png)

Here’s the start of one run where we chose to fire manually.  On our first shot, we hit a part of the ship “Beta” – note the “Outcome” that is printed.

![SHIP_HIT](/images/image2.png)

If we were so silly as to fire on this square or any other square we’ve fired at before, this is the “Outcome” you get:

![SHOT_HERE_BEFORE](/images/image3.png)

When we hit the last square of a ship, the “Outcome” is “SHIP_SUNK”

![SHIP_SUNK](/images/image4.png)

On the other hand, if we whiff a shot and don’t hit anything, we get the “Outcome” “SHOT_MISSED”:

![SHOT_MISSED](/images/image5.png)

There is one other possible “Outcome”, that’s when we sink the last ship!

![CAME_WON](/images/image6.png)

These five different “Outcomes” correspond to enum values defined in **grid.h**.

What about algorithmic firing?  Here’s start of a run where algorithmic firing was chosen:

![ALGORITHMIC FIRING](/images/image7.png)

There’s not much new to see here.  The more interesting story is what is happening in the code.  At the start of the main program, an instance for the _CpuLogic_ class is created to serve as an oracle to tell it which square to fire on.  This _CpuLogic_ object purposely doesn’t have any knowledge of the grid ship configuration so it can’t “cheat.”

Here’s the code sequence that is used for algorithmic firing:

1)	The user interface calls the _DetermineShot_ method of the _CpuLogic_ object to determine which square to fire on. 
2)	The user interface then calls the _FireShot_ method of the _Grid_ object to fire the shot.  The user interface receives an _Outcome_ value for the shot via a "call by reference" parameter.
3)	The user interface reports the _Outcome_ of the shot to the _CpuLogic_ object so the object can record this information and use it to make an informed decision on which square to fire on next.

The _CpuLogic_ object doesn’t know where the ships are, so it picks random squares to fire at.  It misses a lot – at least until it hits part of a ship.  

At minimum, your _CpuLogic_ class should pick random squares to fire on, but be smart enough not to fire on a square it has already fired at.  

The better _CpuLogic_ implementations (Hint: extra credit) will be smarter — when a part of a ship is hit, it will be able to quickly demolish the rest of the ship  like you would when you play Battleship.

## Files you are given
In this lab, you are given all the files you will need for your CLion project.  

* **CMakeLists.txt** - This contains the information necessary to build the project.  This file should not be modified.

*	**main.cpp** – This file contains the main routine which drives the command line user interface, and a very simple subfunction called _UserDetermineShot_.  This file has been completed for you and should not be modified.

*	**helperCode.h** – This file declares the function _PrintGrid_ which is implemented in **helperCode.cpp**.  This file has been completed for you and should not be modified.

*	**helperCode.cpp** – This file implements the useful function _PrintGrid_.  This file has been completed for you and should not be modified.

*	**grid.h** – This file contains the definition of the _Grid_ ADT as a C++ class.  This file has been completed for you and should not be modified.
.
*	**grid.cpp** – This is the file where you should place your implementation of the _Grid_ class. 
 
*	**cpuLogic.h** – This file contains the declaration of the public members of the _CpuLogic_ class.   The design of the private portion of the class has been left to you.  Note that you are not allowed to modify the public portion of the class declaration – only make modifications to the private portion.

*	**cpuLogic.cpp** – This is the file where you should place your implementation of the _CpuLogic_ class. 

##	The _Grid_ Class

Here’s the definition of the _Grid_ class:

```
class Grid {
public:
    Grid();

    bool LoadShips(ifstream& file);
    bool SaveShips(ofstream& file);

    void RandomlyPlaceShips(const Ship ships[], int shipCount);

    bool AddShip(const string& name, int size, bool isVertical, int startRow, int startColumn);
    int GetShipsSunk() const;
    int GetShipsDeployed() const;
    void GetShip(int i, Ship& ship) const;
    int FindShip(int row, int column) const;

    bool FireShot(int row, int column, Outcome& outcome);

    SquareStatus GetSquareStatus(int row, int column) const;

private:
    void Init();

    Ship _ships[SHIPS_MAX];
    int _shipsDeployed;
    int _shipsSunk;
    SquareStatus _squareStatus[COUNT_ROWS][COUNT_COLUMNS];
};
```
As you can see:

*	The public methods of the _Grid_ class include all of the ADT interface functions you implemented in Lab 4 except for Init().  A new method called _FireShot_ has been added.  The declarations of the methods that were part of the Lab 4 interface are the same except the _Grid_ parameter no longer appears.
* The Init method is the only private method for this class.  It's been declared private because there is no reason for it to be called by code that runs outside of the _Grid_ object.  It is called internally by the constructor and by LoadShips.
*	The data portion of the _Grid_ class is the same the _Grid_ struct used in Lab 4, except that we have prepended _ before each of the member names to indicate (for documentation purposes – C++ doesn’t care) that they are private data members.

##	The _CpuLogic_ Class

Here’s the definition of the _CpuLogic_ class:

```
class CpuLogic {
public:
    CpuLogic();

    void DetermineShot(int &row, int& column) const;
    void ReportOutcome(int row, int column, Outcome outcome);

private:
    //
    //  Add any private members you need here to implement this class
    //
};
```

As described earlier, the user interface calls _DetermineShot_ to find out what shot to fire.  Then, after the user interface calls _FireShot_ on the _Grid_ object, the user interface turns around and reports the _Outcome_ to the _CpuLogic_ object by calling the _ReportOutcome_ method.

## Recommended implementation order

Here’s a recommendation set of steps to doing this assignment:

1.	Start by putting your name in the file headers for **grid.cpp*, **cpuLogic.h**, and **cpuLogic.cpp** as author or co-author.

2.	Implement the _Grid_ constructor and the _Grid_ class methods that correspond to the Lab 4 interface functions.  The function header comments have already been placed in the file **grid.cpp** for you.  You can copy in the corresponding Lab 4 implementation under each function header comment and then fix the syntax.  No algorithmic changes are necessary here.  Once you get the hang of it, this should go quickly.  Make sure everything compiles before you go further.

3.	Implement the _FireShot_ method of the _Grid_ class.  This will take more thinking.

  *	Check the row and column parameters to see they are in range, if not return _false_.
  * Check the current status of the square. 
    *	 If the square has been fired at previously, you return _true_ with the _Outcome_ _SHOT_HERE_BEFORE_
    *	 If the square is open water, mark the square as _MISS_ in *_squareStatus* and return _true_ with the _Outcome_ _SHOT_MISSED_
    *	Otherwise you will need to get the ship that sits on the square and increase the ship's count of hits
     *	If there are still parts of the ship that haven’t been hit, mark the square as _HIT_, and return _true_ with the _Outcome_ _SHIP_HIT_
     *	Otherwise, mark all squares the ship occupies as _SUNK_.  
       * If not all ships have been sunk, return true and report _SHIP_SUNK_
       * 	Otherwise report _GAME_WON_.

4.	Stub out the two _CpuLogic_ methods enough so that the program can be compiled, and you can test manual firing.

5.	After you have tested manual firing thoroughly, go on to implement the _CpuLogic_ class.  As mentioned earlier, *DetermineShot* should fire on random squares.  It should never suggest the same square twice.  In order to make sure that you don’t suggest the same square a second time, you will need to keep track of what squares have been fired at.  That’s going to mean you will have to declare member variable(s) in the private portion of the class.

6.	If you have time after everything is working, see if you can get some extra credit by making the _CpuLogic_ smarter so once it hits a ship, it focuses on demolishing it rather than continuing to fire randomly.

## Testing

Make sure you test your code thoroughly.  
* For starters, make sure that you test all the possible outcomes of manual firing shown in the screen shots.  You should also verify it works correctly with both horizontal and vertical ship orientations and ships longer than two squares.
* Test algorithmic firing.  Ensure that you do not fire on the same square twice, and that you are using the random number generator correctly.

The test files referenced by the rubric have been included in this repo: twoShips.txt, threeShips.txt, fourShips.txt, and fiveShips.txt.

## Style

Your program needs to be orderly and readable.  If you are working a development team and don’t write clean looking code, you will be unpopular among your colleagues and may not work on that team very long.  Because of this your program will be graded on style as well as correctness.  Please refer to the style guidelines discussed in class and in reading assignments concerning

  *	Indention of code
  *	Consistent use of {}, preferably Stroustrup style
  *	Meaningful names of identifiers
  *	Naming conventions for identifiers (camelCase for variables, CamelCase for function names. First word of a function name typically should be a verb.)
  *	No use of global variables. Global variables sometimes are appropriate, but not in the assignments we will be giving this quarter.
  *	Making sure *struct* and object parameters are passed by reference (and declared const if appropriate)
 
## Documentation
    
At the start of your file you should have a header comment that gives the title of the assignment, the purpose, and your name.  Here is an example (from Lab 1) of what that could look like:

      ```
      /*
          Title:      Lab 1 – evalSteps.cpp
          Purpose:    implement the GetEvalSteps functions called by the main program to generate the evaluation
                      steps for an expression passed in as a parameter.
          Author:     Sally Johnson
          Date:       January 6, 2020
      */
      ```
Each subordinate function should also start with a header that describes what it does, it’s parameters, what it returns, and how errors are handled.  Here is an example (again from Lab 1):

    ```
    // Produce a string of evaluation steps for simplifying an expression
    // For example:
    //      if “2+3*4-5”  is passed to this function, the string “2+3*4-5 = 2+12-5\n        = 14-5\n        = 9”
    //      would be returned
    // Parameters:
    //      expression - an arithmetic expression
    // Returns:
    //      a string consisting of the evaluation steps needed to simplify the expression
    // Possible Error Conditions: 
    //      If evaluating the expression causes division by zero, this function crash.
    //      If evaluating the expression causes an oveflow, the results may not be reliable.
    ```

You should include additional comments in your code to describe what you are doing.   If it is hard to understand what a variable is for, add a comment after it.   It possible, though, to put in too many comments, so be judicious and make sure you have time left to do well in your other classes when it comes to commenting.

## Submitting your code
Your solution should be contained within files that were provided.  You MUST NOT modify **CMakeFiles.txt**, **main.cpp**, **helperCode.h**, **helperCode.cpp**, or **grid.h**.  Do not modify the public interface of the _CpuLogic_ class in **cpuLogic.h**. 

Make sure you test your code thoroughly.  We will try your code with our own test files, and we will programmatically test your _Grid_ and _CpuLogic_ classes with our own test programs.  

Your code needs to be submitted through GitHub Classroom.  You will need to push your last version of your program before the lab deadline. As a good programming practice remember to commit frequently and to push every time you have a functioning version of your code.

## Grading
Correctness is essential.  Make sure your solution builds as described above and correctly handles the test cases displayed in the screen shot.  We will test on other input values as well. Your code must compile and should not have runtime errors (crash).

Even if your solution operates correctly, points will be taken off for:
- Not following the design described above
- Not adhering to style guidelines described above
- Using techniques not presented in class
- Programming error not caught by other testing
- Not following good programming practices

## Academic Integrity
This programming assignment is to be done on an individual basis. At the same time, it is understood that learning from your peers is valid and you are encouraged to talk among yourselves about programming in general and current assignments in particular.  Keep in mind, however, that each individual student must do the work in order to learn.  Hence, the following guidelines are established:
- Feel free to discuss any and all programming assignments but do not allow other students to look at or copy your code. Do not give any student an electronic or printed copy of any program you write for this class.
- Gaining the ability to properly analyze common programming errors is an important experience. Do not deprive a fellow student of his/her opportunity to practice problem solving: control the urge to show them what to do by writing the code for them.
- If you’ve given the assignment a fair effort and still need help, see the instructor or a lab assistant.
- **If there is any evidence that a program or other written assignment was copied from another student, neither student will receive any credit for it. This rule will be enforced.**
- Protect yourself: Handle throw-away program listings carefully, keep your repository private.

Refer to the ECS Department Policy on Academic Integrity that is included in the class syllabus.

## Grading Rubric Summary
The following aspects are going to be consider during grading. Make sure you comply with all of them.
- The program compiles (there will be no partial credit for programs that do not compile)
- Provides the correct output for the test cases
- Catches errors gracefully, the program does not crash on incorrect input
- The program outputs the information in the specified format
- The assignment follows all the instructions
- In general the program does not crash 
