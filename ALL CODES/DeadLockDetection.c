#include <stdio.h>
#define PROCESSES 3
#define RESOURCES 3

void findDeadlock(int max_matrix[PROCESSES][RESOURCES], int alloc_matrix[PROCESSES][RESOURCES], int available[RESOURCES]) {
    int need_matrix[PROCESSES][RESOURCES];
    int finish[PROCESSES];
    int work[RESOURCES];

    // Initialize finish array and need matrix
    for (int i = 0; i < PROCESSES; i++) {
        finish[i] = 0;
        for (int j = 0; j < RESOURCES; j++) {
            need_matrix[i][j] = max_matrix[i][j] - alloc_matrix[i][j];
        }
    }

    // Initialize work array with available resources
    for (int i = 0; i < RESOURCES; i++) {
        work[i] = available[i];
    }

    int deadlocked = 0;

    // Find deadlock
    for (int i = 0; i < PROCESSES; i++) {
        if (!finish[i]) {
            int canExecute = 1;
            for (int j = 0; j < RESOURCES; j++) {
                if (need_matrix[i][j] > work[j]) {
                    canExecute = 0;
                    break;
                }
            }

            if (canExecute) {
                // Execute the process
                finish[i] = 1;
                for (int j = 0; j < RESOURCES; j++) {
                    work[j] += alloc_matrix[i][j];
                }

                // Reset the loop to check from the beginning
                i = -1;
            }
        }
    }

    // Check for deadlock
    for (int i = 0; i < PROCESSES; i++) {
        if (!finish[i]) {
            deadlocked = 1;
            printf("Process P%d is deadlocked.\n", i + 1);
        }
    }

    if (!deadlocked) {
        printf("No deadlock detected.\n");
    }
}

int main() {
    int max_matrix[PROCESSES][RESOURCES] = {
        {3, 6, 8},
        {4, 3, 3},
        {3, 4, 4}
    };

    int alloc_matrix[PROCESSES][RESOURCES] = {
        {3, 3, 3},
        {2, 0, 3},
        {1, 2, 4}
    };

    int available[RESOURCES] = {1, 2, 0};

    findDeadlock(max_matrix, alloc_matrix, available);

    return 0;
}
