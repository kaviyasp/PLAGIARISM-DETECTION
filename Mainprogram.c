#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#define d 256 // Number of characters in the input alphabet 
// Function to check plagiarism using Rabin-Karp algorithm 
void checkPlagiarism(char *file1_path, char *file2_path, int patternLength) 
{ 
    FILE *file1 = fopen(file1_path, "r"); 
    FILE *file2 = fopen(file2_path, "r"); 
    if (file1 == NULL || file2 == NULL) { 
        printf("Error opening files.\n"); 
        exit(1); 
    } 
    char text[patternLength + 1]; 
    char pattern[patternLength + 1]; 
    // Read the pattern from the first file 
    if (fgets(pattern, patternLength + 1, file1) == NULL) { 
        printf("Error reading from file.\n"); 
        exit(1); 
    } 
    // Read the text from the second file 
    while (fgets(text, patternLength + 1, file2) != NULL) { 
        // Compare the pattern with the text using Rabin-Karp algorithm 
        if (strcmp(pattern, text) == 0) { 
            printf("Plagiarism detected!\n"); 
            fclose(file1); 
9 
 
            fclose(file2); 
            return; 
        } 
    } 
    printf("No plagiarism detected.\n"); 
    fclose(file1); 
    fclose(file2); 
} 
int main() { 
    char file1_path[100]; 
    char file2_path[100]; 
    int patternLength; 
    printf("Enter the path of the ft file: "); 
    scanf("%s", file1_path); 
    printf("Enter the path of the sd file: "); 
    scanf("%s", file2_path); 
    printf("Enter the pattern length for plagiarism checking: "); 
    scanf("%d", &patternLength); 
    checkPlagiarism(file1_path, file2_path, patternLength); 
    return 0; 
}
