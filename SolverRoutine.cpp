//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
   //Adds Pre-created Libraries to the Code

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
   //Initialising Functions and Global Variables.

int Dec2Bin(int Dec);                         //initialising decimal to binary function

int **MazeArray;                              //initialising variable for maze size using a double pointer
int a, b, c, d, f;
int success = 0;
int i, j;
int numberOfSteps = 0;
int shortestSteps = 0;
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//

int main(int argc, char** argv)
//int main()
{
	//command prompt.

	char* displayMaze = 0;
	char* mazeFile = 0;
	char* outputFile = 0;

	//printf("Number of arguments: %d\n", argc);

	//for (int i = 0; i < argc; i++) 
	//{ 
	//  printf("arg[%d] = %s\n", i, argv[i]); 
	//}

	if (argc == 4)
	{
		  displayMaze = *argv[1];
	      fin = argv[2];
	      outputFile = argv[3];
	}

	else if (argc == 3)
	{
	      fin = argv[2];
	      outputFile = argv[3];
	}
	else
	{
			printf_s("Incorrect Number of Input Arguments! \n");
	}

	//if (argv[2])      //check if .txt file
	//{
	//	printf_s("Error: Input File Must Be of '.txt' Format! \n");
	//}

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
	//Load File In.

	FILE *fin;

	fin = fopen("smallmaze(1).txt", "rt");

	if (fin == NULL)
	{
		printf_s("File has not successfully loaded \n");
		perror("Error: \n ");
	}
	else
	{
		printf_s("File has successfully loaded \n");
	}

	//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
		//Retrieve Data From Input File.
		//Dynamically Allocating The 2D Malloc Function.

	int numberOfRows, numberOfCols, startRow, startCol, endRow, endCol;
	fscanf_s(fin, "%d %d %d %d %d %d", &numberOfRows, &numberOfCols, &startRow, &startCol, &endRow, &endCol);           //retrieves data from the input file. decimal format is used along with ampersands to allocate the correct data to the variable
	printf_s("\n numberOfRows = %d \n numberOfCols = %d \n startPosition = (%d, %d) \n endPosition = (%d, %d) \n\n ", numberOfRows, numberOfCols, startRow, startCol, endRow, endCol);    //displays the data read from the file for the user
                                                                                                                       
                                                                                                                       //allows for different sized mazes to be automatically entered and data input to be adjusted accordingly
	MazeArray = (int **)malloc(numberOfRows * sizeof(int));                                                            //places the row data from the file in to memory, space taken up is remebered as the number of rows
	for (int i = 0; i < numberOfRows; i++)                                                                             
	{
		MazeArray[i] = (int *)malloc(numberOfCols * sizeof(int));                                                      //places the column data from the file in to memory, space taken up is remebered as the number of columns
	}
	if (MazeArray)                                                                                                     //allocates memory for the array
	{
		for (int i = 0; i < numberOfRows; i++)
		{
			for (int j = 0; j < numberOfCols; j++)                                                                     //safety buffer so that the array created is not bigger than the number of rows and columns calculated in malloc
			{

				fscanf_s(fin, "%d", &f);                                                                               //reads the input file size as a decimal integer
				MazeArray[i][j] = f;                                                                                   //creates an array of the size calculated using the malloc
			}
		}
	}
	else
	{
		printf_s("Array not created \n");                                                                               //error message for the user if the array was not created
	}
	fclose(fin);                                                                                                        //closes file and deletes what was allocated in memory, size of what was allocated stays therfore we know the size of array

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
	//Display Maze Data.

	for (int i = 0; i < numberOfRows; i++)
	{
		for (int j = 0; j < numberOfCols; j++)
		{
			fscanf_s(fin, "%d", &MazeArray[i][j]);
			printf_s("\t%d", MazeArray[i][j]);
		}
		printf_s("\n");
	}
	printf_s("\n");
	printf_s("\n");

	//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
		 //Displaying The Maze.

if (displayMaze == '-d')                                                          //check if maze needs displayed, if the user has requested this using command prompt
{
	for (int j = 0; j < numberOfCols; j++)                                        //ensures displayed maze does not have more columns than maze from file
	{
		if (j < numberOfCols)                                                     //default condition for the top edge wall to always be drawn
		{
			printf_s(" _");                                                       //draw horizontal wall for that co-ordinate
		}
	}
	printf_s("\n");                                                               //leave a line before drawing next horizontal line so that space is left between walls

	for (int i = 0; i < (numberOfRows); i++)                                     // ensures displayed maze does not have more columns than maze from file, moves along each row
	{
		printf_s("|", MazeArray[i][j]);                                           //default condition to place outside left wall for each maze

		for (int j = 0; j < numberOfCols; j++)                                    //moves along each column
		{
			Dec2Bin(MazeArray[i][j]);                                              //call decimal to binary function for e
			if (c == 1)
			{
				printf_s("_", MazeArray[i][j]);
			}
			else
			{
				printf_s(" ");
			}

			if (d == 1)
			{
				printf_s("|", MazeArray[i][j]);
			}
			else
			{
				printf_s(" ");
			}
		}
		printf_s("\n");
	}
	printf_s("\n");
}
	 	else
	 	{
	 		printf_s("To Display Maze Type '-d'! \n");
	 	}

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
	//Maze Solver Algorithm.

		int facing = 0, x = startRow, z = startCol, ShortestPath = 0; // k = 0, l = 0, m = 0;
	    static char MazePath[]="";

	while (success == 0 )	// While success is equal to 0.
	{
		if (x == endRow && z == endCol)	// If current location is the exit of the maze.
		{
			success = 1;	//set success to 1.
			printf_s("Maze Solved You Rock \n");
	        printf_s("The Maze Took %d Steps To Be Completed \n", numberOfSteps);
			printf_s("The Path Of The Shortest Route is: %s \n", MazePath);
			shortestSteps = strlen(MazePath);
			printf_s("Shortest Number Of Steps From String = %d \n", shortestSteps);
			printf_s("Shortest Number Of Steps = %d \n", ShortestPath);
		}

        else if (x < 0 || z < 0)
			{
				printf_s("Error has occurred maze position is out of maze size!! Maze cannot be solved, Please Restart");
				success = 2;
			}

		else
		{
			Dec2Bin(MazeArray[z][x]);                                                                //if not at the end position go through the maze in steps starting from the start position

			if (facing == 0)	// if facing up.
			{
				if (d == 0)	//check square to the right for valid move.
				{
					x++;	// Move to the right.
					facing = 1;
					numberOfSteps = numberOfSteps + 1;
					ShortestPath++;
					char MazeRight[] = "R";
					strcat(MazePath, MazeRight);
					if (MazePath[ShortestPath - 2] == 'L')
					{
						MazePath[ShortestPath - 1] = 0;
						MazePath[ShortestPath - 2] = 0;
						ShortestPath = ShortestPath - 2;
					}
				}
				else if (a == 0)	//check square above for valid move.
				{
					z--;	// Move up.
					facing = 0;
					numberOfSteps = numberOfSteps + 1;
					ShortestPath++;
					char MazeUp[] = "U";                                                               //PROBLEM STARTS HERE!
					strcat(MazePath, MazeUp);                                                        //when back tracking from it goes to 4,4 goes to 4,3 and 4,2 fine then completes this else if, once it leaves this the z is set to 0 somehow then next move its set to over 20,000
					if (MazePath[ShortestPath - 2] == 'D')                                         //not entering this!!!!!!!!
					{
						MazePath[ShortestPath - 1] = 0;
						MazePath[ShortestPath - 2] = 0;
						ShortestPath = ShortestPath - 2;
					}
				}
				else if (b == 0)	//check square to the left for valid move.
				{
					x--;	// Move to the left.
					facing = 3;
					numberOfSteps = numberOfSteps + 1;
					ShortestPath++;
					char MazeLeft[] = "L";
					strcat(MazePath, MazeLeft);
					if (MazePath[ShortestPath - 2] == 'R')
					{
						MazePath[ShortestPath - 1] = 0;
						MazePath[ShortestPath - 2] = 0;
						ShortestPath = ShortestPath - 2;
					}
				}
				else   // If nowhere to go.
				{
					facing = 2;
					//numberOfSteps = numberOfSteps - 1;
					//MazePath[numberOfSteps] = 0;
				}
			}

			else if (facing == 1)	// If facing right.
			{
				if (c == 0)	//check square below for valid move.
				{
					z++;	// Move down.
					facing = 2;
					numberOfSteps = numberOfSteps + 1;
					ShortestPath++;
					char MazeDown[] = "D";
					strcat(MazePath, MazeDown);
					if (MazePath[ShortestPath - 2] == 'U')
					{
						MazePath[ShortestPath - 1] = 0;
						MazePath[ShortestPath - 2] = 0;
						ShortestPath = ShortestPath - 2;
					}
				}
				else if (d == 0)	//check square to the right for valid move.
				{
					x++;	// Move right.
					facing = 1;
					numberOfSteps = numberOfSteps + 1;
					ShortestPath++;
					char MazeRight[] = "R";
					strcat(MazePath, MazeRight);
					if (MazePath[ShortestPath - 2] == 'L')
					{
						MazePath[ShortestPath - 1] = 0;
						MazePath[ShortestPath - 2] = 0;
						ShortestPath = ShortestPath - 2;
					}
				}
				else if (a == 0)	//check square above for valid move.
				{
					z--;	// Move up.
					facing = 0;
					numberOfSteps = numberOfSteps + 1;
					ShortestPath++;
					char MazeUp[] = "U";
					strcat(MazePath, MazeUp);
					if (MazePath[ShortestPath - 2] == 'D')
					{
						MazePath[ShortestPath - 1] = 0;
						MazePath[ShortestPath - 2] = 0;
						ShortestPath = ShortestPath - 2;
					}
				}
				else	// If nowhere to go.
				{
					facing = 3;
					//numberOfSteps = numberOfSteps - 1;
					//MazePath[numberOfSteps] = 0;
				}
			}

			else if (facing == 2)	// If facing down.
			{
				if (b == 0)	//check square to the left for valid move.
				{
					x--;	// Move to the left.
					facing = 3;
					numberOfSteps = numberOfSteps + 1;
					ShortestPath++;
					char MazeLeft[] = "L";
					strcat(MazePath, MazeLeft);
					if (MazePath[ShortestPath - 2] == 'R')
					{
						MazePath[ShortestPath - 1] = 0;
						MazePath[ShortestPath - 2] = 0;
						ShortestPath = ShortestPath - 2;
					}
				}

				else if (c == 0)	//check square below for valid move.
				{
					z++;	// Move down.
					facing = 2;
					numberOfSteps = numberOfSteps + 1;
					ShortestPath++;
					char MazeDown[] = "D";
					strcat(MazePath, MazeDown);
					if (MazePath[ShortestPath - 2] == 'U')
					{
						MazePath[ShortestPath - 1] = 0;
						MazePath[ShortestPath - 2] = 0;
						ShortestPath = ShortestPath - 2;
					}
				}

				else if (d == 0)	//check square to the right for valid move.
				{
					x++;	// Move to the right.
					facing = 1;
					numberOfSteps = numberOfSteps + 1;
					ShortestPath++;
					char MazeRight[] = "R";
					strcat(MazePath, MazeRight);
					if (MazePath[ShortestPath - 2] == 'L')
					{
						MazePath[ShortestPath - 1] = 0;
						MazePath[ShortestPath - 2] = 0;
						ShortestPath = ShortestPath - 2;
					}
				}

				else	// If nowhere to go.
				{
					facing = 0;
					//numberOfSteps = numberOfSteps - 1;
					//MazePath[numberOfSteps] = 0;
				}
			}

			else if (facing == 3)	// If facing left.
			{
				if (a == 0)	// check square above for valid move.
				{
					z--;	// Move up.
					facing = 0;
					numberOfSteps = numberOfSteps + 1;
					ShortestPath++;
					char MazeUp[] = "U";
					strcat(MazePath, MazeUp);
					if (MazePath[ShortestPath - 2] == 'D')
					{
						MazePath[ShortestPath - 1] = 0;
						MazePath[ShortestPath - 2] = 0;
						ShortestPath = ShortestPath - 2;
					}
				}
				else if (b == 0)	//check square to the left for valid move.
				{
					x--;	// Move to the left.
					facing = 3;
					numberOfSteps = numberOfSteps + 1;
					ShortestPath++;
					char MazeLeft[] = "L";
					strcat(MazePath, MazeLeft);
					if (MazePath[ShortestPath - 2] == 'R')
					{
						MazePath[ShortestPath - 1] = 0;
						MazePath[ShortestPath - 2] = 0;
						ShortestPath = ShortestPath - 2;
					}
				}
				else if (c == 0)	//check square below for valid move.
				{
					z++;	// Move down.
					facing = 2;
					numberOfSteps = numberOfSteps + 1;   //count for total number of correct moves to solve maze
					ShortestPath++;
					char MazeDown[] = "D";               //string to display the correct maze path direction
					strcat(MazePath, MazeDown);          //joins the newest path direction that has been carried out to the previous path directions
					if (MazePath[ShortestPath - 2] == 'U')
					{
						MazePath[ShortestPath - 1] = 0;
						MazePath[ShortestPath - 2] = 0;
						ShortestPath = ShortestPath - 2;
					}
				}
				else	// If nowhere to go.
				{
					facing = 1;
					//numberOfSteps = numberOfSteps - 1;       //subtracts a move from number of steps due to incorrect move being madde
					//MazePath[numberOfSteps] = 0;             //takes previous move direction and overwrites it to 0, due to incorrect move being carried out
				}
			}
		}
	}
	while (1);
}

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
    //Decimal To Binary Converter. 4 bits representing the walls from up and working anitclockwise

