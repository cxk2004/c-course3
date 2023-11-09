#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// set random value for the elements of array
void setRandomArray( int array[], const int arraySize);

// shift the elements of array to right 
void shiftArray( int array[], const int arraySize, const int shiftLength);

// print the array
void displayArray( const int array[], const int arraySize);

int main()
{
    srand(time(NULL));

    const int size = 10;
    int array[size];

    printf("\nThe random array is:\n");
    setRandomArray( array, size);
    displayArray( array, size );

    int shiftLength = 1 + rand()%size;
    printf("\nThe shift length is %d", shiftLength);

    printf("\nThe shifted array is:\n");
    shiftArray( array, size, shiftLength );
    displayArray( array, size );

    return 0;
}

void displayArray( const int x[], const int xSize)
{
    int i ;
    for ( i = 0; i < xSize; i ++ )
    {
        printf("%4d", x[i] );
    }
    printf("\n");

    return;
}

void setRandomArray( int x[], const int xSize )
{
    int i;
    for ( i = 0; i < xSize; i ++ )
    {
        x[i] = 1 + rand()%100;
    }

    return;
}

void shiftArray( int x[], const int xSize, const int shiftLength)
{
  int i  ,temp[xSize];
  for(i=0;i<xSize;i++)
  {
    temp[i]=x[i];

  }
  for(i=0;i<xSize;i++)
  {
    x[(i+shiftLength)%xSize]=temp[i];
  }
}
