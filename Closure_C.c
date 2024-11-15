#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Function to generate a predicate to check if a string starts with a specific character
bool (*stringStartsWithAnyCharpredicateGenerator(char startsWithChar))(const char *item) {
    static char targetChar; // Static variable to hold the character
    targetChar = startsWithChar; // Store the character

    // Local function to check if the string starts with the target character
    bool startsWith(const char *item) {
        if (item == NULL) {
            return false;
        }
        return item[0] == targetChar; // Compare with the stored character
    }
    
    return startsWith; // Return the pointer to the function
}

// Function to check if a string ends with 'b'
bool endsWithB(const char *str) {
    if (str == NULL || strlen(str) == 0) {
        return false;
    }
    return str[strlen(str) - 1] == 'b';
}

// Function to filter strings based on the provided predicate
int filterString(char *names[], int arrayLength, bool (*predicate)(const char*), char *result[], int maxResults) {
    int count = 0;
    for (int i = 0; i < arrayLength; i++) {
        if (predicate(names[i])) {
            if (count < maxResults) {
                result[count] = names[i]; // Store the result
                count++;
            }
        }
    }
    return count; // Return the number of filtered results
}

int main() {
    char *names[10] = {"bosch", "Robert", "Lenovo", "Bengaluru", "Rubic"};
    int arrayLength = sizeof(names) / sizeof(names[0]);
    char* result[arrayLength];
    int maxResults = arrayLength;

    // Get predicate for names starting with 'R'
    bool (*predicate)(const char *item) = stringStartsWithAnyCharpredicateGenerator('R');
    
    int count = filterString(names, arrayLength, predicate, result, maxResults);
    printf("Filtered names starting with 'R':\n");
    for (int i = 0; i < count; i++) {
        printf("%s\n", result[i]);
    }

    // Get predicate for names starting with 'B'
    predicate = stringStartsWithAnyCharpredicateGenerator('B');
    
    count = filterString(names, arrayLength, predicate, result, maxResults);
    printf("Filtered names starting with 'B':\n");
    for (int i = 0; i < count; i++) {
        printf("%s\n", result[i]);
    }

    return 0;
}
