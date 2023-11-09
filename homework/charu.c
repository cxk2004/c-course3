
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void sortArray( int array[], int xsize );


int main(void)
{
   printf("Random reset the array:\n");
   srand( time(NULL) );
    int array[10]={0};
    int i;
    for(i=0;i<10;i++)
    {
        array[i]=rand()%100;
        printf("%d ",array[i]);
    }
    printf("\n");
    printf("\nSort the array: Insertion Sort\n");
    printf("The sorted array is:\n");
    sortArray(array,10);
}
void sortArray(int x[], int xsize) 
{
    int i , j,insert_value,is_inserted;
    is_inserted = 0;
    for(i = 1;i<xsize;i++)
    {
        insert_value = x[i];
        is_inserted = 0;
        for( j =i - 1;(j>=0)&&(x[j]>insert_value);j--)
        {
            x[j+1] = x[j];
        }
        if(j != i-1)
        {
            x[j+1] = insert_value;
            is_inserted = 1;
        }
        printf("\nPass %d: current x[%d] = %d\n", i,i,insert_value);
        if(is_inserted)
        {
             printf("Element  insert to  x[%d] = %d\n",i,insert_value);
        
        }
        else
        {
            printf("No requirment to insert x[%d] = %d\n",i,insert_value);
           
        }
        for(int k = 0;k<i+1;k++)
        {
            if(k ==j+1)
            {
                printf("%d* ",x[k]);
            }
            else
            {
            printf("%d ",x[k]);
            }
        }

    }
    printf("\n");
    printf("The sorted array is:\n");
    for(i = 0;i<xsize;i++)
    {
        printf("%d ",x[i]);
    }
}