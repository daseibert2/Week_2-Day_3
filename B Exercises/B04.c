#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[])
{
  int j,temp;
    int c[]={0,0,0,0,0,0,0,0,0,0};
  /* Initialize the random number generator */
  srand( time(NULL) );

    for(j=0;j<500;j++)
    {
       temp=rand()%10;
        c[temp]++;

    }
printf("0:\t%d\n",c[0]);
printf("1:\t%d\n",c[1]);
printf("2:\t%d\n",c[2]);
printf("3:\t%d\n",c[3]);
printf("4:\t%d\n",c[4]);
printf("5:\t%d\n",c[5]);
printf("6:\t%d\n",c[6]);
printf("7:\t%d\n",c[7]);
printf("8:\t%d\n",c[8]);
printf("9:\t%d\n",c[9]);
  system("pause");
  return 0;
}

