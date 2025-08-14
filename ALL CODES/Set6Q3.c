#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define NUM_TRACKS 5
void sort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
int abs_diff(int a, int b) {
    return abs(a - b);
}
int fcfs(int tracks[], int size, int start) {
    int head_movement = 0;
    for (int i = 0; i < size; i++) {
        head_movement += abs_diff(start, tracks[i]);
        start = tracks[i];
    }
    return head_movement;
}
int sstf(int tracks[], int size, int start) {
	
    int head_movement=0;
    int visited[NUM_TRACKS] = {0};
    for (int i = 0; i < size; i++) {
        int min_distance = INT_MAX;
        int min_index = -1;
        for (int j = 0; j < size; j++) {
            if (!visited[j]) {
                int distance = abs_diff(start, tracks[j]);
                if (distance < min_distance) {
                    min_distance = distance;
                    min_index = j;
                }
            }
        }
        head_movement += min_distance;
        start = tracks[min_index];
        visited[min_index] = 1;
    }
    return head_movement;
}
int main() {
    int tracks[] = {50, 58, 60, 70, 18};
    int size = sizeof(tracks) / sizeof(tracks[0]);
    int start = 0; 
    int fcfs_movement = fcfs(tracks, size, start);
    printf("FCFS Head Movement: %d\n", fcfs_movement);
    int sstf_movement = sstf(tracks, size, start);
    printf("SSTF Head Movement: %d\n", sstf_movement);
    float average_movement = (float)(fcfs_movement + sstf_movement) / 2;
    printf("Average Head Movement: %.2f\n", average_movement);
    return 0;
}
