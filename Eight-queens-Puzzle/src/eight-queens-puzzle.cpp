#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#define MAXN 20 // Maximum size for the chessboard

int q[MAXN]; // Array to store the positions of queens
int count = 0; // Counter for the number of solutions

// Function declarations
void displaySolution(int n);
bool canPlace(int i);
void solveQueens(int n);
void displaySignature(void);

int main()
{
    int n;

    // Display name and ID with color formatting in the terminal

    displaySignature();

    // Prompt the user to enter the number of queens
    printf("Enter the number of queens (e.g., 8 for an 8x8 chessboard): \033[91m");
    scanf("%d", &n);
    
    // Validate the input
    if (n <= 0 || n >= MAXN) {
        printf("Invalid number of queens. Please enter a value between 1 and %d.\n", MAXN - 1);
        return 1;
    }
    
    // Solve the n-queens problem
    solveQueens(n);
	printf("\n");
    return 0;
}

// Function to display a solution
void displaySolution(int n)
{
    printf("\033[0mSolution %d: \033[36m", ++count); // Increment the solution count and display it
    for (int i = 1; i <= n; i++)
        printf("(%d,%d) ", i, q[i]); // Display the position of each queen
    printf("\033[0m\n");
}

// Function to check if a queen can be placed in the current row
bool canPlace(int i)
{
    for (int j = 1; j < i; j++) { // Loop through all previously placed queens
        // Check if any queen is in the same column or diagonal
        if (q[j] == q[i] || abs(q[j] - q[i]) == abs(j - i))
            return false; // If so, return false (placement is not valid)
    }
    return true; // Otherwise, the placement is valid
}

// Function to solve the n-queens problem using backtracking
void solveQueens(int n)
{
    int i = 1;
    q[i] = 0; // Start by placing the first queen
    while (i >= 1) // Continue until all rows have been processed
    {
        q[i]++; // Move the queen to the next column
        // Try to place the queen in a valid position
        while (q[i] <= n && !canPlace(i))
            q[i]++;
        if (q[i] <= n) // If a valid position is found
        {
            if (i == n) // If all queens are placed
                displaySolution(n); // Display the solution
            else
            {
                i++; // Move to the next row
                q[i] = 0; // Reset the column position for the new row
            }
        }
        else
            i--; // Backtrack if no valid position is found
    }
}

// Function to display a signature graphic
void displaySignature(void)
{
    const char *signature = R"(  
                                                                                     
  ______ _       _     _      ____                              _____               _      
 |  ____(_)     | |   | |    / __ \                            |  __ \             | |     
 | |__   _  __ _| |__ | |_  | |  | |_   _  ___  ___ _ __  ___  | |__) |   _ _______| | ___ 
 |  __| | |/ _` | '_ \| __| | |  | | | | |/ _ \/ _ \ '_ \/ __| |  ___/ | | |_  /_  / |/ _ \
 | |____| | (_| | | | | |_  | |__| | |_| |  __/  __/ | | \__ \ | |   | |_| |/ / / /| |  __/
 |______|_|\__, |_| |_|\__|  \___\_\\__,_|\___|\___|_| |_|___/ |_|    \__,_/___/___|_|\___|
            __/ |                                                                          
           |___/                                                                           
)";

    std::cout 
				<< "\033[90mName: AL RAIMI ABDULLAH\033[0m\n"
				<< "\033[90mID:   202336020211\033[0m"
				<< "\033[31m" << signature << "\033[0m"
				<< std::endl; // Display the signature in the terminal
}
