# Maze-Solver
University of Bath EEE 2nd Year Structured Programming Module.

The final solution file solved the small and medium mazes. However, not all of the large mazes could be solved as the code got lost within itself.

The Challenge
The program should perform the following tasks:
1. Read a maze from a file.
2. Work out a route from the start point to the end point of the maze.
3. If selected by the user, display the maze on the screen.
4. Write the solution to the maze to a file. 

The Maze File
1) The file that describes the maze is a text file. The file contains whitespace (space,
tab or newline) separated integers. The first three lines of the file contain two
integers each.
2) The first line gives the number of rows and columns (in that order) in the maze.
3) The second line gives the start location for the maze solver as a row number
followed by a column number. These values are zero based and location (0,0) in
the maze is the top left.
4) The third line gives the end location for the maze solver in the same format as the
start point.
5) All subsequent lines (one for each row as stated in the first line) contain a set of
integers (one for each column stated in the first line). The integer is a sum of
variables that indicate the presence or absence of a wall:
 If the location has a wall above it the variable has 8 added to it.
 If the location has a wall to the left of it the variable has 4 added to it.
 If the location has a wall below it the variable has 2 added to it.
 If the location has a wall to the right of it the variable has 1 added to it.

The Solution file
Your program should output a text file with two lines:
 The first line should be the number of moves required to get from the start
location to the end location.
 The second line should be a list of moves that will trace a path from the start
position to the end position without going through any walls. Each move is
represented by a single letter U, D, L or R for Up, Down, Left or Right
respectively.

Files contained are:
1. Maze Solver File
2. Small maze test file
3. Medium maze test file
4. Large maze test file
