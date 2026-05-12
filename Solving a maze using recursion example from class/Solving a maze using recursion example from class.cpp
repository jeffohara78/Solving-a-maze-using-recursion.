// Solving a maze using recursion example from class.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>



using std::cin;
using std::cout;
using std::endl;



void printMaze(const char maze[][12], int xLoc, int yLoc);
int mazeTraverse(char maze[][12], int xLoc, int yLoc, int facing);



int main()
{
	char maze[12][12] =
	{ {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
	{ '#', '.', '.', '.', '#', '.', '.', '.', '.', '.', '.', '#'},
	{ '.', '.', '#', '.', '#', '.', '#', '#', '#', '#', '.', '#'},
	{ '#', '#', '#', '.', '#', '.', '.', '.', '.', '#', '.', '#'},
	{ '#', '.', '.', '.', '.', '#', '#', '#', '.', '#', '.', '.'},
	{ '#', '#', '#', '#', '.', '#', '.', '#', '.', '#', '.', '#'},
	{ '#', '.', '.', '#', '.', '#', '.', '#', '.', '#', '.', '#'},
	{ '#', '#', '.', '#', '.', '#', '.', '#', '.', '#', '.', '#'},
	{ '#', '.', '.', '.', '.', '.', '.', '.', '.', '#', '.', '#'},
	{ '#', '#', '#', '#', '#', '#', '.', '#', '#', '#', '.', '#'},
	{ '#', '.', '.', '.', '.', '.', '.', '#', '.', '.', '.', '#'},
	{ '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'} };
	
	
	int success = 0;



	success = mazeTraverse(maze, 2, 0, 1); // Call function to move through the maze, assign returned value to success.



	if (success == 1) // If success is equal to 1...
		cout << "Congratulations! The maze has been solved.\n"; // ...output congratulations...
	else // ...else...
		cout << "Unfortunately the maze has not been solved correctly.\n"; // ...output failed message.



	return 0; // End program.
}



// print the current state of the maze
void printMaze(const char maze[][12], int xLoc, int yLoc)
{
	// nested for loops to iterate through maze
	for (int x = 0; x < 12; ++x)
	{
		for (int y = 0; y < 12; ++y)
			if ((x == xLoc) && (y == yLoc))
				cout << 'X' << ' ';
			else
				cout << maze[x][y] << ' ';



		cout << '\n';
	} // end for



	cout << "\nHit return to see next move\n";
	cin.get();
} // end function printMaze



// Traverse through the maze one square at a time
int mazeTraverse(char maze[][12], int xLoc, int yLoc, int facing)
{
	int success = 0;



	maze[xLoc][yLoc] = '*'; // Mark current location in the maze.



	printMaze(maze, xLoc, yLoc); // Call function to display maze with current location marked.



	while (success == 0) // While success is equal to 0...
	{
		if ((xLoc == 4) && (yLoc == 11)) // If current location is the exit of the maze...
		{
			success = 1; // ...set success to 1.
		}
		else if (facing == 0) // Else if facing up...
		{
			if (maze[xLoc][yLoc + 1] == '.') // ...check square to the right for valid move...
			{
				success = mazeTraverse(maze, xLoc, yLoc + 1, 1); // Move to the right.
			}
			else if (maze[xLoc - 1][yLoc] == '.') // ...check square above for valid move...
			{
				success = mazeTraverse(maze, xLoc - 1, yLoc, 0); // Move up.
			}
			else if (maze[xLoc][yLoc - 1] == '.') // ...check square to the left for valid move...
			{
				success = mazeTraverse(maze, xLoc, yLoc - 1, 3); // Move to the left.
			}
			else // If nowhere to go...
				return 0; // ...close recursion to the previous junction.
		}
		else if (facing == 1) // If facing right...
		{
			if (maze[xLoc + 1][yLoc] == '.') // ...check square below for valid move...
			{
				success = mazeTraverse(maze, xLoc + 1, yLoc, 2); // Move down.
			}
			else if (maze[xLoc][yLoc + 1] == '.') // ...check square to the right for valid move...
			{
				success = mazeTraverse(maze, xLoc, yLoc + 1, 1); // Move right.
			}
			else if (maze[xLoc - 1][yLoc] == '.') // ...check square above for valid move...
			{
				success = mazeTraverse(maze, xLoc - 1, yLoc, 0); // Move up.
			}
			else // If nowhere to go...
				return 0; // ...close recursion to the previous junction.
		}
		else if (facing == 2) // If facing down...
		{
			if (maze[xLoc][yLoc - 1] == '.') // ...check square to the left for valid move...
			{
				success = mazeTraverse(maze, xLoc, yLoc - 1, 3); // Move to the left.
			}
			else if (maze[xLoc + 1][yLoc] == '.') // ...check square below for valid move...
			{
				success = mazeTraverse(maze, xLoc + 1, yLoc, 2); // Move down.
			}
			else if (maze[xLoc][yLoc + 1] == '.') // ...check square to the right for valid move...
			{
				success = mazeTraverse(maze, xLoc, yLoc + 1, 1); // Move to the right.
			}
			else // If nowhere to go...
				return 0; // ...close recursion to the previous junction.
		}
		else if (facing == 3) // If facing left...
		{
			if (maze[xLoc - 1][yLoc] == '.') // ...check square above for valid move...
			{
				success = mazeTraverse(maze, xLoc - 1, yLoc, 0); // Move up.
			}
			else if (maze[xLoc][yLoc - 1] == '.') // ...check square to the left for valid move...
			{
				success = mazeTraverse(maze, xLoc, yLoc - 1, 3); // Move to the left.
			}
			else if (maze[xLoc + 1][yLoc] == '.') // ...check square below for valid move...
			{
				success = mazeTraverse(maze, xLoc + 1, yLoc, 2); // Move down.
			}
			else // If nowhere to go...
				return 0; // ...close recursion to the previous junction.
		}
	} // ...end while loop.



	return success; // Return value of success.
}