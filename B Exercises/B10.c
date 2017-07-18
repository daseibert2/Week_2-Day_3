#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Puzzle B10 -- generate random doubles in the range
|  0 < = r < 100. Print the first one that is within
|  epsilon of 50.0, and print how many trials it took
|  to reach it.
*/

double randDoubleRange( double min, double max )
{
  return (max-min)*(rand()/(RAND_MAX+1.0)) + min;
}

const int limit = 10000000 ;
const double MIN=0.0, MAX= 100.0;
const double TARGET=50.0;
const double EPSILON= 1.0e-3;

int main(int argc, char *argv[])
{
  int j=0 ;
  double r ;
  srand( time(NULL) );

  printf("Target: %lf;  Epsilon: %9.7lf\n", TARGET, EPSILON );

  r = randDoubleRange( MIN, MAX ) ;
  while ( fabs( r-TARGET ) >= EPSILON && j<limit  )
  {
    r = randDoubleRange( MIN, MAX ) ;
    j++ ;
  }

  if ( j != limit )
    printf("Closest value: %18.15lf; occurred on trial: %d\n", r, j );
  else
    printf("No number within the limit in %d trials\n", limit );

  system("pause");
  return 0;
}

