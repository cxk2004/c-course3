/*
 * Calculator-01: fixed long length integer, based on array
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define INT_WIDTH   20

// Generate a random long integer
void generateLongInt( char longInt[] );

// Sum two long integers
int addTwoLongInts( char longInt1[], char longInt2[], char longIntSum[] );

// Display the long integer in a single line
void displayLongInt( char longInt[] );

int main( void)
{
    printf("\n");
    printf(" Calculator-01 : sum two long integer numbers\n");
    printf(" Data structure: char array\n");
    printf(" Assumption    : two intergers are in the same width (%d digit)\n", INT_WIDTH );
    printf("\n");

    srand( time(NULL) );
    char longInt1[ INT_WIDTH ] = {0};
    generateLongInt( longInt1 );
    char longInt2[ INT_WIDTH ] = {0};
    generateLongInt( longInt2 );
    
    char longIntSum[ INT_WIDTH ] = {0};
    int isOverflow = addTwoLongInts( longInt1, longInt2, longIntSum );

    if ( isOverflow == 0 )
    {
        printf("\n  ");;
        displayLongInt( longInt1 );
        printf("+ ");
        displayLongInt( longInt2 );
        printf("= ");
        displayLongInt( longIntSum );
    }
    else if ( isOverflow == 1 )
    {
        printf("\nError! addition overflow!\n");
    }

    printf("\n");
    return 0;
}

void generateLongInt( char longInt[] )
{
    // **********************************************
    // << Your source code starts here >>
    //
      int i ;
      for(i=0;i<INT_WIDTH -1 ;i++)
       {
         longInt[i]= rand()%10 + '0';
         while (longInt[0] == '0')
         {
            longInt[0]=rand()%10 + '0' ;
         }
         
       }
    //
    // << Your source code stops here >>
    // **********************************************

    printf("Generated (%d digit): ", INT_WIDTH);
    displayLongInt( longInt );

    return;
}


int addTwoLongInts( char longInt1[],  char longInt2[], char longIntSum[] )
{
    int isOverflow;

    // **********************************************
    // << Your source code starts here >>
    //
     int i,j;
     for(i=INT_WIDTH - 2; i > 0; i--)
     {
        longIntSum[i]+=('0' + longInt1[i] - '0' + longInt2[i] - '0');
        if(longIntSum[i]>'9')
        {
            longIntSum[i] -= 10;
            longIntSum[i-1] += 1;
        }
     }
    longIntSum[0] += ('0' + longInt1[0]-'0'+longInt2[0]-'0');
    if(longIntSum[0]>'9')
    {
        isOverflow = 1;
    }
    else
    {
        isOverflow = 0;

    }
    //
    // << Your source code stops here >>
    // **********************************************
    
    
    printf("Sum Result(%d digit): ", INT_WIDTH);
    displayLongInt( longIntSum );

    return isOverflow;
}


void displayLongInt( char longInt[] )
{
    int i;
    for ( i = 0; i < INT_WIDTH; i ++ )
    {
        printf("%c", longInt[i] );
    }
    printf("\n");

    return;
}
