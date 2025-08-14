#include <stdio.h>
#define MAX_PROCESSES 4
#define MAX_RESOURCES 3
int isSafe(int processes[MAX_PROCESSES][MAX_RESOURCES], int available[MAX_RESOURCES], int max[MAX_PROCESSES][MAX_RESOURCES], int allocation[MAX_PROCESSES][MAX_RESOURCES]) {
    int work[MAX_RESOURCES];
    int finish[MAX_PROCESSES] = {0};
    int safeSequence[MAX_PROCESSES];
    int count = 0;
    for (int i = 0; i < MAX_RESOURCES; i++) {
        work[i] = available[i];
    }
    // Loop through processes until all are finished or system is unsafe
    while (count < MAX_PROCESSES) {
        int found = 0;
        for (int i = 0; i < MAX_PROCESSES; i++) {
            // Check if the process is not finished and can be satisfied with current resources
            if (!finish[i]) {
                int j;
                for (j = 0; j < MAX_RESOURCES; j++) {
                    if (max[i][j] - allocation[i][j] > work[j]) {
                        break; // The process cannot be satisfied with current resources
                    }
                }
                // If all resources for the process are satisfied
                if (j == MAX_RESOURCES) {
                    // Release allocated resources and mark the process as finished
                    for (int k = 0; k < MAX_RESOURCES; k++) {
                        work[k] += allocation[i][k];
                    }
                    safeSequence[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }

        // If no process could be found in this iteration, the system is unsafe
        if (!found) {
            printf("System is in an unsafe state\n");
            return 0;
        }
    }

    // If all processes are finished, the system is in a safe state
    printf("System is in a safe state\nSafe sequence: ");
    for (int i = 0; i < MAX_PROCESSES; i++) {
        printf("%d ", safeSequence[i]);
    }
    printf("\n");
    return 1;
}

int main() {
    int processes[MAX_PROCESSES][MAX_RESOURCES] = {
        {3, 2, 2},
        {6, 1, 3},
        {3, 1, 4},
        {4, 2, 2}
    };

    int available[MAX_RESOURCES] = {9, 3, 6};

    int max[MAX_PROCESSES][MAX_RESOURCES] = {
        {6, 5, 6},
        {8, 3, 7},
        {3, 2, 5},
        {5, 4, 2}
    };

    int allocation[MAX_PROCESSES][MAX_RESOURCES] = {
        {1, 0, 0},
        {6, 1, 2},
        {2, 1, 1},
        {0, 0, 2}
    };

    if (isSafe(processes, available, max, allocation)) {
    }

    return 0;
}
