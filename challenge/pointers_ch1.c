#include <stdlib.h>
#include <stdio.h>

/* Write a function that returns a pointer to the largest element in an array */

int* max_element(int* nums, int len){
    int* max = nums;

    for (int i = 1; i < len; i++) {
        if (nums[i] > *max){
            max = &nums[i];
        }
    }

    return max;
}

int main() {

    {
        int nums[] = {3, 9, 2, 8, 6};
        int* max = max_element(nums, 5);
        printf("Max: %d\n", *max);  // should be 9
    }

    {
        int nums[] = {-10, -50, -3, -7};
        int* max = max_element(nums, 4);
        printf("Max: %d\n", *max);  // should be -3
    }

    {
        int nums[] = {5, 5, 5, 5};
        int* max = max_element(nums, 4);
        printf("Max: %d\n", *max);  // should be 5
    }

    {
        int nums[] = {42};
        int* max = max_element(nums, 1);
        printf("Max: %d\n", *max);  // should be 42
    }

    {
        int nums[] = {1, 2, 3, 99};
        int* max = max_element(nums, 4);
        printf("Max: %d\n", *max);  // should be 99
    }
    
    return 0;
}

