#include <stdio.h>
#include <stdlib.h>

/* Puzzle D14 -- Rotate the elements of a 2D array */
#define NUMCOLS 5
#define NUMROWS 3

void rotate2D ( int x[][NUMCOLS], int nrows )
{
  int r, c, elmnt00;

  elmnt00 = x[0][0];
  for ( r=0; r<nrows; r++ )
    for ( c=0; c<NUMCOLS; c++ )
      if( c>=1 )
        x[r][c-1] = x[r][c];
      else if ( r>=1 )
        x[r-1][NUMCOLS-1] = x[r][c];

  x[nrows-1][NUMCOLS-1] = elmnt00 ;
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
  rotate2D( x, NUMCOLS );
  printf("\n\nRotated:\n");
  print2DArray( x, NUMCOLS  );

  system("pause");
  return 0;
}
