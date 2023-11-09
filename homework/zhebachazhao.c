#include<stdio.h>
#define SIZE 15

int binarySearch(const int b[],int searchKey,int low ,int high);
void printHeader(void);
void printRow(const int b[],int low,int mid,int high);

int main(void)
{
    int a[SIZE];
    int i;
    int key;
    int result;
    for( i=0;i<SIZE;i++)
    {
        a[i] =2 * i;
    }  
    printf("Enter a number between 0 and 28:");
    scanf("%d", &key);
    printHeader();
    result = binarySearch(a,key,0,SIZE - 1);

    if( result != -1)
    {
        printf("\n%d found in arrar element %d\n",key,result);
    }
    else
    {
        printf("\n%d not found\n",key);
    }
    return 0;

}
int binarySearch(const int b[],int searchKey,int low ,int high)
{
    int middle;
    while (low<=high)
    {
       middle = (low + high)/2;
       printRow(b,low,middle,high);
       if(searchKey == b[middle])
       {
        return middle;
       }
       else if(searchKey<b[middle])
       {
        high=middle - 1;
       }
       else
       {
        middle = low + 1;
       }
    }
    return -1;
}
void printRow(const int b[],int low,int mid,int high)
{
   
}
void printHeader(void)
{
  
}