#include <stdio.h>
#include <stdlib.h>
struct Process {
    char name;
    int arrival_time;
    int burst_time;
    int remaining_time;
    int start_time;
    int finish_time;
    int waiting_time;
    int turnaround_time;
};

void preemptive_srpt(struct Process processes[], int n) {
    int current_time = 0;
    int completed_processes = 0;
    int remaining_processes = n;

    while (completed_processes < n) {
        int shortest_index = -1;
        int shortest_remaining_time = 999999;

        for (int i = 0; i < n; i++) {
            if (processes[i].arrival_time <= current_time && processes[i].remaining_time < shortest_remaining_time && processes[i].remaining_time > 0) {
                shortest_index = i;
                shortest_remaining_time = processes[i].remaining_time;
            }
        }

        if (shortest_index == -1) {
            current_time++;
        } else {
            processes[shortest_index].start_time = current_time;
            processes[shortest_index].remaining_time--;
            current_time++;

            if (processes[shortest_index].remaining_time == 0) {
                processes[shortest_index].finish_time = current_time;
                processes[shortest_index].waiting_time = processes[shortest_index].start_time - processes[shortest_index].arrival_time;
                processes[shortest_index].turnaround_time = processes[shortest_index].finish_time - processes[shortest_index].arrival_time;

                completed_processes++;
            }
        }
    }
}

int main() {
    struct Process processes[] = {
        {'P1', 0, 3, 3, 0, 0, 0, 0},
        {'P2', 1, 5, 5, 0, 0, 0, 0},
        {'P3', 2, 3, 3, 0, 0, 0, 0},
        {'P4', 4, 1, 1, 0, 0, 0, 0},
        {'P5', 5, 3, 3, 0, 0, 0, 0},
    };

    int n = sizeof(processes) / sizeof(processes[0]);

    preemptive_srpt(processes, n);

    float total_waiting_time = 0, total_turnaround_time = 0;

    for (int i = 0; i < n; i++) {
        total_waiting_time += processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;
    }

    float avg_waiting_time = total_waiting_time / n;
    float avg_turnaround_time = total_turnaround_time / n;

    printf("Average Waiting Time: %.2f ms\n", avg_waiting_time);
    printf("Average Turnaround Time: %.2f ms\n", avg_turnaround_time);

    return 0;
}
