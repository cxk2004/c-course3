#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_REAL_WIDTH   25

typedef struct {
    char digits[MAX_REAL_WIDTH];
    int  pointPos;
    int  length;
} Real;

// **********************************************
// << Functions about struct of Real >>
// **********************************************

// Generate a random long real number
Real generateLongReal(void);

// Sum two long real numbers
Real addTwoLongReals(Real r1, Real r2);

// Get the pointPos of a real number
int getPointPos(Real r);

// Judge whether the long real number is valid, 1 for true, and 0 for false
int isLongRealValid(Real r);

// Display the real number in a single line
void displayAssignedLongReal(int pointPos, Real r);


// **********************************************
// << Functions about fixed length array >>
// **********************************************

// Shift the digits to right direction
void shiftDigitsToRight(char number[], int shiftLength);

// Shift the digits to left direction
void shiftDigitsToLeft(char number[], int shiftLength);

// Display the number in a fixed width
void displayFixedWidthNumber(char number[], const int width);


int main(void)
{

    printf("Calculator-04 : sum two long real numbers with points\n");
    printf(" Data structure: a struct (Real): char array (digits[]), integer (length), integer (pointPos)\n");
    printf(" Assumption    : two real numbers are with different width (less than %d digits)\n", MAX_REAL_WIDTH);
    printf("               : and different points position, not support for addition promotion\n");
    printf("\n");

    int SEED;
    scanf("%d", &SEED);
    srand(SEED);

    Real real1 = generateLongReal();
    Real real2 = generateLongReal();
    Real realSum = addTwoLongReals(real1, real2);

    int pointPos = 0;
    if (isLongRealValid(realSum) == 1)
    {
        pointPos = getPointPos(realSum);
        printf("\n  ");
        displayAssignedLongReal(pointPos, real1);
        printf("+ ");
        displayAssignedLongReal(pointPos, real2);
        printf("= ");
        displayAssignedLongReal(pointPos, realSum);
    }
    else
    {
        printf("\nError! addition overflow!\n");
    }
    printf("\n");

    return 0;
}

// **********************************************
// << Functions about struct of Real >>
// **********************************************

Real generateLongReal(void)
{

    Real r;
    r.length = 2 + rand() % (MAX_REAL_WIDTH - 1); // 1 stands for the bit of pointer/dot
    r.pointPos = 1 + rand() % (r.length);

    r.digits[0] = '1' + rand() % 9;

    int i;
    for (i = 1; i < r.length - 1; i++)
    {
        r.digits[i] = '0' + rand() % 10;
    }
    r.digits[r.length - 1] = '1' + rand() % 9;
    r.digits[r.pointPos - 1] = '.';

    // clear the rest of the memory
    for (i = r.length; i < MAX_REAL_WIDTH; i++)
    {
        r.digits[i] = '\0';
    }

    printf("Generated (%2d.%2d): ", r.length, r.length - r.pointPos);
    displayFixedWidthNumber(r.digits, MAX_REAL_WIDTH);

    return r;
}

