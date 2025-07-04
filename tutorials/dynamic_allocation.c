#include <stdio.h>
#include <stdlib.h>

/* Use malloc to dynamically allocate a point structure. */

typedef struct {
  int x;
  int y;
} point;

int main() {
  point * mypoint = NULL;

  /* Dynamically allocate a new point
     struct which mypoint points to here */
    mypoint = (point *) malloc(sizeof(point));

  mypoint->x = 10;
  mypoint->y =5 ;
  printf("mypoint coordinates: %d, %d\n", mypoint->x, mypoint->y);

  free(mypoint);
  return 0;
}