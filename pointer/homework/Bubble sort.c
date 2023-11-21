#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void sortArray(int *array, int size);
int main(void)
{
    printf("Random reset the array:\n");
    srand(time(NULL));
    int array[10] = {0};
    int *p;
    for(p = array; p < array + 10; p++)
    {
        *p = rand() % 100;
        printf("%d ", *p);
    }
    printf("\n");
    printf("\nSort the array: Bubble Sort\n");
    printf("The sorted array is:\n");
    sortArray(array, 10);
}
void sortArray(int *x, int xsize) 
{
    int *i, *j, temp, isSwapped;
    for (i = x; i < x + xsize - 1; i++) 
    {
        printf("Pass %d:\n", (i - x) + 1);
        isSwapped = 0;
        for (j = x; j < x + xsize - (i - x) - 1; j++) 
        {
            printf("Elements comparison: x[%d] vs. x[%d]\n", (j - x), (j - x) + 1);
            if (*j > *(j + 1)) 
            {
                printf("Elements swapped: %d <--> %d\n", *j, *(j + 1));
                temp = *j;
                *j = *(j + 1);
                *(j + 1) = temp;
                isSwapped = 1;
            }
        }
        if (!isSwapped) 
        {
            break;
        }
    }
    printf("The sorted array is:\n");
    for (i = x; i < x + xsize; i++) 
    {
        printf("%d ", *i);
    }
    printf("\n");
}