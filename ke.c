#include<stdio.h>
int main(void)
{ 
    int a , b ,c ,d;
    double sum;
    printf("请输入4个整型数:  ",a,b,c,d);
    scanf("%d%d%d%d",&a,&b,&c,&d);
    sum = (double)(a+b+c+d)/4;
    printf("%d %d %d %d的平均值是%.2f",a,b,c,d,sum);



}