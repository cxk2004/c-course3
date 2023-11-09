

#include<stdio.h>
#include<stdlib.h>
#include<time.h>   
#define  ARRAY_SIZE 12 
void getRandArray(int array[], int arraySize);
void sortArray(int array[], int arraySize);
int findSerials(int array[], int arraySize);
int main(void)
{
    int array[ARRAY_SIZE];
    getRandArray(array,ARRAY_SIZE);
    sortArray(array,ARRAY_SIZE);
    int count = findSerials(array,ARRAY_SIZE);
    printf("Find total %d pairs",count);
    return 0;
}
void getRandArray(int  array[],int arraySize)
{
    int i ;
    srand(time(NULL));
    for(i=0;i<arraySize;i++)
    {
        array[i]=rand()%100+1;
    }
    for(i=0;i<arraySize;i++)
    {
        printf("%2d,",array[i]);
    }
    printf("\n");

}
void sortArray(int array[],int arraySize)
{
    int i,j,temp;
    for(i=0;i<arraySize-1;i++)
    {
        for(j=0;j<arraySize-1-i;j++)
        {
            if(array[j]>array[j+1])
            {
                temp=array[j];
                array[j]=array[j+1];
                array[j+1]=temp;

            }
        }
    }
}
int findSerials(int array[], int arraySize)
{
    int count=0;
    int i,j,k;
   for(i=0;i<arraySize-2;i++)
   {
     for(j=i+1;j<arraySize-1;j++)
     {
        for(k=j+1;k<arraySize;k++)
        {
            if(array[i]+array[k]==2*array[j])
            {
                printf("(%d,%d,%d)\n",array[i],array[j],array[k]);
                count++;
            }
        }
     }


   }
   return count;
}