int Dec2Bin(int Dec)
{
	if (Dec - 8 < 0)
	{
		a = 0;
	}
	else
	{
		a = 1;
		Dec = Dec - 8;
	}

	if (Dec - 4 < 0)
	{
		b = 0;
	}
	else
	{
		b = 1;
		Dec = Dec - 4;
	}

	if (Dec - 2 < 0)
	{
		c = 0;
	}
	else
	{
		c = 1;
		Dec = Dec - 2;
	}

	if (Dec - 1 < 0)
	{
		d = 0;
	}
	else
	{
		d = 1;
		Dec = Dec - 1;
	}

	/*printf_s("\t %d %d %d %d", a, b, c, d );
	printf_s("\n");*/

	return(0);
}



//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
// different methods tried, commented incase they need used in future to parts that aren't working 100%

//int facing at 0, success, 
// if moved up facing = 0 , i was decreased
// if moved left facing = 1,  j increased
// if moved down facing = 2, i increased
// if moved right facing = 3, j decreased

// if facing up
// check right, up, left
// if right increase j if up decrease i if left decrease j
//none return
//check at end point display something

//if facing left
//check up left down
// if up decrease i if left decrease j if down increase i
//none return
//check at end point display something

//if facing down
//check left down right
// if left decrease j if down increase i if right increase j
//none return
//check at end point something

//if facing right
// up right down
// if up decrease i if right increase j if down increase i
//none return
//check at end point display something


     //parts left to do, completed parts have n *

//command prompt to run
//display maze due to command prompt, writing to file and displaying

//loaded file error checks  --->  file input doesnt contain all same numbers, files input doesnt contain characters, file input doesnt contain values greater than 15 or less than 0, file input is a text file
//makesure no gaps around edges of maze ---> at sides check binary letter and print error to say incomplete or wrong maze, that the maze is actually 5x5 etc

//smaller test input files created* and run ---> 3x3, 7x7, 10x10 (using random number generator online? or create one?)
//check x++ etc have correct comments/

//get 2D malloc working*
//display maze*
//path directions*
//shortest path directions and step number*
// note number of steps is wrong and maze path is wrong because when going backwards it only subtracts one in the else condition not the else if*


//ensure x or z doesnt go minus *
//number of steps in path*
//ask if wants maze displayed *
//default condition if value is zero keep going the way its facing, automatically does this*