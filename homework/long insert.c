/*
 * Calculator-02: fixed long length real, based on string
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define REAL_WIDTH        25   // the width of real number includes the point/dot
#define POINT_POSITION    12

// Generate a random long real number
void generateLongReal( char longReal[] );

// Display the long integer in a single line
void displayLongReal( char longReal[] );

// sum two long real numbers
int addTwoLongReals( char longReal1[],  char longReal2[],  char longRealSum[]);

int main( void)
{
    printf("\n");
    printf(" Calculator-02 : sum two long real numbers with points\n");
    printf(" Data structure: char array, with one bit to store '.'\n");
    printf(" Assumption    : two real numbers are in the same width (%d digit)\n", REAL_WIDTH );
    printf("               : their points are also in the same position (No.%d bit)\n", POINT_POSITION);  
    printf("\n");

    srand( time(NULL) );

    char longReal1[ REAL_WIDTH ] = {0};
    generateLongReal( longReal1 );

    char longReal2[ REAL_WIDTH ] = {0};
    generateLongReal( longReal2 );

    char longRealSum[ REAL_WIDTH ] = {0};
    int isOverflow = addTwoLongReals( longReal1, longReal2, longRealSum );

    if ( isOverflow == 0 )
    {
        printf("\n  ");;
        displayLongReal( longReal1 );
        printf("+ ");
        displayLongReal( longReal2 );
        printf("= ");
        displayLongReal( longRealSum );
    }
    else if ( isOverflow == 1 )
    {
        printf("\nError! addition overflow!\n");
    }

    printf("\n");

    return 0;
}


void generateLongReal( char longReal[] )
{
    // **********************************************
    // << Your source code starts here >>
    //
    int i;
    for (i = 0; i < REAL_WIDTH; i++)
    {
        if (i == POINT_POSITION)
        {
            longReal[i] = '.';
        }
        else
        {
            longReal[i] = rand() % 10 + '0';
            while (longReal[0] == '0')
            {
                longReal[0] = rand() % 10 + '0';
            }
        }
    }
    //
    // << Your source code stops here >>
    // **********************************************

    printf("Generated (%d.%d): ", REAL_WIDTH, REAL_WIDTH - POINT_POSITION );
    displayLongReal( longReal );

}


int addTwoLongReals( char longReal1[],  char longReal2[],  char longRealSum[] )
{
    int isOverflow;
    
    // **********************************************
    // << Your source code starts here >>
    //
    int i, j, sum;
    int carry = 0;
    for (i = REAL_WIDTH - 1; i >= 0; i--)
    {
        if (longReal1[i] == '.')
        {
            longRealSum[i - 1] += carry;
            carry = 0;
            longRealSum[i] = '.';
        }
        else
        {
            sum = longReal1[i] - '0' + longReal2[i] - '0' + carry;
            if (sum >= 10)
            {
                carry = 1;
                sum = sum - 10;
            }
            else
            {
                carry = 0;
            }
            longRealSum[i] += (sum + '0');
        }
    }

    if (i == -1 && carry == 1)
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
    if( isOverflow == 0)
    {
    printf("Sum Result(%d.%d): ", REAL_WIDTH, REAL_WIDTH - POINT_POSITION );
    displayLongReal( longRealSum );
    }
    return isOverflow;
}

void displayLongReal( char longReal[] )
{
    int i;
    for ( i = 0; i < REAL_WIDTH; i ++ )
    {
        printf("%c", longReal[i] );
    }
    printf("\n");

}
