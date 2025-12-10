#include <stdio.h>
#include <stdlib.h>

void main()
{
    int fragments[20], blocks[20], files[20];
    int ii, jj, nn, pp, temp, lowest = 9999;
    static int barray[20], parray[20];

    printf("Memory Management Scheme - Best Fit");
    printf("\nEnter the number of blocks:");
    scanf("%d", &nn);
    printf("Enter the number of processes:");
    scanf("%d", &pp);

    printf("\nEnter the size of the blocks:\n");
    for (ii = 1; ii <= nn; ii++)
    {
        printf("Block no.%d:", ii);
        scanf("%d", &blocks[ii]);
    }

    printf("\nEnter the size of the processes:\n");
    for (ii = 1; ii <= pp; ii++)
    {
        printf("Process no.%d:", ii);
        scanf("%d", &files[ii]);
    }

    for (ii = 1; ii <= pp; ii++)
    {
        for (jj = 1; jj <= nn; jj++)
        {
            if (barray[jj] != 1)
            {
                temp = blocks[jj] - files[ii];
                if (temp >= 0)
                {
                    if (lowest > temp)
                    {
                        parray[ii] = jj;
                        lowest = temp;
                    }
                }
            }
        }
        fragments[ii] = lowest;
        barray[parray[ii]] = 1;
        lowest = 10000;
    }

    printf("\nProcess_no\tProcess_size\tBlock_no\tBlock_size\tFragment");
    for (ii = 1; ii <= pp && parray[ii] != 0; ii++)
    {
        printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d", ii, files[ii], parray[ii], blocks[parray[ii]], fragments[ii]);
    }
}
