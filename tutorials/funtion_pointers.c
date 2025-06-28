#include <stdio.h>
#include <stdlib.h>

// void someFunction(int arg)
// {
//     printf("This is someFunction being called and arg is: %d\n", arg);
//     printf("Whoops leaving the function now!\n");
// }

// int compare(const void* left, const void* right)
// {
//     return (*(int*)right - *(int*)left);
//     // go back to ref if this seems complicated: http://www.cplusplus.com/reference/cstdlib/qsort/
// }


// int main()
// {
//     {
//     void (*pf)(int);
//     pf = &someFunction;
//     printf("We're about to call someFunction() using a pointer!\n");
//     (pf)(5);
//     printf("Wow that was cool. Back to main now!\n\n");
//     }   

//     {
//     int (*cmp) (const void* , const void*);
//     cmp = &compare;

//     int iarray[] = {1,2,3,4,5,6,7,8,9};
//     qsort(iarray, sizeof(iarray)/sizeof(*iarray), sizeof(*iarray), cmp);

//     int c = 0;
//     while (c < sizeof(iarray)/sizeof(*iarray))
//         {
//         printf("%d \t", iarray[c]);
//         c++;
//         }
//     }

//     return 0;
// }



void f1(int var)
    {
            printf("this is f1 and var is: %d\n", var);
    }

    void f2(int var)
    {
            printf("this is f2 and var is: %d\n", var);
    }

    void f3(int var)
    {
            printf("this is f3 and var is: %d\n", var);
    }

    int main()
    {
                /* define an array full of function pointers 
                to the above functions, that take an `int` as 
                their only argument */

        void (*fp[3])(int);
        fp[0] = &f1;
        fp[1] = &f2;
        fp[2] = &f3;

		int c = 0;
		while(c < 3)
		{
                        /* call the functions using the function pointers
                        of the array at index `c` with `c` as an argument */

            (fp[c])(c);
			++c;
		}

	  return 0;
    }