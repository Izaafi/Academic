#include <stdio.h>
// Here we define the number of elements and the capacity(space) of the knapsack.
#define ELEMENT 6
#define SPACE 10

int main() {
    int i;
    int j;
    // Array to store the elemnet and space of the items.
    int element[] = {10, 20, 30, 11, 6, 7};
    int space[] = {3, 5, 6, 7, 9, 1};

    // 2D array for the knapsack
    int bag[ELEMENT + 1][SPACE + 1];

    // Initialize bag array
    for (i = 0; i <= ELEMENT; i++) {
        for (j = 0; j <= SPACE; j++) {
            if (i == 0 || j == 0) {
                // Setting first row and column to zero
                bag[i][j] = 0;
            }
        }
    }

    // Filling the knapsack array using dynamic programming
    // Evaluate whether including the current item improves the knapsack's total value
    // Decide if excluding the current item yields a higher overall value
    // Calculate the optimal value achievable for the current knapsack capacity
    for (i = 1; i <= ELEMENT; i++) {
        for (j = 0; j <= SPACE; j++) 
        {
            if (element[i - 1] + bag[i - 1][j - space[i - 1]] > bag[i - 1][j]) 
            {
                bag[i][j] = element[i - 1] + bag[i - 1][j - space[i - 1]];
            } else {
                bag[i][j] = bag[i - 1][j];
            }
        }
    }

    // Printing out the maximum value obtained
    printf("Maximum value we get from here: %d\n", bag[ELEMENT][SPACE]);

    return 0;
}
