#include <stdlib.h>
#include <stdio.h>

/* Write a function that swaps the values of two integers using pointers. */

void swap_ints(int* x, int* y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main () {

    {
        int x = 1, y = 2;
        swap_ints(&x, &y);
        printf("x: %d, y: %d\n", x, y); 
        // x: 2, y: 1
    }

    {
        int x = 7, y = 7;
        swap_ints(&x, &y);
        printf("x: %d, y: %d\n", x, y);
        // should remain the same: 7, 7
    }

    {
        int x = -3, y = 9;
        swap_ints(&x, &y);
        printf("x: %d, y: %d\n", x, y);
        // x: 9, y: -3
    }

    {
        int x = 0, y = 42;
        swap_ints(&x, &y);
        printf("x: %d, y: %d\n", x, y);
        // x: 42, y: 0
    }

    {
        int x = 100, y = 200;
        swap_ints(&x, &y);
        swap_ints(&x, &y);
        printf("x: %d, y: %d\n", x, y);
        // should return to original: 100, 200
    }

    return 0;
}