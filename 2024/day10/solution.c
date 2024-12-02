#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

// Function prototypes
long solve_part1(FILE *fp);
long solve_part2(FILE *fp);

int main() {
    FILE *fp;
    
    // Part 1
    fp = fopen("input.txt", "r");
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }
    
    long part1_result = solve_part1(fp);
    printf("Part 1 Result: %ld\n", part1_result);
    fclose(fp);
    
    // Part 2
    fp = fopen("input.txt", "r");
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }
    
    long part2_result = solve_part2(fp);
    printf("Part 2 Result: %ld\n", part2_result);
    fclose(fp);
    
    return 0;
}

long solve_part1(FILE *fp) {
    char line[MAX_LINE_LENGTH];
    long result = 0;
    
    while (fgets(line, sizeof(line), fp)) {
        // Remove newline if present
        line[strcspn(line, "\n")] = 0;
        
        // TODO: Implement part 1 solution
    }
    
    return result;
}

long solve_part2(FILE *fp) {
    char line[MAX_LINE_LENGTH];
    long result = 0;
    
    while (fgets(line, sizeof(line), fp)) {
        // Remove newline if present
        line[strcspn(line, "\n")] = 0;
        
        // TODO: Implement part 2 solution
    }
    
    return result;
}
