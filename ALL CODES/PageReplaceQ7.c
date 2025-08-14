#include<stdio.h>
#define MAX_FRAMES 3
int findLRU(int frames[], int n, int referenceSeq[], int currIndex) {
    int index = -1;
    int farthest = currIndex;
    for (int i = 0; i < n; i++) {
        int j;
        for (j = currIndex - 1; j >= 0; j--) {
            if (frames[i] == referenceSeq[j]) {
                break;
            }
        }
        if (j == -1 && farthest > j) {
            farthest = j;
            index = i;
        }
    }
    return index;
}
void pageReplacementLRU(int referenceSeq[], int n, int numFrames) {
    int frames[MAX_FRAMES];
    int pageFaults = 0;

    for (int i = 0; i < MAX_FRAMES; i++) {
        frames[i] = -1;  // Initialize frames as empty
    }

    for (int i = 0; i < n; i++) {
        int page = referenceSeq[i];
        int frameIndex = -1;

        for (int j = 0; j < numFrames; j++) {
            if (frames[j] == page) {
                frameIndex = j;
                break;
            }
        }

        if (frameIndex == -1) {
            // Page fault
            int lruIndex = findLRU(frames, numFrames, referenceSeq, i);
            frames[lruIndex] = page;
            pageFaults++;
        }
    }

    printf("Number of Page Faults using LRU: %d\n", pageFaults);
}
int main() {
    int referenceSeq[] = {1, 2, 3, 2, 1, 5, 2, 1, 6, 2, 5, 6, 3, 1, 3, 6, 1, 2, 4, 3};
    int n = sizeof(referenceSeq) / sizeof(referenceSeq[0]);
    int numFrames = 3;

    pageReplacementLRU(referenceSeq, n, numFrames);

    return 0;
}
