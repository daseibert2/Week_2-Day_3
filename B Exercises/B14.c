#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


int randInt( int min, int max )
{
  return (rand()*(max-min+1))/(RAND_MAX+1) + min ;
}

char randChar()
{
    return 'a'+randInt(0,25);
}

int randWord(char word[],int minWordSize,int maxWordSize)
{
  int size,j;

  size = randInt(minWordSize,maxWordSize);

  for(j=0;j<size;j++)
    word[j] =randChar();

  word[size] ='\0';

  return size;
}


int main(int argc, char *argv[])
{
    long j=0;
    int count=0;
    int max=5;
    char target[]="hello";
    char word[max+1] ;

    srand( time(NULL) );

    while(!j)
    {
        count++;
        randWord(word,max,max);
        if(strncmp(target,word,sizeof(word))==0)
        {
            printf("\nword = %s, count = %ld\n",word,count);
            j=1;
        }
        if(count%5000000==0)
            printf("*\n");
        else if(count%100000==0)
        printf("*");
    }
    printf("\n\n");
    return 0;
}

