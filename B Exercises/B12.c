#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


int randInt( int min, int max )
{
  return (rand()*(max-min+1))/(RAND_MAX+1) + min ;
}

char randChar()
{
    return 'a'+randInt(0,25);
}

int limit=50;
int max=8;

int main(int argc, char *argv[])
{
    int i,j,k;
    for(i=0;i<limit;i++)
    {
        for(j=0;j<10;j++)
        {
            for(k=0;k<randInt(1,max);k++)
            {
                printf("%c",randChar());
            }
            printf(" ");
        }
        printf("\n");
    }

    return 0;
}
