/* Puzzle B01 -- print N random integers */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[])
{
  int j,count;
  count=0;


  /* Initialize the random number generator */
  srand( time(NULL) );

  /* Loop limit times, printing one random integer per iteration */
    for(j=0;j<RAND_MAX*100;j++){
        if(rand()==RAND_MAX)
            count++;
    }

  printf("RAND_MAX occured %d times in 100*RAND_MAX trials",count);
  system("pause");
  return 0;
}

