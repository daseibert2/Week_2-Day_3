#include <stdio.h>
#include <stdlib.h>

#define NUMCOLS 4
#define NUMROWS 8

/* Puzzle D11 -- reverse the order of the elements in a 2D array */

int reverse2D( int x[][NUMCOLS], int nrows )
{
    int r,c;
    int temp;

    for(r=0;r<nrows/2;r++)
    {
        for(c=0;c<NUMCOLS;c++)
        {
            temp=x[r][c];
            x[r][c]=x[nrows-1-r][NUMCOLS-1-c];
            x[nrows-1-r][NUMCOLS-1-c]=temp;
        }
    }
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

void rasterFill2DArray ( int x[][NUMCOLS], int nrows )
{
  int r, c;

  for ( r=0; r<nrows; r++ )
    for ( c=0; c<NUMCOLS; c++ )
      x[r][c] = r*10+c;
}

int main(int argc, char *argv[])
{
  int x[NUMROWS][NUMCOLS];
  rasterFill2DArray( x, NUMROWS );

  printf("Original:\n");
  print2DArray( x, NUMROWS );

  printf("\n\nReversed:\n");
  reverse2D(x, NUMROWS );
  print2DArray( x, NUMROWS );

  system("pause");
  return 0;
}
