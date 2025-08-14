#include <stdio.h>

int absoluteValue(int);

void main() {
    int queue[25], n, headposition, i, j, k, seek = 0, maxrange, difference, temp, queue1[20], queue2[20], temp1 = 0, temp2 = 0;
    float averageSeekTime;

    // Initialize the maximum range of the disk
    maxrange = 5;

    // Initialize the number of queue requests
    n = 5;

    // Initialize the initial head position
    headposition = 50;

    // Initialize the disk positions to be read in the order of arrival
    queue[0] = headposition;
    queue[1] = 55;
    queue[2] = 58;
    queue[3] = 60;
    queue[4] = 70;
    queue[5] = 18;

    // Calculate the seek time and average seek time
    for (j = 0; j <= n; j++) {
        // Find the difference between the next position and the current position
        difference = absoluteValue(queue[j + 1] - queue[j]);

        // Add the difference to the current seek time value
        seek = seek + difference;

        // Move the disk head from the current position to the next position
        queue[j + 1] = queue[j] + difference;
    }

    // Calculate the average seek time
    averageSeekTime = seek / (float)n;

    // Print the results
    printf("Total Seek Time = %d\n", seek);
    printf("Average Seek Time = %f\n", averageSeekTime);
}

// Define the function to calculate the absolute value of a number
int absoluteValue(int x) {
    if (x > 0) {
        return x;
    } else {
        return x * -1;
    }
}