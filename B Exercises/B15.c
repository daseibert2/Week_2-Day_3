#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


int randInt( int min, int max )
{
  return (rand()*(max-min+1))/(RAND_MAX+1) + min ;
}

int main(int argc, char *argv[])
{
    int i,j;
    int length=24;
    int limit=13;

    srand( time(NULL) );

    for(i=0;i<length;i++)
    {
        for(j=0;j<length;j++)
        {
            if(randInt(1,limit)==1)
                printf("*");
            else
                printf(".");
        }
        printf("\n");
    }
    printf("\n\n");
    return 0;
}
