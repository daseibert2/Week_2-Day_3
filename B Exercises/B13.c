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
int limit=35;
int max=8;
int length=50;

int main(int argc, char *argv[])
{
    int i,j,min,sent;
    int count,size=0;

    char word[ max+2 ] ;

    srand( time(NULL) );

    for(i=0;i<limit;i++)
    {
        size=0;
        sent=randInt(1,max);
        for(j=0;j<sent;j++)
        {
            if(size==1)
                min=2;
            else
                min=1;
            size=randWord(word,min,max);
            if(j==0&&randInt(0,9)==0)
                word[0]-='a'-'A';
            if(j==sent-1)
            {
                word[size]='.';
                word[size+1]='\0';
                size++;
            }
            if(size+count>length)
            {
                printf("\n");
                count=size+1;
            }
            else
            {
                count+=size+1;
            }
            printf("%s",word);
            printf(" ");
        }
        printf(" ");

    }
    printf("\n\n");
    return 0;
}

