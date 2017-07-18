#include <stdio.h>
#include <stdlib.h>
#define NUMCOLS 10

/* Puzzle D19 -- Count the number of duplicate values in a 2D array of ints */
int numberDuplicates( int x[][NUMCOLS], int nrows )
{
    int i,j,k,inRun,count;

    inRun=0;
    int array[nrows*NUMCOLS];
    k=0;
    count=0;
    for(i=0;i<nrows;i++)
    {
        for(j=0;j<NUMCOLS;j++)
        {
            array[k++]=x[i][j];
        }
    }
    selectionSort(array,nrows*NUMCOLS);
    for(k=0;k<nrows*NUMCOLS-1;k++)
        {
            if(!inRun&&array[k]==array[k+1])
                {
                    inRun=1;
                    count+=2;

                }
            else if(inRun && array[k]==array[k+1])
                count++;
            else
                inRun=0;
        }
    return count;
}

int selectionSort( int arr[], int size )
{
  int pass, j;
  int min, minj;

  for ( pass=0; pass<size-1; pass++ )
  {
    /* find the smallest remaining element in */
    /* arr[pass]... arr[size-1] */
    minj = pass;
    min  = arr[minj];
    for ( j=pass+1; j<size; j++ )
    {
      if ( arr[j] < min )
      {
        min = arr[j];
        minj = j;
      }
    }

    /* swap the smallest remaining element */
    /* with the element in arr[pass] */
    arr[minj] = arr[pass];
    arr[pass] = min;
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
  const int Nrows = 2 ;
  int x[2][NUMCOLS] ={ { 1, 3, 1, 1, 5, 8, -1, 1, 1, 1},
                       { 1, 7, 2, 1, 1, 1, 2, 1, 5, 9} };

  /* Print the array */
  print2DArray( x, Nrows );
  printf("\nNumber of duplicates: %d\n", numberDuplicates( x, Nrows ) );

  printf("\n");
  system("pause");
  return 0;
}
