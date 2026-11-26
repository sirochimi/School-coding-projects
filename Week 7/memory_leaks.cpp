// ============================================================
// ACTIVITY 3A: THE MEMORY LEAK
// Learning Outcome: Evaluate memory leak risks
// ============================================================

#include <iostream>
using namespace std;

// A function that allocates memory but forgets to delete it
void createLeak() {
    // 'new int' allocates memory on the HEAP (dynamic memory) for one integer.
    // It returns the memory address, which we store in 'ptr'.
    int* ptr = new int(42);

    cout << "Inside function. The value is: " << *ptr << endl;
    cout << "Memory allocated at address: " << ptr << endl;

    // LEAK DEMONSTRATION: The uncorrected function would end here.
    // The local variable 'ptr' is destroyed, but the memory on the heap
    // it was pointing to is NEVER freed. We have lost the address,
    // and the memory would become unreachable. Fix: release it.
    delete ptr;
}

int main() {


    cout << "Calling function with corrected memory management..." << endl;
    createLeak();
    cout << "Function finished. The memory has been freed." << endl;

    // If we called createLeak() in a loop a million times,
    // the program would consume gigabytes of RAM and crash.

    return 0;
}
