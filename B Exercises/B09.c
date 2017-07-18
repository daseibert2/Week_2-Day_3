#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

/* Puzzle B09 -- print the number out of of N random doubles 0 <= d < 100
  that is closest to 50.0*/

double randDoubleRange( double min, double max )
{
  return (max-min)*(rand()/(RAND_MAX+1.0)) + min;
}

const int limit = 10000 ;
const double MIN=0.0, MAX= 100.0;
const double target=50.0;

int main(int argc, char *argv[])
{
  int j=0 ;
  double r, f;
  double minDifference = MAX;
  double closest;

  srand( time(NULL) );

  for ( j=0; j<limit; j++ )
  {
    r = randDoubleRange(MIN, MAX);

    if ( (f = fabs(target-r) ) < minDifference )
    {
      minDifference = f ;
      closest = r;
    }
  }

  printf("Closest: %lf; difference: %lf\n", closest, minDifference );
  system("pause");
  return 0;
}
