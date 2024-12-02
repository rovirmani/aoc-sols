#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

// Global arrays
int arr1[1000];
int arr2[1000];

int solve_part1(FILE *fp);
int solve_part2(FILE *fp);

int find_array_position(int *array, int index, int value) {
    int low = 0;
    int high = index - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (array[mid] < value) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return low; // array position to insert 
}

void arr_insert(int *array, int index, int value) {
    int pos = find_array_position(array, index, value); 

    for (int i = index; i > pos; i--) {
        array[i] = array[i - 1];
    }

    array[pos] = value;
}

int main() {
    FILE *fp;
    
    // Part 1
    fp = fopen("input.txt", "r");
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }
    
    int part1_result = solve_part1(fp);
    printf("Part 1 Result: %d\n", part1_result);
    fclose(fp);
    
    // Part 2 (arrays are already sorted)
    fp = fopen("input.txt", "r");
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }
    
    int part2_result = solve_part2(fp);
    printf("Part 2 Result: %d\n", part2_result);
    fclose(fp);
    
    return 0;
}

int solve_part1(FILE *fp) {
    char line[MAX_LINE_LENGTH];
    int result = 0;
    int count = 0; // track line indices for array insert 
    
    while (fgets(line, sizeof(line), fp)) {
        // Remove newline if present
        line[strcspn(line, "\n")] = 0;
        
        // get the integers
        int value1, value2;

        if (sscanf(line, "%d %d", &value1, &value2) != 2) {
            printf("Line didnt have 2 integers");
            exit(1);
        }
        
        arr_insert(arr1, count, value1);
        arr_insert(arr2, count, value2);
        count++;
    }

    for(int i = 0; i < count; i++) {
        result += abs(arr1[i] - arr2[i]);
    }
    
    return result;
}

int solve_part2(FILE *fp) {
    int sim_score = 0;
    
    for (int i = 0; i < 1000; i++) {
        int count = 0;
        
        // count num appearances in the second array 
        for (int j = 0; j < 1000; j++) {
            if (arr1[i] == arr2[j]) {
                count++;
            }
        }
        sim_score += arr1[i] * count;
    }
    
    return sim_score;
}