// **********************************************
// << Your source code starts here >>
//
Real addTwoLongReals(Real real1, Real real2)
{
    int rightLength = ( real1.length - real1.pointPos > real2.length - real2.pointPos ) ? real1.length - real1.pointPos : real2.length - real2.pointPos ;
    shiftDigitsToRight( real1.digits , MAX_REAL_WIDTH - rightLength - real1.pointPos );
    shiftDigitsToRight( real2.digits , MAX_REAL_WIDTH - rightLength - real2.pointPos );
    Real sum , initial1 = real1 , initial2 = real2 ;
    int i , n[MAX_REAL_WIDTH] = {0} ;
    if ( real1.digits[0] != '\0' && real2.digits[0] != '\0' )
    {
        sum.length = MAX_REAL_WIDTH ;
        sum.pointPos = sum.length - rightLength ;
    }
    for ( i = MAX_REAL_WIDTH - 1 ; i >= 0 ; i -- )
    {
        if ( i == MAX_REAL_WIDTH - rightLength - 1 )
        {
            sum.digits[i] = '.' ;
            continue;
        }
        if ( real1.digits[i] == '\0' && real2.digits[i] == '\0' )
        {
            sum.length = MAX_REAL_WIDTH - i - 1 ;
            sum.pointPos = sum.length - rightLength ;
            if ( n[i] != 0 )
            {
                sum.digits[i] = n[i] + '0' ;
                sum.length ++ ;
                sum.pointPos ++ ;
            }
            break;
        }
        if ( real1.digits[i] == '\0' )
        {
            real1.digits[i] = '0' ;
        }
        if ( real2.digits[i] == '\0' )
        {
            real2.digits[i] = '0' ;
        }
        n[i] += real1.digits[i] - '0' + real2.digits[i] - '0' ;
        if ( n[i] > 9 && i > 0 )
        {
            if ( i == MAX_REAL_WIDTH - rightLength )
            {
                n[i-2] ++ ;
            }
            else
            {
                n[i-1] ++ ;
            }
            n[i] -= 10 ;
        }
        sum.digits[i] = n[i] + '0' ;
    }
    if ( sum.digits[0] > '9' )
    {
        sum.length = -1 ;
    }
    else
    {
        real1 = initial1 ;
        real2 = initial2 ;
        for ( i = 0 ; i < MAX_REAL_WIDTH - sum.length ; i ++ )
        {
            sum.digits[i] = '\0' ;
        }
        printf("Sum Result(%2d.%2d): ", sum.length , sum.length - sum.pointPos );
        displayFixedWidthNumber(sum.digits, MAX_REAL_WIDTH);
        shiftDigitsToLeft( sum.digits , MAX_REAL_WIDTH - sum.length );
        int shiftLength1 = MAX_REAL_WIDTH - real1.length - ( rightLength - ( real1.length - real1.pointPos ) ) ;
        shiftDigitsToLeft( real1.digits , shiftLength1 );
        int shiftLength2 = MAX_REAL_WIDTH - real2.length - ( rightLength - ( real2.length - real2.pointPos ) ) ;
        shiftDigitsToLeft( real2.digits , shiftLength2 );
    }
    return sum;
}
//
// << Your source code stops here >>
// **********************************************


int getPointPos(Real r)
{
    return  r.pointPos;
}


int isLongRealValid(Real r)
{
    return (r.length > 0) ? 1 : 0;
}


void displayAssignedLongReal(int pointPos, Real r)
{
    int i;
    for (i = 0; i < pointPos - r.pointPos; i++)
    {
        printf(" ");
    }
    for (i = 0; i < r.length; i++)
    {
        printf("%c", r.digits[i]);
    }
    printf("\n");

    return;
}


// **********************************************
// << Functions about fixed length array >>
// **********************************************

void shiftDigitsToRight(char longNumber[], int shiftLength)
{
    if (MAX_REAL_WIDTH - 1 < shiftLength || shiftLength < 0)
    {
        printf("Range error. Program terminated.\n");
        exit(-10);
    }

    int i;
    for (i = MAX_REAL_WIDTH - 1; i - shiftLength >= 0; i--)
    {
        longNumber[i] = longNumber[i - shiftLength];
    }
    for (; i >= 0; i--)
    {
        longNumber[i] = '\0';
    }

    printf("shiftRight (%2d)  : ", shiftLength);
    displayFixedWidthNumber(longNumber, MAX_REAL_WIDTH);

    return;
}


void shiftDigitsToLeft(char longNumber[], int shiftLength)
{
    if (MAX_REAL_WIDTH - 1 < shiftLength || shiftLength < 0)
    {
        printf("Range error. Program terminated.\n");
        exit(-10);
    }

    int i;
    for (i = 0; i + shiftLength < MAX_REAL_WIDTH; i++)
    {
        longNumber[i] = longNumber[i + shiftLength];
    }
    for (; i < MAX_REAL_WIDTH; i++)
    {
        longNumber[i] = '\0';
    }

    printf("shiftLeft  (%2d)  : ", shiftLength);
    displayFixedWidthNumber(longNumber, MAX_REAL_WIDTH);

    return;
}


void displayFixedWidthNumber(char number[], const int width)
{
    int i;
    for (i = 0; i < width; i++)
    {
        if (number[i] == '\0')
        {
            printf("_");
        }
        else
        {
            printf("%c", number[i]);
        }
    }
    printf("\n");

    return;
}