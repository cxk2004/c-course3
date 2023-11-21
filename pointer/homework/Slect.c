#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void sortArray(int *x, int xsize);

int main(void)
{
    printf("Random reset the array:\n");
    srand(time(NULL));
    int array[10] = {0};
    int *p = array;
    for(int i = 0; i < 10; i++)
    {
        p[i] = rand() % 100;
        printf("%d ", p[i]);
    }
    printf("\n");
    printf("\nSort the array: Bubble Sort\n");
    printf("The sorted array is:\n");
    sortArray(p, 10);
}

void sortArray(int *x, int xsize) 
{
    int min_index, min_value;
    for(int i = 0; i < xsize - 1; i++)
    {
        printf("Pass %d:\n", i + 1);
        min_index = i;
        for(int j = i + 1; j < xsize; j++)
        {
            if(x[j] < x[min_index])
            {
                min_index = j;
            }
        }
        if(min_index != i)
        {
            min_value = x[min_index];
            x[min_index] = x[i];
            x[i] = min_value;
        }
        printf("Found the minimal element: x[%d] = %d\n", min_index, x[min_index]);
        printf("Elements swapped: x[%d] <--> x[%d]\n", i, min_index);
        printf("The sorted array is:\n");
    }
    for(int i = 0; i < xsize; i++)
    {
        printf("%d ", x[i]);
    }
    printf("\n");
}