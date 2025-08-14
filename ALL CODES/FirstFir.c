#include <stdio.h>

#define MAX_PARTITIONS 10

// Function to perform First-Fit memory allocation
void firstFit(int memoryPartitions[], int numPartitions, int processSizes[], int numProcesses) {
    int allocation[MAX_PARTITIONS];
    for (int i = 0; i < numPartitions; i++) {
        allocation[i] = -1; // Initialize allocation array to -1, indicating unallocated partitions
    }

    // Allocate memory for each process using First-Fit algorithm
    for (int i = 0; i < numProcesses; i++) {
        for (int j = 0; j < numPartitions; j++) {
            if (allocation[j] == -1 && memoryPartitions[j] >= processSizes[i]) {
                allocation[j] = i; // Allocate the process to the partition
                break;
            }
        }
    }

    // Display the outcome
    printf("Process\tProcess Size\tPartition\n");
    for (int i = 0; i < numProcesses; i++) {
        printf("%d\t%d KB\t\t", i + 1, processSizes[i]);
        if (allocation[i] != -1) {
            printf("%d KB\n", memoryPartitions[allocation[i]]);
        } else {
            printf("Not Allocated\n");
        }
    }
}

int main() {
    int memoryPartitions[] = {300, 600, 350, 200, 750, 125};
    int numPartitions = sizeof(memoryPartitions) / sizeof(memoryPartitions[0]);

    int processSizes[] = {115, 500, 358, 200, 375};
    int numProcesses = sizeof(processSizes) / sizeof(processSizes[0]);

    printf("Memory Partitions: ");
    for (int i = 0; i < numPartitions; i++) {
        printf("%d KB ", memoryPartitions[i]);
    }
    printf("\n");

    printf("Process Sizes: ");
    for (int i = 0; i < numProcesses; i++) {
        printf("%d KB ", processSizes[i]);
    }
    printf("\n\n");

    // Perform First-Fit memory allocation
    firstFit(memoryPartitions, numPartitions, processSizes, numProcesses);

    return 0;
}
