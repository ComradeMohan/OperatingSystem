#include <stdio.h>
#include <stdbool.h>
#define MAX_FRAMES 10
// Function to find the index of the page in the frames
int findPageIndex(int page, int frames[], int n) {
    for (int i = 0; i < n; i++) {
        if (frames[i] == page) {
            return i;
        }
    }
    return -1; // Page not found in frames
}

// Function to simulate FIFO page replacement algorithm
int fifoPageReplacement(int pages[], int n, int numFrames) {
    int frames[MAX_FRAMES];
    int pageFaults = 0;
    int frameIndex = 0;

    // Initialize frames to -1 indicating empty frames
    for (int i = 0; i < numFrames; i++) {
        frames[i] = -1;
    }

    // Iterate through the page reference sequence
    for (int i = 0; i < n; i++) {
        int page = pages[i];

        // Check if the page is already in frames
        if (findPageIndex(page, frames, numFrames) == -1) {
            // Page fault occurs
            pageFaults++;

            // Replace the oldest page in the frames with the new page
            frames[frameIndex] = page;
            frameIndex = (frameIndex + 1) % numFrames; // Move to the next frame in a circular manner

            // Print the current state of frames
            printf("Frames: ");
            for (int j = 0; j < numFrames; j++) {
                if (frames[j] == -1) {
                    printf("- ");
                } else {
                    printf("%d ", frames[j]);
                }
            }
            printf("\n");
        }
    }

    return pageFaults;
}

int main() {
    int numFrames = 3;
    int pageReferenceSequence[] = {4, 1, 2, 4, 3, 2, 1, 5};
    int numPages = sizeof(pageReferenceSequence) / sizeof(pageReferenceSequence[0]);

    printf("Page Reference Sequence: ");
    for (int i = 0; i < numPages; i++) {
        printf("%d ", pageReferenceSequence[i]);
    }
    printf("\n");

    int pageFaults = fifoPageReplacement(pageReferenceSequence, numPages, numFrames);

    printf("Number of Page Faults: %d\n", pageFaults);

    return 0;
}
