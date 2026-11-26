// ============================================================
// ACTIVITY 2: MEMORY LAYOUT OF 2D ARRAYS - ROW-MAJOR ORDER (C VERSION)
// Learning Outcome: Analyse 2D array memory layout
// ============================================================

// Include the standard input/output library
#include <stdio.h>

int main() {
    // Declare a 2D array with 3 rows and 4 columns
    int matrix[3][4] = {

        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    // Display the array in row-major order (row by row)
    printf("Row-major traversal (row by row):\n");
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 4; col++) {
            printf("%d ", matrix[row][col]);
        }
        printf("\n");
    }

    // Display memory addresses to show row-major layout
    // %p is the format specifier for pointers (addresses)
    printf("\nMemory addresses (each int takes 4 bytes):\n");
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 4; col++) {
            printf("matrix[%d][%d] = %d at address %p\n",
                   row, col, matrix[row][col], (void*)&matrix[row][col]);
        }
    }

    // Explain the row-major order
    printf("\nObservation: Addresses increase row by row.\n");

    printf("Row 0 is stored completely, then row 1, then row 2.\n");
    printf("This is called ROW-MAJOR ORDER.\n");

    return 0;
}
