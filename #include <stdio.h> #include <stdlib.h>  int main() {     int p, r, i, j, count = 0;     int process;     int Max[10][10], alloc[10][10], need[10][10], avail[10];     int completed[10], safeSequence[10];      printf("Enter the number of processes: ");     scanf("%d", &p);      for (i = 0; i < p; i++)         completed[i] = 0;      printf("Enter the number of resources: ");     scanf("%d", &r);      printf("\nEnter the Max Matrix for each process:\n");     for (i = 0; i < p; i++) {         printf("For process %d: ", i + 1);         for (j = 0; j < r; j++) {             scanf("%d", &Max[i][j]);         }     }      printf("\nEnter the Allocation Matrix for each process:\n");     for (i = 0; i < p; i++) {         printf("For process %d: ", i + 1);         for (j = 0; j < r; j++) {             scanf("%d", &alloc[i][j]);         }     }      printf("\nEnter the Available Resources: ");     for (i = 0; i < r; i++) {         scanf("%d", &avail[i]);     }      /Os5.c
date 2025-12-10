#include <stdio.h>
#include <stdlib.h>

int main() {
    int p, r, i, j, count = 0;
    int process;
    int Max[10][10], alloc[10][10], need[10][10], avail[10];
    int completed[10], safeSequence[10];

    printf("Enter the number of processes: ");
    scanf("%d", &p);

    for (i = 0; i < p; i++)
        completed[i] = 0;

    printf("Enter the number of resources: ");
    scanf("%d", &r);

    printf("\nEnter the Max Matrix for each process:\n");
    for (i = 0; i < p; i++) {
        printf("For process %d: ", i + 1);
        for (j = 0; j < r; j++) {
            scanf("%d", &Max[i][j]);
        }
    }

    printf("\nEnter the Allocation Matrix for each process:\n");
    for (i = 0; i < p; i++) {
        printf("For process %d: ", i + 1);
        for (j = 0; j < r; j++) {
            scanf("%d", &alloc[i][j]);
        }
    }

    printf("\nEnter the Available Resources: ");
    for (i = 0; i < r; i++) {
        scanf("%d", &avail[i]);
    }

    // Calculate Need Matrix
    for (i = 0; i < p; i++) {
        for (j = 0; j < r; j++) {
            need[i][j] = Max[i][j] - alloc[i][j];
        }
    }

    printf("\nMax matrix:\tAllocation matrix:\tNeed matrix:\n");
    for (i = 0; i < p; i++) {
        for (j = 0; j < r; j++)
            printf("%d ", Max[i][j]);
        printf("\t");
        for (j = 0; j < r; j++)
            printf("%d ", alloc[i][j]);
        printf("\t");
        for (j = 0; j < r; j++)
            printf("%d ", need[i][j]);
        printf("\n");
    }

    // Banker's Algorithm
    while (count < p) {
        process = -1;
        for (i = 0; i < p; i++) {
            if (completed[i] == 0) {
                int canRun = 1;
                for (j = 0; j < r; j++) {
                    if (avail[j] < need[i][j]) {
                        canRun = 0;
                        break;
                    }
                }
                if (canRun) {
                    process = i;
                    break;
                }
            }
        }

        if (process == -1) break;

        printf("\nProcess %d runs to completion!", process + 1);
        safeSequence[count] = process + 1;
        count++;

        for (j = 0; j < r; j++) {
            avail[j] += alloc[process][j];
            alloc[process][j] = 0;
            Max[process][j] = 0;
            need[process][j] = 0;
        }
        completed[process] = 1;
    }

    if (count == p) {
        printf("\n\nThe system is in a SAFE state!!\n");
        printf("Safe Sequence: < ");
        for (i = 0; i < p; i++) {
            printf("%d ", safeSequence[i]);
        }
        printf(">\n");
    } else {
        printf("\n\nThe system is in an UNSAFE state!!\n");
    }

    return 0;
}
