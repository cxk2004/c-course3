
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
    printf("\nSort the array: Bubble Sort\n");
    printf("The sorted array is:\n");
    sortArray(array,10);
}
void sortArray(int x[], int xsize) {
    int i, j, temp, isSwapped;
    for (i = 0; i < xsize - 1; i++) 
    {
        printf("Pass %d:\n", i + 1);
        isSwapped = 0;
        for (j = 0; j < xsize - i - 1; j++) 
        {
           
           
            printf("Elements comparison: x[%d] vs. x[%d]\n", j, j + 1);
            if (x[j] > x[j + 1]) {
                printf("Elements swapped: %d <--> %d\n", x[j], x[j + 1]);
                temp = x[j];
                x[j] = x[j + 1];
                x[j + 1] = temp;
                isSwapped = 1;
            }
        }
        if (!isSwapped) {
            break;
        }
    }
    printf("The sorted array is:\n");
    for (i = 0; i < xsize; i++) {
        printf("%d ", x[i]);
    }
    printf("\n");
}