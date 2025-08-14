#include <stdio.h>
// Function to perform Non-Preemptive SJF Scheduling
void sjfScheduling(int burstTime[], int n, int waitingTime[], int turnaroundTime[]) {
    int completionTime[n];
    int remainingTime[n];

    // Copy burst times to remainingTime array
    for (int i = 0; i < n; i++) {
        remainingTime[i] = burstTime[i];
    }

    int currentTime = 0;

    // Process each job
    for (int i = 0; i < n; i++) {
        // Find the job with the shortest remaining time
        int shortestJob = 0;
        for (int j = 1; j < n; j++) {
            if (remainingTime[j] < remainingTime[shortestJob]) {
                shortestJob = j;
            }
        }

        // Update completion time
        completionTime[shortestJob] = currentTime + remainingTime[shortestJob];

        // Update waiting time and turnaround time
        waitingTime[shortestJob] = currentTime;
        turnaroundTime[shortestJob] = completionTime[shortestJob];

        // Update current time
        currentTime = completionTime[shortestJob];

        // Set remaining time of the completed job to a large value to avoid selecting it again
        remainingTime[shortestJob] = 9999;
    }
}

int main() {
    int n = 4;
    int burstTime[] = {6, 8, 7, 3};
    int waitingTime[n], turnaroundTime[n];

    // Perform Non-Preemptive SJF Scheduling
    sjfScheduling(burstTime, n, waitingTime, turnaroundTime);

    // Calculate average waiting time and average turnaround time
    double avgWaitingTime = 0, avgTurnaroundTime = 0;
    for (int i = 0; i < n; i++) {
        avgWaitingTime += waitingTime[i];
        avgTurnaroundTime += turnaroundTime[i];
    }

    avgWaitingTime /= n;
    avgTurnaroundTime /= n;

    // Display the results
    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\n", i + 1, burstTime[i], waitingTime[i], turnaroundTime[i]);
    }

    printf("\nAverage Waiting Time: %.2f\n", avgWaitingTime);
    printf("Average Turnaround Time: %.2f\n", avgTurnaroundTime);

    return 0;
}
