
/* C/C++ program to solve Rat in a Maze problem using 
   backtracking */
#include<stdio.h> 
  
// Maze size 
#define N 5 
#define MUR "⬛"
#define CHEMIN "  "
#define SOURIS "🐭" 
#define FROMAGE "🧀"
#define TRUE 1
#define FALSE 0

/* A utility function to print solution matrix sol[N][N] */
void printSolution(int labyrinthe[N][N]) 
{ 
    for (int i = 0; i < N; i++) 
    { 
        for (int j = 0; j < N; j++) 
            printf(" %d ", labyrinthe[i][j]); 
        printf("\n"); 
    } 
} 

/* A utility function to check if x,y is valid index for N*N maze */
int cheminBon(int labyrinthe[N][N], int x, int y) 
{ 
    // if (x,y outside maze) return false 
    if(x >= 0 && x < N && y >= 0 && y < N && labyrinthe[x][y] == 1) 
        return TRUE; 
  
    return FALSE; 

}

/* A recursive utility function to solve Maze problem */
int solveMazeUtil(int labyrinthe[N][N], int x, int y, solution[N][N]) 
{ 
    // if (x,y is goal) return true 
    if(x == N-1 && y == N-1) 
    { 
        labyrinthe[x][y] = 2; 
        return TRUE; 
    } 
  
    // Check if labyrinthe[x][y] is valid 
    if(cheminBon(labyrinthe, x, y) == TRUE) 
    { 
        // mark x,y as part of solution path 
        labyrinthe[x][y] = 2; 

        /* If moving in [x][y] direction doesn't give solution then 
           Move down in x+1 direction  */
        if (solveMazeUtil(labyrinthe, x+1, y, solution) == TRUE) 
            return TRUE; 
  
        /* Move forward in y+1 direction */
        if (solveMazeUtil(labyrinthe, x, y+1, solution) == TRUE) 
            return TRUE; 
  
        /* If moving in y+1 direction doesn't give solution then 
           Move down in x-1 direction  */
        if (solveMazeUtil(labyrinthe, x-1, y, solution) == TRUE) 
            return TRUE; 

        /* If moving in x-1 direction doesn't give solution then 
           Move down in y-1 direction  */
        if (solveMazeUtil(labyrinthe, x, y-1, solution) == TRUE) 
            return TRUE; 
  
        /* If none of the above movements work then BACKTRACK:  
            unmark x,y as part of solution path */
        solution[x][y] = 0; 
        return FALSE; 
    }    
  
    return FALSE; 
}  

void solveMaze(int labyrinthe[N][N], int N)
{
	if (cheminBon(labyrinthe, 0, 0, N, "down")) {
		print(solution, N);
	}else{
		printSolution("NO PATH FOUND\n");
	}
		
}

// driver program to test above function 
int main() 
{ 

	int solution[N][N] = {{0, 0, 0, 0, 0}, 
     	 	 		 	  {0, 0, 0, 0, 0}, 
       					  {0, 0, 0, 0, 0}, 
         				  {0, 0, 0, 0, 0},
         				  {0, 0, 0, 0, 0}}; 

    int labyrinthe[N][N]  =  {{1, 0, 1, 1, 1}, 
        			    	  {1, 1, 1, 0, 1}, 
        					  {1, 0, 1, 0, 1}, 
        					  {1, 0, 1, 1, 1},
        					  {1, 1, 1, 0, 1}}; 


    // int labyrinthe[N][N]  =  {{SOURIS, MUR,    CHEMIN, CHEMIN,  CHEMIN}, 
    //     			    	  {CHEMIN, CHEMIN, CHEMIN, MUR,     CHEMIN}, 
    //     					  {CHEMIN, MUR,    CHEMIN, MUR,     CHEMIN}, 
    //     					  {CHEMIN, MUR,    CHEMIN, CHEMIN,  CHEMIN},
    //     					  {CHEMIN, CHEMIN, CHEMIN, MUR,    FROMAGE}}; 

	
	printSolution(labyrinthe);  
	printf("\n\n");      					  

  
    solveMazeUtil(labyrinthe, 0, 0, solution); 
    printSolution(solution);
    return 0; 
} 