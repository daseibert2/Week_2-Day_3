#include <stdio.h>
#include <stdlib.h>
#define NUMCOLS 9

/* Puzzle D17 --  Initialize the diagonals of an NxM array */

int initDiagonals ( int x[][NUMCOLS], int nrows )
{
    int i,j,k;

    if (NUMCOLS<nrows)
        k=nrows;
    else
        k=NUMCOLS;
    for(i=0;i<NUMCOLS;i++)
    {
        for(j=0;j<nrows;j++){
            x[j][i]=k-abs(j-i);
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
  const int Nrows = 10 ;

  int x[Nrows][NUMCOLS];

  initDiagonals( x, Nrows );
  print2DArray( x, Nrows  );

  system("pause");
  return 0;
}
