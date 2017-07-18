#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Puzzle B08 -- print N random doubles MIN <= d < MAX */
double randDoubleRange( double min, double max )
{
  return (max-min)*(rand()/(RAND_MAX+1.0)) + min;
}

const int limit = 100 ;
const double MIN=5.0, MAX= 10.0;

int main(int argc, char *argv[])
{
  int j=0 ;
  double r;
  srand( time(NULL) );

  for ( j=0; j < limit; j++ )
  {
    r = randDoubleRange(MIN, MAX) ;
    printf("% 12.10lf", r );
    if ( j%5 == 4 ) printf("\n");
  }

  printf("\n");
  system("pause");
  return 0;
}
