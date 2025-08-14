#include <stdio.h>
#include <stdlib.h>
#define MAX_TRACKS 100
int main() {
    int tracks[MAX_TRACKS], n_tracks, start_pos, i, j, temp, head_movements;
	printf("Enter the number of tracks: ");
    scanf("%d", &n_tracks);
    printf("Enter the tracks:\n");
    for (i = 0; i < n_tracks; i++) {
        scanf("%d", &tracks[i]);
    }
    printf("Enter the starting position: ");
    scanf("%d", &start_pos);
    for (i = 0; i < n_tracks - 1; i++) {
        for (j = i + 1; j < n_tracks; j++) {
            if (tracks[i] > tracks[j]) {
                temp = tracks[i];
                tracks[i] = tracks[j];
                tracks[j] = temp;
            }
        }
    }
    for (i = 0; i < n_tracks; i++) {
        if (tracks[i] >= start_pos) {
            break;
        }
    }
    head_movements = 0;
    if (i == n_tracks) {
        i = n_tracks - 1;
        head_movements += tracks[i] - start_pos;
    }
    for (; i >= 0; i--) {
        head_movements += start_pos - tracks[i];
        start_pos = tracks[i];
    }
    head_movements += start_pos; 
    for (i = 1; i < n_tracks; i++) {
        head_movements += tracks[i] - start_pos;
        start_pos = tracks[i];
    }
    printf("Average head movements: %.2f\n", (float) head_movements / n_tracks);
    return 0;
}
//output:
//Enter the number of tracks: 
//5
//Enter the tracks:
//55 58 	60 70 18
//Enter the starting position: 55
//Average head movements: 21.40