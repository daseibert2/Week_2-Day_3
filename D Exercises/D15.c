#include <stdio.h>
#include <stdlib.h>

/* Puzzle D15 -- Rotate the elements of a 2D array by N positions */
#define NUMCOLS 5
#define NUMROWS 3

void rotate2D ( int x[][NUMCOLS], int nrows, int N )
{
  int j ;

  /* Save the first N entries */
  int temp[N];
  for ( j=0; j<N; j++ )
    temp[j] = x[0][j];

  /* Slide elements down */
  for ( j=0; j<nrows*NUMCOLS-N; j++ )
    x[0][j] = x[0][j+N];

  /* Copy first N entries to last N positions */
  for ( j=0; j<N; j++ )
    x[0][nrows*NUMCOLS-N+j] = temp[j];

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
  int num;

  printf("Move How Many?\n");
  scanf("%d",&num);

  if (num>NUMCOLS*NUMROWS)
    return 0;
  else
  {

    fill2DArray( x, NUMCOLS );
    printf("Original:\n");
    print2DArray( x, NUMCOLS );
    rotate2D( x, NUMCOLS,num );
    printf("\n\nRotated:\n");
    print2DArray( x, NUMCOLS  );
  }

  system("pause");
  return 0;
}

