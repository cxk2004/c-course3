#include <stdio.h>

double factorial_recursion( long number );

int main(void)
{
    int n ;
    printf("Please input a positive integer n:");
    scanf("%d", &n );

    if ( n < 1 )
    {
        printf("Error input value, program terminates.\n");
        return -1;
    }

    printf("\nCalling factorial_recursion():\n");
    printf("\n%d! = %.0lf \n\n", n, factorial_recursion( n ) );

	return 0;
}


double factorial_recursion( long x )
{
    static int k ;
    int i;
    double result;

    if ( x <= 1 )
    {
        for ( i = 0; i < k; i ++ )
        {
            printf("  ");
        }
        printf("factorial_recursion(1): return 1, the recursion end! \n");
        return 1;
    }
    else
    {
        for ( i = 0; i < k; i ++ )
        {
            printf("  ");
        }
        printf("factorial_recursion(%ld): calling factorial(%ld)\n", x, x - 1 );

        k ++;
        result = x * factorial_recursion(x-1);
        k --;

        for ( i = 0; i < k; i ++ )
        {
            printf("  ");
        }
        printf("factorial_recursion(%ld): return %.0lf \n", x, result );
        return result;
    }

}
