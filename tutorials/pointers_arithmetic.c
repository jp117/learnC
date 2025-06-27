#include <stdio.h>

int main()
{
    {
        int intarray[5] = {10,20,30,40,50};
        int i;
        for(i = 0; i < 5; i++)
            printf("intarray[%d] has value %d - and address @ %x\n", i, intarray[i], &intarray[i]);

        int *intpointer = &intarray[3]; //point to the 4th element in the array
        printf("address: %x - has value %d\n", intpointer, *intpointer); //print the address of the 4th element

        intpointer++; //now increase the pointer's address so it points to the 5th elemnt in the array
        printf("address: %x - has value %d\n", intpointer, *intpointer); //print the address of the 5th element
    }

    {
    int intarray[5] = {10,20,30,40,50};

    int i;
    for(i = 0; i < 5; i++)
        printf("intarray[%d] has value %d - and address @ %x\n", i, intarray[i], &intarray[i]);

    int *intpointer = &intarray[4]; //point to the 5th element in the array
    printf("address: %x - has value %d\n", intpointer, *intpointer); //print the address of the 5th element

    intpointer--; //now decrease the point's address so it points to the 4th element in the array
    printf("address: %x - has value %d\n", intpointer, *intpointer); //print the address of the 4th element
    }



    {
    int intarray[5] = {10,20,30,40,50};

    int i;
    for(i = 0; i < 5; i++)
        printf("intarray[%d] has value: %d - and address @ %x\n", i, intarray[i], &intarray[i]);

    int *intpointer = &intarray[1]; //point to the 2nd element in the array
    printf("address: %x - has value %d\n", intpointer, *intpointer); //print the address of the 2nd element

    intpointer += 2; //now shift by two the point's address so it points to the 4th element in the array
    printf("address: %x - has value %d\n", intpointer, *intpointer); //print the addres of the 4th element
    }



    {
        int intarray[5] = {10,20,30,40,50};
        //-----------------------^
        int *pointer = &intarray[2];

        // Array of 3 pointers
        int *parray[3];

        // Copy last three addresses of intarray into parray
        // Use parray and pointer
        int i;
        for (i = 0; i < 3; i++) {
            // Insert code here
            parray[i] = pointer + i;
        }

        // Test code
        for (i = 0; i < 3; i++) {
            if (parray[i] == &pointer[i]) {
                printf("Matched!\n");
            } else {
                printf("Fail\n");
            }
        }
    }

    return 0;
}