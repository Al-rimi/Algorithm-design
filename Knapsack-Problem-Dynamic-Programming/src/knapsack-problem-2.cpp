#include <stdio.h>
#include <vector>
#include <iomanip>
#include <iostream>

using namespace std;

// Function prototypes
void knapsackDP(int n, int W, const int w[], const int v[]);
void printTable(const vector<vector<int>>& dp, int n, int W);
void findSelectedItems(const vector<vector<int>>& dp, const int w[], const int v[], int n, int W);
void displaySignature(void);

int main() {
    displaySignature();

    int n = 5; // Number of items
    int W = 10; // Knapsack capacity
    int w[] = {2, 2, 6, 5, 4}; // Weights of the items
    int v[] = {6, 3, 5, 4, 6}; // Values of the items

    printf("\033[90m0/1 Knapsack Problem, Dynamic Programming \n\033[0m");
    knapsackDP(n, W, w, v);
    printf("\n");

    return 0;
}

// Function to solve the knapsack problem using dynamic programming
void knapsackDP(int n, int W, const int w[], const int v[]) {
    // Create a 2D DP table to store the maximum value for each item and capacity
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    // Fill the DP table
    for (int i = 1; i <= n; ++i) { // Iterate over each item
        for (int j = 0; j <= W; ++j) { // Iterate over each capacity
            // Check if the current item can be included
            if (w[i - 1] <= j) {
                // Choose the maximum value between including and not including the current item
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i - 1]] + v[i - 1]);
            } else {
                // If the item cannot be included, take the value from the previous row
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    // Print the DP table (Optional for debugging)
    // printTable(dp, n, W);

    // Find and print the selected items and the optimal value
    findSelectedItems(dp, w, v, n, W);
}

// Function to print the DP table (Optional, for debugging purposes)
void printTable(const vector<vector<int>>& dp, int n, int W) {
    printf("DP Table:\n");
    printf("Weight Capacity -> ");
    for (int j = 0; j <= W; ++j) {
        printf("%10d", j); // Print capacity headers
    }
    printf("\n");
    for (int i = 0; i <= n; ++i) {
        printf("Item %2d -> ", i);
        for (int j = 0; j <= W; ++j) {
            printf("%10d", dp[i][j]); // Print DP values
        }
        printf("\n");
    }
    printf("\n");
}

// Function to find and print the selected items
void findSelectedItems(const vector<vector<int>>& dp, const int w[], const int v[], int n, int W) {
    int maxValue = dp[n][W]; // The maximum value obtainable with capacity W
    vector<int> selectedItems; // To store the indices of selected items

    // Traceback to determine which items are included in the optimal solution
    int capacity = W;
    for (int i = n; i > 0; --i) {
        // Check if the current item was included in the optimal solution
        if (dp[i][capacity] != dp[i - 1][capacity]) {
            selectedItems.push_back(i); // Add item to selectedItems
            capacity -= w[i - 1]; // Decrease the remaining capacity
        }
    }

    // Print the result in the required format with colors
    printf("Solution result (\033[32moptimal scheme\033[0m)\n");
    printf("Selected items: ");
    for (int i = selectedItems.size() - 1; i >= 0; --i) {
        printf("\033[32m%d\033[0m ", selectedItems[i]); // Print item numbers in red
    }
    printf("\nTotal value = \033[32m%d\033[0m\n", maxValue); // Print total value in green
}

// Function to display a signature graphic
void displaySignature(void)
{
    const char *signature = R"(  
  _  __                                 _      _____           _     _                
 | |/ /                                | |    |  __ \         | |   | |               
 | ' / _ __   __ _ _ __  ___  __ _  ___| | __ | |__) | __ ___ | |__ | | ___ _ __ ___  
 |  < | '_ \ / _` | '_ \/ __|/ _` |/ __| |/ / |  ___/ '__/ _ \| '_ \| |/ _ \ '_ ` _ \ 
 | . \| | | | (_| | |_) \__ \ (_| | (__|   <  | |   | | | (_) | |_) | |  __/ | | | | |
 |_|\_\_| |_|\__,_| .__/|___/\__,_|\___|_|\_\ |_|   |_|  \___/|_.__/|_|\___|_| |_| |_|
                  | |                                                                 
                  |_|                                                                 
)";

    std::cout 
                << "\033[90mName: AL RAIMI ABDULLAH\033[0m\n"
                << "\033[90mID:   202336020211\033[0m"
                << "\033[31m" << signature << "\033[0m"
                << std::endl; // Display the signature in the terminal
}