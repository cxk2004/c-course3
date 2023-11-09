
#include <stdio.h>
#include<time.h>
#include<stdlib.h>
#define XSIZE 4
#define YSIZE 6
void resetArrae2D (int array[][YSIZE],int xsize,int ysize);
void displayArray2D(int array[][YSIZE],int xsize,int ysize);
void sortArrayBubble(int array[],int arraySize);
int searchArrayBinary(int array[],int key,int arraySize);
int main(void)
{
    srand(time(NULL));

    int a[XSIZE][YSIZE]={0};
    printf("Random reset the  2D array:\n");
    resetArrae2D(a,XSIZE,YSIZE);
    displayArray2D(a,XSIZE,YSIZE);
    printf("Sort the 2D array by 1D function\n");
    sortArrayBubble(a[0],XSIZE*YSIZE);
    displayArray2D(a,XSIZE,YSIZE);
    int searchKey = 0,searchResult ,x,y;
    printf("Please an integer to search:");
    scanf("%d",&searchKey);
    searchResult = searchArrayBinary(a[0],searchKey,XSIZE*YSIZE);   
    if(searchResult != -1)
    {
        x = searchResult/YSIZE;
        y = searchResult - x * YSIZE;
        printf("Found! a[%d][%d] = %d\n",x,y,searchKey);
    }
    else
    {
      printf("Not found!\n");
    }
    return 0;
}
void resetArrae2D (int array[][YSIZE],int xsize,int ysize)
{
    int i,j;
    for(i=0;i<xsize;i++)
    {
        for(j=0;j<ysize;j++)
        {
            array[i][j] = rand()%100;
        }
    }
}
void displayArray2D(int array[][YSIZE],int xsize,int ysize)
{
    int i,j;
    for(i=0;i<xsize;i++)
    {
        for(j=0;j<ysize;j++)
        {
            printf("%3d ",array[i][j]);
        }
        printf("\n");
    }
}
void sortArrayBubble(int array[],int arraySize)
{
    int i,j,temp;
    for(i=0;i<arraySize-1;i++)
    {
        for(j=0;j<arraySize-1-i;j++)
        {
            if(array[j]>array[j+1])
            {
                temp = array[j+1];
                array[j+1] = array[j];
                array[j] = temp;
            }
        }
    }
}
int searchArrayBinary(int array[],int key,int arraySize)
{
    int low = 0,high = arraySize - 1,middle;
    while(low<=high)
    {
       
        middle = (low + high)/2;
        printf("Binary search:low =%d,high = %d,middle = %d,x[%d] = %d\n",low,high,middle,middle,array[middle]);
        if(key == array[middle])
        {
            return  middle;
            
        }
        else if(key<array[middle])
        {
            high = middle - 1;
        }
        else
        {
            low = middle + 1;
        }
    }
    return -1;
}