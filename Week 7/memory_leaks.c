// ============================================================
// ACTIVITY 3: MEMORY LEAKS (C VERSION)
// Learning Outcome: Evaluate memory leak risks and fix them
// ============================================================

// Include standard I/O library for printf
#include <stdio.h>

// Include standard library for malloc and free
#include <stdlib.h>

// A function that allocates memory but forgets to free it
void createLeak() {
    // In C, we use malloc() to allocate memory on the heap.
    // sizeof(int) ensures we allocate the correct number of bytes for an integer.
    // We cast the void pointer returned by malloc to an int pointer (int*).
    int *ptr = (int*)malloc(sizeof(int));



    // Check if allocation was successful
    if (ptr == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    // Store a value at the allocated memory address
    *ptr = 42;

    printf("Inside function. The value is: %d\n", *ptr);
    printf("Memory allocated at address: %p\n", (void*)ptr);

    // LEAK DEMONSTRATION: The uncorrected function would end here.
    // The local pointer 'ptr' is destroyed, but the heap memory is NEVER freed.
    // We free the allocation to fix the leak.
    free(ptr);
}

int main() {
    printf("Calling function with corrected memory management...\n");
    createLeak();
    printf("Function finished. The memory has been freed.\n");

    return 0;
}
