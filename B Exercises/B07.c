#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double randInt( double min, double max )
{
  return(double) (rand()*(max-min))/(RAND_MAX) + min ;
}

int main(int argc, char *argv[])
{
  int i,j;
  double c[10][10];


  /* Initialize the random number generator */
  srand( time(NULL) );

    for(i=0;i<10;i++)
    {
       for(j=0;j<10;j++)
       {
           c[i][j]=(double)randInt(0.0,1.0);
           printf("%f ",c[i][j]);
           if(c[i][j]<=0)
            printf("*");
           else if(c[i][j]>=1)
            printf("*");
       }
    }
printf("\n");
  system("pause");
  return 0;
}

