
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ARRAY_SIZE       10
#define MAX_FACTORS_NUM  10
typedef struct{
    int value;
    int factors[MAX_FACTORS_NUM];
    int numFactors;
    int distinctFactors[MAX_FACTORS_NUM];
    int numDistinctFactors;
} Integer;
void setIntegerArray( Integer [], const int arraySize, const int initialValue);
void getIntegerFactors( Integer [], const int arraySize);
void getIntegerDistinctFactors( Integer [], const int arraySize);
void sortIntegerByDistinctFactors( Integer [], const int arraySize);
void displayFactors( const int value, const int factors[], const int numFactors);
int main(void)
{
    srand(time(NULL));
    int initial = 100 + rand() % 100;
    printf("\nfactorization analysis: from %d to %d \n", initial + 1, initial + ARRAY_SIZE );
    Integer array[ARRAY_SIZE];
    setIntegerArray( array, ARRAY_SIZE, initial );
    int i;
    getIntegerFactors( array, ARRAY_SIZE );
    printf("results of primary factors:\n");
    for ( i = 0; i < ARRAY_SIZE; i ++ )
    {
        displayFactors( array[i].value, array[i].factors, array[i].numFactors );
    }
    getIntegerDistinctFactors( array, ARRAY_SIZE );
    printf("results of distinct factors:\n");
    for ( i = 0; i < ARRAY_SIZE; i ++ )
    {
        displayFactors( array[i].value, array[i].distinctFactors, array[i].numDistinctFactors );
    }
    sortIntegerByDistinctFactors( array, ARRAY_SIZE );
    printf("sorting by number of distinct factors:\n");
    for ( i = 0; i < ARRAY_SIZE; i ++ )
    {
        displayFactors( array[i].value, array[i].distinctFactors, array[i].numDistinctFactors );
    }
    printf("%d has the maximal number that has maximal (%d) number of distinct primary factors.\n", 
           array[ARRAY_SIZE - 1].value, array[ARRAY_SIZE - 1].numDistinctFactors );
    return 0;
}
void setIntegerArray( Integer array[], const int arraySize, const int initialValue)
{
    int i, j;
    for ( i = 0; i < arraySize; i ++ )
    {
        array[i].value = initialValue + 1 + i; 
        for ( j = 0; j < MAX_FACTORS_NUM; j ++ )
        {
            array[i].factors[j] = 0;
            array[i].distinctFactors[j] = 0;
        }
        array[i].numFactors = 0;
        array[i].numDistinctFactors = 0;
    }
}
void getIntegerFactors( Integer array[], const int arraySize)
{
   int i,j,k;
   for(i = 0;i<arraySize;i++)
   {
    int originalValue= array[i].value;
    k = 0;
    for(j = 2;j<= originalValue;j++)
    {
        while (originalValue % j ==0)
        {
            array[i].factors[k] =j;
            originalValue = originalValue / j;
            k = k + 1;
        }
    }
    if (k == 0)
    {
        array[i].factors[k] = array[i].value;
        k = k + 1;
    }
    array[i].numFactors = k;
   }
}
   

void getIntegerDistinctFactors( Integer array [], const int arraySize)
{
  int i,j,k;
  for(i=0;i<arraySize;i++)
  {
    int k = 0;
    for(j=0;j<array[i].numFactors;j++)
    {
        if(j == 0 || array[i].factors[j] != array[i].factors[j-1])
        {
            
            array[i].distinctFactors[k] = array[i].factors[j];
            k = k + 1;
        }
    }
    array[i].numDistinctFactors = k;
  }
}
void sortIntegerByDistinctFactors( Integer array [], const int arraySize)
{
 int i,j;
    for(i=0;i<arraySize-1;i++)
     {
        for(j=0;j<arraySize-i-1;j++)
          {
            if(array[j].numDistinctFactors<array[j+1].numDistinctFactors
               ||array[j].numDistinctFactors==array[j+1].numDistinctFactors&&array[j].value>array[j+1].value)
              {
                Integer temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
              }     
  
          }
     }
}
void displayFactors( const int value, const int factors[], const int numFactors)
{
    printf("    %3d [%d]:", value, numFactors );
    int i;
    for ( i = 0; i < numFactors - 1; i ++ )
    {
        printf(" %d,", factors[i] );
    }
    printf(" %d\n", factors[i] );
    return;
}