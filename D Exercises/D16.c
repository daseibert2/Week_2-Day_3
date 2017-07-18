#include <stdio.h>
#include <stdlib.h>
#define NUMCOLS 9

/* Puzzle D16 -- Zero the edges of an Array
|
| Change the elements of the outer rows and
| columns of an array to zero. Leave all other
| elements unaffected.
|
*/

int zeroEdges ( int x[][NUMCOLS], int nrows )
{
  int j;
  /* row: 0 */
    for(j=0;j<NUMCOLS;j++){
        x[0][j]=0;
    }
  /* row: nrows-1 */
    for(j=0;j<NUMCOLS;j++){
        x[nrows-1][j]=0;
    }
  /* column: 0 */
  for(j=0;j<nrows;j++){
        x[j][0]=0;
    }

  /* column: NUMCOLS-1 */
  for(j=0;j<nrows;j++){
        x[j][NUMCOLS-1]=0;
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
  const int Nrows = 9 ;

  int x[Nrows][NUMCOLS];

  fill2DArray( x, Nrows );
  printf("Original:\n");
  print2DArray( x, Nrows );

  zeroEdges( x, Nrows );

  printf("\n\Rotated:\n");
  print2DArray( x, Nrows  );
  printf("\n");
  system("pause");
  return 0;
}
