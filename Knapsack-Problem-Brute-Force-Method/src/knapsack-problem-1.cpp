#include <cstdio>
#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstring>

using namespace std;

// ANSI color codes
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

// Function prototypes
void knapsack(int n, int W, int w[], int v[]);
void displayTableHeader(void);
void displayTableRow(int combination, const int solution[], int totalWeight, int totalValue, bool canLoad);
void displaySignature(void);

int main(void) {
    int n = 4;                  // Number of items
    int W = 6;                  // Knapsack capacity
    int w[] = {5, 3, 2, 1};     // Weights of the items
    int v[] = {4, 4, 3, 1};     // Values of the items

    displaySignature();
    cout << "\033[90m" << "0/1 Knapsack Problem, Brute Force Method\n" << "\033[0m";
    displayTableHeader();
    knapsack(n, W, w, v);

    return 0;
}

// Function to solve the knapsack problem using brute force
void knapsack(int n, int W, int w[], int v[]) {
    int maxValue = 0;
    int bestSolution[4] = {0};

    // Iterate over all possible combinations of items
    int numCombinations = pow(2, n);
    for (int i = 0; i < numCombinations; i++) {
        int solution[4] = {0};
        int totalWeight = 0;
        int totalValue = 0;

        // Determine the current combination
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) { // Check if the j-th item is included
                solution[j] = 1; // Mark the item as selected
                totalWeight += w[j];
                totalValue += v[j];
            }
        }

        bool canLoad = totalWeight <= W;

        // Check if the current combination is the best
        if (canLoad && totalValue > maxValue) {
            maxValue = totalValue;
            for (int k = 0; k < n; k++) {
                bestSolution[k] = solution[k];
            }
        }

        displayTableRow(i + 1, solution, totalWeight, totalValue, canLoad);
    }

    cout << "\nThe best solution is: " << GREEN << "Selected items { ";
    for (int i = 0; i < n; i++) {
        if (bestSolution[i] == 1) {
            cout << i + 1 << " ";
        }
    }
    cout << "}, Total weight: " << W << ", Total value: " << maxValue << RESET << "\n";
}

void displayTableHeader() {
    printf(YELLOW "%-15s%-20s%-15s%-15s%-20s\n" RESET, 
           "Combination", "Selected Items", "Total Weight", "Total Value", "Can it be loaded");
    printf(CYAN "%s\n" RESET, std::string(85, '-').c_str());
}

void displayTableRow(int combination, const int solution[], int totalWeight, int totalValue, bool canLoad) {
    printf(" %-15d", combination); // Start the first column at position 0 (left-aligned within 15 spaces)

    // Manually construct the "Selected Items" column with fixed spacing
    printf("{ ");
    int itemCount = 0;
    for (int i = 0; i < 4; i++) {
        if (solution[i] == 1) {
            printf("%d ", i + 1);
            itemCount += 2; // Each item (number and space) adds 2 characters
        }
    }
    printf("}"); // Closing the selected items bracket

    // Calculate the padding needed to align the next column correctly
    int padding = 17 - itemCount; // 17 = 2 (braces and space) + 15 (fixed column width)
    printf("%*s", padding, ""); // Add padding to ensure alignment

    printf("%5d%15d%28s\n", 
           totalWeight, 
           totalValue, 
           canLoad ? GREEN "Yes" RESET : RED "No" RESET);
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
