#include <stdio.h>
#include <stdlib.h>
#define NUMCOLS 9

/* Puzzle D18 -- Determine if any element in a 2D array is duplicated  */

int isDuplicate( int x[][NUMCOLS], int nrows )
{
    int i,j,k,l,target;
    for(i=0;i<nrows;i++)
    {
        for(j=0;j<NUMCOLS;j++)
        {
            target=x[i][j];
            for(l=j+1;l<NUMCOLS;l++)
                if(target==x[i][l])
                return 1;
            for(k=i+1;k<nrows;k++)
            {
                for(l=0;l<NUMCOLS;l++)
                {
                    if(target==x[k][l])
                    {
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}

void print2DArray ( int x[][NUMCOLS], int nrows )
{
  int r, c;  /* row and column indexes for the array */

  /* Print elements in row major order */
  for ( r=0; r<nrows; r++ )
  {
    for ( c=0; c<NUMCOLS; c++ )
      printf("%3d ", x[r][c]  );
    printf("\n");
  }
}

int main(int argc, char *argv[])
{
  const int Nrows = 4 ;

  int x[4][10] ={ {  0,  2,  3,  4,  5,  6,  7,  8,  9, 10},
                  { 11, 12, 13, 14, 15, 31, 17, 18, 19, 20},
                  { 21, 22, 23, 24, 25, 26, 27, 28, 29, 30},
                  { 31, 32, 33, 34, 35, 36, 37, 38, 39, 40 } };

  print2DArray( x, Nrows );

  if ( isDuplicate( x, Nrows ) )
    printf("\nThere is a duplicate.\n\n");
  else
    printf("\nThere are no duplicates.\n\n");

  system("pause");
  return 0;
}
