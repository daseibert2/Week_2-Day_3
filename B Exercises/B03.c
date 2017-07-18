#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[])
{
  int j;


  /* Initialize the random number generator */
  srand( time(NULL) );

    for(j=0;j<10;j++)
    {
       printf("%d\n",rand()%10);
    }

  system("pause");
  return 0;
}
