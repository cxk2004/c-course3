#include <stdio.h>
void main()
{
    int a[4][3] = {{1,2,3}, {10,20,30}, {4,5,6}, {11,12,13}};
int (*p)[3];
p = a;
printf("%d, %d", *(*(p+1)+1), *((p+1)+1));

}