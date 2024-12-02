#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LINE_LENGTH 1024

// Function prototypes
bool valid_diff(int current, int previous, bool increasing);
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

bool valid_diff(int current, int previous, bool increasing) {
    int diff = current - previous;
    if (increasing) {
        return diff > 0 && diff <=3;
    }
    else {
        return diff >= -3 && diff <= -1;
    }
}

long solve_part1(FILE *fp) {
    char line[MAX_LINE_LENGTH];
    long num_safe = 0;
    
    while (fgets(line, sizeof(line), fp)) {
        // Remove newline if present
        line[strcspn(line, "\n")] = 0;
        
        // designed to only process positive ints
        char *ptr = line;
        char *endptr;
        int previous = -1;
        int current;
        bool increasing;
        bool safe = false;

        while (*ptr) {
            current = strtol(ptr, &endptr, 10);
            if (ptr == endptr) {
                break;
            }

            if (previous == -1) {
                previous = current;
            } else {
                // sequence checking done here
                if (!safe) {
                    increasing = (current > previous);
                    safe = valid_diff(current, previous, increasing);
                    if (!safe) {
                        break;
                    }
                } else {
                    if (increasing && !valid_diff(current, previous, increasing) ||
                    (!increasing && !valid_diff(current, previous, increasing))) {
                        safe = false;
                        break;
                    }
                }
                previous = current;
            }

            ptr = endptr;
            while(*ptr == ' ') {
                ptr++;
            }
            
        }
        if (safe) {
            num_safe += 1;
        }
    }
    
    return num_safe;
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
