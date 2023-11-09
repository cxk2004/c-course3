#include <stdio.h>
#include <stdlib.h>
// **********************************************
// << Your source code starts here >> 
// power_recursion( base, exponent ) 函数声明
double power_recursion(int base, int exponent);
//
//
// << Your source code stops here >>
// **********************************************


int main( void )
{
    int base;
    //printf("Please input an integer number as base:");
    scanf("%d", &base );

    int exponent;
    //printf("Please input a positive integer number as exponent:");
    scanf("%d", &exponent );

    if ( exponent < 1 )
    {
        printf("Error input value, program terminates.\n");
        return -1;
    }

    //printf("\nCalling power_recursion():\n");
    printf(" %d ^ %d = %.0lf \n", base, exponent, 
    	power_recursion( base, exponent ) );

    return 0;
}
double power_recursion(int base, int exponent)
{
    if(exponent ==1)
    {
        return (double)base;
    }
    else
    {
        return base*power_recursion(base , exponent - 1);
    }
}


// **********************************************
// << Your source code starts here >>
// power_recursion( base, exponent ) 函数


//
// << Your source code stops here n>>
// **********************************************
    

