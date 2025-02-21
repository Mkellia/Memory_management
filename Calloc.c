#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_STUDENT_COUNT 10
#define SHRINKED_STUDENT_COUNT 6
#define EMAIL_LENGTH 50  

int main() {
    
    char **emails = (char **)calloc(INITIAL_STUDENT_COUNT, sizeof(char *));
    
    if (emails == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    
    for (int i = 0; i < INITIAL_STUDENT_COUNT; i++) {
        emails[i] = (char *)calloc(EMAIL_LENGTH, sizeof(char));
        if (emails[i] == NULL) {
            printf("Memory allocation failed for email %d!\n", i);
            return 1;
        }
    }
    
    for (int i = 0; i < INITIAL_STUDENT_COUNT; i++) {
        snprintf(emails[i], EMAIL_LENGTH, "student%d@university.edu", i + 1);
    }
    
    printf("Stored Email Addresses before shrinking:\n");
    for (int i = 0; i < INITIAL_STUDENT_COUNT; i++) {
        printf("%s\n", emails[i]);
    }
    
    emails = (char **)realloc(emails, SHRINKED_STUDENT_COUNT * sizeof(char *));
    if (emails == NULL) {
        printf("Memory reallocation failed!\n");
        return 1;
    }
    
    printf("Stored Email Addresses after shrinking:\n");
    for (int i = 0; i < SHRINKED_STUDENT_COUNT; i++) {
        printf("%s\n", emails[i]);
    }
    
    for (int i = 0; i < SHRINKED_STUDENT_COUNT; i++) {
        free(emails[i]);
    }
    free(emails);
    
    return 0;
}
