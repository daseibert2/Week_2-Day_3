#include <stdio.h>
#include <stdlib.h>
#include <time.h>

  int j,temp,max;
    int c[]={0,0,0,0,0,0,0,0,0,0};
    int nc[10];

int main(int argc, char *argv[])
{

  /* Initialize the random number generator */
  srand( time(NULL) );

    generate();
    max=findMax();
    plot(max);

  system("pause");
  return 0;
}

void generate()
{
    for(j=0;j<500;j++)
    {
       temp=rand()%10;
       c[temp]++;
    }
}

int findMax()
{
    int max=-10000000000;
    int i;
    for(i=1;i<10;i++)
    {
        if(c[i]>max)
            max=c[i];
    }
    return max;
}

void plot(int max)
{
    int j,s;
    int barWidth=50;
    for(j=0;j<10;j++)
    {
        printf("%d (\t%d):\t",j,c[j]);
        for(s=0;s<c[j]*barWidth/max;s++){
            printf("*");
        }
        printf("\n");
    }
}
