#include <stdio.h>
#include <stdlib.h>
#define NUMCOLS 10

/* Puzzle D20 -- fill a 2D array with random ints, without any duplicates
|
|  Return 1 if successful, 0 if not. Failure is guaranteed if there
|  are fewer integers in the range low..high than there are elements
|  in the array.
|
*/
int randomFill2DUnique( int x[][NUMCOLS], int nrows, int low, int high )
{
    int r,c,i,j,unique,temp;
    if(NUMCOLS*nrows>high-low+1)
        return 0;

    for(r=0;r<nrows;r++)
        for(c=0;c<NUMCOLS;c++)
        {
            unique=0;
            while(!unique)
            {
                temp=randInt(low,high);
                unique=1;
                for(i=0;i<r&&unique;i++)
                    for(j=0;j<NUMCOLS&&unique;j++)
                        if(x[i][j]==temp)
                            unique=0;
                    for(j=0;j<c&&unique;j++)
                        if(x[i][j]==temp)
                            unique=0;
            }
            x[r][c]=temp;
        }
        return 1;

}

/* Generate a random integer  min <= r <= max */
int randInt( int min, int max )
{
  return (rand()*(max-min+1))/(RAND_MAX+1) + min ;
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

int numberDuplicates( int x[][NUMCOLS], int nrows )
{
  int r, c;     /* indexes to the current array element */
  int j;        /* index into array[] */
  int array[nrows*NUMCOLS];
  int duplicateCount = 0;
  int inRun = 0;

  /* Copy elements from x[][] to array[] */
  j = 0;
  for ( r=0; r<nrows; r++ )
    for ( c=0; c<NUMCOLS; c++ )
      array[ j++ ] = x[r][c];

  /* Sort the 1D array */
  selectionSort( array, nrows*NUMCOLS );

  /* Scan the 1D array for duplicates */
  for ( j=0; j<nrows*NUMCOLS; j++ )
  {
    if ( !inRun && array[j] == array[j+1] )
    {
      inRun = 1;
      duplicateCount += 2 ;
    }
    else if ( inRun && array[j] == array[j+1] )
      duplicateCount++ ;
    else if ( array[j] != array[j+1] )
      inRun = 0;
  }
  return duplicateCount;
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
  const int low = 0, high = 99;
  int x[Nrows][NUMCOLS] ;

  /* Fill the array with unique random integers */
  srand( time(NULL) );

  if ( !randomFill2DUnique( x, Nrows, low, high ) )
  {
    printf("Array is larger than range of values\n");
    system("pause");
    return 0;
  }

  /* Print the array */
  print2DArray( x, Nrows );
  printf("\nNumber of duplicates: %d\n", numberDuplicates( x, Nrows ) );

  printf("\n");
  system("pause");
  return 0;
}
