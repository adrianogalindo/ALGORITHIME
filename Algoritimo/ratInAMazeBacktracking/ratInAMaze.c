/* C/C++ program to solve Rat in a Maze problem using 
   backtracking */
#include <stdio.h> 
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

  
// Maze size 
#define N 8
#define true 1
#define false 0  
#define SOURIS "🐭"
#define MUR "███" //▌  ▎▏█
#define FROMAGE "🧀"
  
void printMazeWonderfully(int maze[N][N], int x, int y) 
{ 
    printf("\n\n");;
    printf("████████████████████████\n");
    for (int i = 0; i < N; i++) 
    { 
        for (int j = 0; j < N; j++) 
        {   

            if (maze[i][j] == 6)
                printf("%s", SOURIS);
            else if(maze[i][j] == 0)
                printf("%s",MUR); 
            else if(maze[i][j] == 1)
                printf("   ");
            else if (maze[i][j] == 5)
                printf("%s", FROMAGE); 
        }
        printf("\n");
    } 
    printf("████████████████████████\n");
            printf("\n\n");

} 
  
/* A utility function to check if x,y is valid index for N*N maze */
int isSafe(int maze[N][N], int x, int y) 
{ 
    // if (x,y outside maze) return false 
    if(x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1)
        return true; 
    return false; 
} 
 
/* A recursive utility function to solve Maze problem */
int solveMazeUtil(int maze[N][N], int x, int y) 
{ 
    // if (x,y is goal) return true 
    if(x == N-1 && y == N-1) 
    { 
        maze[x][y] = 5;
        printMazeWonderfully(maze, x, y);
        return true; 
    } 
  
    // Check if maze[x][y] is valid 
    if(isSafe(maze, x, y) == true) 
    { 
        // mark x,y as part of solution path 
        maze[x][y] = 6; 
          printMazeWonderfully(maze, x, y);
          sleep(1);
          //system("clear");
        /* Move forward in x direction */
        if ((y + 1 >= 0) && solveMazeUtil(maze, x, y+1) == true) 
            return true; 
  
        /* If moving in x direction doesn't give solution then 
           Move down in y direction  */
        if ((x + 1 >= 0) && solveMazeUtil(maze, x+1, y) == true) 
            return true;

        /* If moving in x, y+1 direction doesn't give solution then 
           Move down in y-1 direction  */
        if ((y - 1 >= 0) && solveMazeUtil(maze, x, y-1) == true) 
            return true; 

        /* If moving in x, y-1 direction doesn't give solution then 
           Move down in x-1 direction  */
        if ((x - 1 >= 0) && solveMazeUtil(maze, x-1, y) == true) 
            return true; 
  
        /* If none of the above movements work then BACKTRACK:  
            unmark x,y as part of solution path */
        
        maze[x][y] = 6;

        return false; 
    }    
  
    return false; 
} 





  
// driver program to test above function 
int main() 
{ 

        int maze[N][N]  =  {{1, 1, 0, 1, 1, 1, 1, 1}, 
        			    	{1, 0, 0, 1, 0, 1, 0, 1},  
        					{1, 1, 1, 1, 0, 1, 1, 1}, 
        					{0, 0, 0, 1, 1, 1, 0, 0},
        					{0, 0, 0, 1, 0, 0, 0, 0},
        					{1, 1, 1, 1, 0, 0, 0, 0},
        					{0, 0, 1, 0, 1, 1, 1, 0},
        					{0, 0, 1, 1, 1, 0, 1, 1}};
  
    solveMazeUtil(maze, 0, 0);
                printf("%s\n", "Parabéns!!!!" ); 
    return 0; 
} 