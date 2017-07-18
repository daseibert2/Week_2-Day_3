#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int randInt( int min, int max )
{
  return (rand()*(max-min+1))/(RAND_MAX+1) + min ;
}

int main(int argc, char *argv[])
{
  int i,j;
  int c[10][10];


  /* Initialize the random number generator */
  srand( time(NULL) );

    for(i=0;i<10;i++)
    {
       for(j=0;j<10;j++)
       {
           c[i][j]=randInt(50,100);
           printf("%d ",c[i][j]);
       }
    }
printf("\n");
  system("pause");
  return 0;
}
