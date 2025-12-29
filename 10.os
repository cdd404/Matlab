#include <stdio.h>
#include <stdlib.h>

#define MAX 50

struct track {
    int up;
    int down;
} kate[MAX];

int request[MAX], head, SIZE;
int uptrack, downtrack;

int dist(int a, int b) {
    return abs(a - b);
}

void sort(int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (request[j] > request[j + 1]) {
                temp = request[j];
                request[j] = request[j + 1];
                request[j + 1] = temp;
            }
        }
    }
}

void scan(int n, int pre) {
    int i, j = 0;
    int seekcount = 0;

    sort(n);

    // Separate requests into down and up arrays
    i = 0;
    while (i < n && request[i] < head) {
        kate[j].down = request[i];
        j++;
        i++;
    }
    downtrack = j;

    while (i < n) {
        kate[j].up = request[i];
        j++;
        i++;
    }
    uptrack = j - downtrack;

    printf("SEEK SEQUENCE = ");

    if (pre < head) {
        // Move towards higher tracks first
        for (i = downtrack; i < downtrack + uptrack; i++) {
            printf("%d ", head);
            seekcount += dist(head, kate[i].up);
            head = kate[i].up;
        }
        for (i = downtrack - 1; i >= 0; i--) {
            printf("%d ", head);
            seekcount += dist(head, kate[i].down);
            head = kate[i].down;
        }
    } else {
        // Move towards lower tracks first
        for (i = downtrack - 1; i >= 0; i--) {
            printf("%d ", head);
            seekcount += dist(head, kate[i].down);
            head = kate[i].down;
        }
        for (i = downtrack; i < downtrack + uptrack; i++) {
            printf("%d ", head);
            seekcount += dist(head, kate[i].up);
            head = kate[i].up;
        }
    }

    printf("\nTOTAL DISTANCE: %d\n", seekcount);
}

int main() {
    int n, i, pre;

    printf("ENTER THE DISK SIZE:\n");
    scanf("%d", &SIZE);

    printf("ENTER THE NO OF REQUEST SEQUENCE:\n");
    scanf("%d", &n);

    printf("ENTER THE REQUEST SEQUENCE:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &request[i]);

    printf("ENTER THE CURRENT HEAD:\n");
    scanf("%d", &head);

    printf("ENTER THE PREVIOUS HEAD POSITION:\n");
    scanf("%d", &pre);

    scan(n, pre);

    return 0;
}
