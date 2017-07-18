#include <stdio.h>
#include <stdlib.h>

int main()
{
    int * points;
    points=(int *)malloc(5*sizeof(int)); //get memory from the heap, reserve space for 5 ints
    free(points); //puts memory back

    return 0;
}
