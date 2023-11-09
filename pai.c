#include<stdio.h>
#include<math.h>
int main(void)
{
    double pi = 0;
    double denominator = 1;
    int sign =1;
    double value =1;
    int i = 1;
    while (fabs(value)>1E-7)
    {
        pi = pi+value;
        denominator +=2;
        sign*= -1;
        value = sign/denominator;
        printf("[3%d] 1/(4n-1) =  %16.13f,pi = %18.15f\n",i++,value,pi*4.0 ); 
    }
    printf("final:pi = %1f\n\n",pi*4.0);


}