#include <stdio.h>

#define MAX_PARTITIONS 100
#define MAX_PROCESSES 100

struct Partition {
    int id;
    int size;
    int allocated;
};

struct Process {
    int id;
    int size;
    int partitionId;
};

void firstFit(struct Partition partitions[], int numPartitions, struct Process processes[], int numProcesses) {
    for (int i = 0; i < numProcesses; ++i) {
        for (int j = 0; j < numPartitions; ++j) {
            if (!partitions[j].allocated && partitions[j].size >= processes[i].size) {
                partitions[j].allocated = 1;
                processes[i].partitionId = partitions[j].id;
                break;
            }
        }
    }
}

void displayAllocation(struct Process processes[], int numProcesses) {
    printf("\nProcess Allocation:\n");
    for (int i = 0; i < numProcesses; ++i) {
        printf("Process %d -> Partition %d\n", processes[i].id, processes[i].partitionId);
    }
}

int main() {
    struct Partition partitions[MAX_PARTITIONS];
    struct Process processes[MAX_PROCESSES];
    int numPartitions, numProcesses;

    printf("Enter the number of partitions: ");
    scanf("%d", &numPartitions);

    printf("Enter partition details:\n");
    for (int i = 0; i < numPartitions; ++i) {
        partitions[i].id = i + 1;
        printf("Partition %d size: ", partitions[i].id);
        scanf("%d", &partitions[i].size);
        partitions[i].allocated = 0;
    }

    printf("Enter the number of processes: ");
    scanf("%d", &numProcesses);

    printf("Enter process details:\n");
    for (int i = 0; i < numProcesses; ++i) {
        processes[i].id = i + 1;
        printf("Process %d size: ", processes[i].id);
        scanf("%d", &processes[i].size);
        processes[i].partitionId = -1;
    }

    firstFit(partitions, numPartitions, processes, numProcesses);
    displayAllocation(processes, numProcesses);

    return 0;
}
