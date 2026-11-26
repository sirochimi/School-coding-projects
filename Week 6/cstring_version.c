// ============================================================
// ACTIVITY 3: C-STRINGS - READING AND MANIPULATING STRINGS (C VERSION)
// Learning Outcome: Evaluate C-strings vs std::string (C only has C-strings)
// ============================================================
#include <stdio.h>
#include <string.h>   // For strlen, strcpy

int main() {
    // Declare a C-string (character array) with a maximum size
    char name[50];

    // Ask the user to enter their name
    printf("Enter your name: ");
    // fgets reads a full line including spaces
    // It stops when it reads (size-1) characters or a newline
    fgets(name, 50, stdin);

    // fgets includes the newline character at the end
    // We remove it by finding its position and replacing with '\0'
    // strcspn returns the index of the first '\n' in the string
    name[strcspn(name, "\n")] = '\0';


    // Display the name
    printf("Name: %s\n", name);

    // Use strlen to find the length of the C-string
    printf("Length: %lu\n", strlen(name));

    // Display the first character
    printf("First character: %c\n", name[0]);

    // Copy the C-string to another C-string using strcpy
    char copy[50];
    strcpy(copy, name);
    printf("Copy: %s\n", copy);

    return 0;
}
