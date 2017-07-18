#include <stdio.h>
#include <stdlib.h>

/* Puzzle D13 -- Transpose the elements of an array */
#define NUMCOLS 5

int transpose( int x[NUMCOLS][NUMCOLS] )
{
  int r,  c, temp ;

  for ( r=0; r<NUMCOLS; r++ )
    for ( c=0; c<r; c++ )
    {
      temp    = x[r][c];
      x[r][c] = x[c][r];
      x[c][r] = temp;
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

void fill2DArray ( int x[][NUMCOLS], int nrows )
{
  int r, c, count=0;

  for ( r=0; r<nrows; r++ )
    for ( c=0; c<NUMCOLS; c++ )
      x[r][c]  = count++ ;
}

int main(int argc, char *argv[])
{
  int x[NUMCOLS][NUMCOLS];

  fill2DArray( x, NUMCOLS );
  printf("Original:\n");
  print2DArray( x, NUMCOLS );
  transpose( x );
  printf("\n\nTransposed:\n");
  print2DArray( x, NUMCOLS  );

  system("pause");
  return 0;
}
