/* Puzzle B01 -- print N random integers */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int j;
  int limit = 25;            /* Print this many random integers */
  unsigned int seed = 123;   /* Initializer for rand() */

  /* Use command line parameters if supplied */
  if ( argc == 3 )
  {
    limit = atoi( argv[1] );
    seed  = atoi( argv[2] );
  }

  /* Initialize the random number generator */
  srand( seed );

  /* Loop limit times, printing one random integer per iteration */
    for(j=0;j<limit;j++)
        printf("%d\n",rand());

  printf("\n");
  system("pause");
  return 0;
}
