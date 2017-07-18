#include <stdio.h>
#include <stdlib.h>

#define NUMCOLS 7
#define NUMROWS 4

/* Puzzle D12 -- Initialize a 2D array so that its diagonal is 0,
                 elements above the diagonal are 1,
                 and elements below the diagonal are -1. */

int initDiagonal( int x[][NUMCOLS], int nrows )
{
  int r,  c;

  for(r=0;r<nrows;r++)
  {
      for (c=0;c<NUMCOLS;c++)
      {
          if(r==c)
            x[r][c]=0;
         else if(c>r)
            x[r][c]=1;
          else
            x[r][c]=-1;
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

int main(int argc, char *argv[])
{
  int x [NUMROWS][NUMCOLS];

  initDiagonal( x, NUMROWS );
  printf("\n\nInitialized:\n");
  print2DArray( x, NUMROWS  );

  system("PAUSE");
  return 0;
}
