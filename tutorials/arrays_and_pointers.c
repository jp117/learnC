#include <stdio.h>
#include <stdlib.h>

/* 
The first seven rows of Pascal's triangle are shown below. Note that row i contains i elements. Therefore, to store the numbers from the first three rows, one would require 1 + 2 + 3 = 6 memory slots.

1

1 1

1 2 1

1 3 3 1

1 4 6 4 1

1 5 10 10 5 1

1 6 15 20 15 6 1

Complete the skeleton code given below to store the numbers from the first three rows of Pascal's triangle in a two-dimensional "array" using dynamic memory allocation. Note that you must allocate exactly six memory slots to store those six numbers. No extra memory should be allocated. At the end of your program, free all the memory blocks used in this program.

*/

int main() {
    int i, j;
    /* TODO: define the 2D pointer variable here */
    int **pnumbers;

    /* TODO: complete the following line to allocate memory for holding three rows */
    pnumbers = (int **) malloc(3 *sizeof(int *));

    /* TODO: allocate memory for storing the individual elements in a row */
    pnumbers[0] = (int *) malloc(1 * sizeof(int));
    pnumbers[1] = (int *) malloc(2 * sizeof(int));
    pnumbers[2] = (int *) malloc(3 * sizeof(int));

    pnumbers[0][0] = 1;
    pnumbers[1][0] = 1;
    pnumbers[1][1] = 1;
    pnumbers[2][0] = 1;
    pnumbers[2][1] = 2;
    pnumbers[2][2] = 1;

    for (i = 0; i < 3; i++) {
        for (j = 0; j <= i; j++) {
            printf("%d", pnumbers[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < 3; i++) {
        /* TODO: free memory allocated for each row */
        free(pnumbers[i]);
    }

    /* TODO: free the top-level pointer */
    free(pnumbers);

  return 0;
}