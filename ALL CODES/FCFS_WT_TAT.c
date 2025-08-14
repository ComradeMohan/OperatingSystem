#include <stdio.h>
int main()
{
    char processes[] = {'P1', 'P2', 'P3'};
    int burst_time[] = {10, 15, 25};
    int n = sizeof(processes) / sizeof(processes[0]);//3

    // initialize waiting time and turnaround time arrays
    int waiting_time[n];//3
    int turnaround_time[n];//3

    // calculate waiting time for each process
    waiting_time[0] = 0;
    for (int i = 1; i < n; i++)
        waiting_time[i] = burst_time[i-1] + waiting_time[i-1];

    // calculate turnaround time for each process
    for (int i = 0; i < n; i++)
        turnaround_time[i] = burst_time[i] + waiting_time[i];

    // calculate average waiting time and average turnaround time
    float avg_waiting_time = 0;
    float avg_turnaround_time = 0;
    for (int i = 0; i < n; i++)
    {
        avg_waiting_time += waiting_time[i];
        avg_turnaround_time += turnaround_time[i];
    }
    avg_waiting_time /= n;
    avg_turnaround_time /= n;

    // print the results
    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++)
        printf("%c\t\t%d\t\t%d\t\t%d\n", processes[i], burst_time[i], waiting_time[i], turnaround_time[i]);
    printf("Average Waiting Time: %.2f\n", avg_waiting_time);
    printf("Average Turnaround Time: %.2f\n", avg_turnaround_time);

    return 0;
}