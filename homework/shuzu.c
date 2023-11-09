#include <stdio.h>
#include<time.h>
#include<stdlib.h>
#define XSIZE 4
#define YSIZE 6
void resetArrae2D (int array[][YSIZE],int xsize,int ysize);
void displayArray2D(int array[][YSIZE],int xsize,int ysize);
int getSeqOfMinimal(int array[][YSIZE],int xsize,int ysize);
int main(void)
{
    int a[XSIZE][YSIZE]={0};
    srand(time(NULL));
    printf("Random reset the  2D array:\n");
    resetArrae2D(a,XSIZE,YSIZE);
    displayArray2D(a,XSIZE,YSIZE);
    int xRange = 3;
    int yRange = 4;
    printf("Find minimal of %d*%d range in %d*%d array:\n",xRange,yRange,XSIZE,YSIZE);
    int minIndex = getSeqOfMinimal(a,xRange,yRange);
    int i = minIndex / YSIZE;
    int j = minIndex -i * YSIZE;
    printf("x[%d][%d] = %d\n",i,j,a[i][j]);
    printf("\n");
    return 0;
}
void resetArrae2D (int array[][YSIZE],int xsize,int ysize)
{
    int i,j;
    for(i=0;i<xsize;i++)
    {
        for(j=0;j<ysize;j++)
        {
            array[i][j]=rand()%100;
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
            printf("%2d ",array[i][j]);
        }
        printf("\n");
    }
}
int getSeqOfMinimal(int array[][YSIZE],int xsize,int ysize)
{
    int i,j;
    int min = array[0][0];
    int minIndex = 0;
    for(i=0;i<xsize;i++)
    {
        for(j=0;j<ysize;j++)
        {
            if(array[i][j]<min)
            {
                min = array[i][j];
                minIndex = i * YSIZE + j;
            }
        }
    }
    return minIndex;
}