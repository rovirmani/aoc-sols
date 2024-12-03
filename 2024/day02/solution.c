#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LINE_LENGTH 1024

// Function prototypes
bool valid_diff(int current, int previous, bool increasing);
bool check_sequence_skip(int *numbers, int count, int skip_idx);
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
        return diff > 0 && diff <= 3;
    }
    else {
        return diff >= -3 && diff <= -1;
    }
}

bool check_sequence_skip(int *numbers, int count, int skip_idx) {
    if (count < 2) return false;
    
    // cringe edge cases for beginning
    int first, second;
    if (skip_idx == 0) {
        first = 1;
        second = 2;
    } else if (skip_idx == 1) {
        first = 0;
        second = 2;
    } else {
        first = 0;
        second = 1;
    }
    if (second >= count) {
        return false;
    }
    bool increasing = numbers[second] > numbers[first];
    
    // check non skipped numbers
    for (int i = 0; i < count - 1; i++) {
        if (i == skip_idx || i + 1 == skip_idx) { 
            continue;
        }
        if (!valid_diff(numbers[i + 1], numbers[i], increasing)) { 
            return false;
        }
    }
    
    // check around skipped numbers 
    if (skip_idx > 0 && skip_idx < count - 1) {
        if (!valid_diff(numbers[skip_idx + 1], numbers[skip_idx - 1], increasing)) { 
            return false;
        }
    }
    
    return true;
}

long solve_part1(FILE *fp) {
    char line[MAX_LINE_LENGTH];
    long num_safe = 0;
    
    while (fgets(line, sizeof(line), fp)) {
        // Remove newline if present
        line[strcspn(line, "\n")] = 0;
        
        // Designed to only process positive ints
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
                // Sequence checking done here
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
    long new_safe = 0;
    int numbers[20];
    
    while (fgets(line, sizeof(line), fp)) {
        line[strcspn(line, "\n")] = 0;
        
        // construct array with all numbers in the line
        char *ptr = line;
        char *endptr;
        int count = 0;
        
        while (*ptr && count < 20) {
            numbers[count] = strtol(ptr, &endptr, 10);
            if (ptr == endptr) break;
            count++;
            ptr = endptr;
            while (*ptr == ' ') ptr++;
        }
        
        // check og sequence
        if (check_sequence_skip(numbers, count, -1)) {
            new_safe++;
            continue;
        }
        
        // remove all numbers until a sequence works 
        for (int i = 0; i < count; i++) {
            if (check_sequence_skip(numbers, count, i)) {
                new_safe++;
                break;
            }
        }
    }
    
    return new_safe;
}
