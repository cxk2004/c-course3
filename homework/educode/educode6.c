#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_REAL_WIDTH   25
 //#define DEBUG_PROMOTION  

typedef struct {
    char digits[MAX_REAL_WIDTH];
    int  pointPos;
    int  length;
} Real;

// **********************************************
// << Functions about struct of Real >>
// **********************************************

// Generate a random long real number
void generateLongReal(Real* rPtr);

// Sum two long real numbers
int addTwoLongReals(const Real* rPtr1, const Real* rPtr2, Real* rPtrSum);

// Get the pointPos of a real number
int getPointPos(Real* rPtr);

// Display the real number in a single line
void displayAssignedLongReal(int pointPos, Real* rPtr);

// **********************************************
// << Functions about fixed length array >>
// **********************************************

// Shift the digits to right direction
void shiftDigitsToRight(const char* longNumber, int shiftLength);

// Shift the digits to left direction
void shiftDigitsToLeft(const char* longNumber, int shiftLength);

// Display the number in a fixed width
void displayFixedWidthNumber(const char* number, const int width);

int main(void)
{

    printf("\n");
    printf(" Calculator-06 : sum two long real numbers with points\n");
    printf(" Data structure: a struct (Real): char array (digits[]), integer (length), integer (pointPos)\n");
    printf(" Assumption    : two real numbers are with different width (less than %d digits) and points\n", MAX_REAL_WIDTH);
    printf("               : support for addition promotion\n");
    printf(" Operation Req.: operate the struct variables by pointers\n");
    printf("               : operate the char array by pointers\n");
    printf("\n");

    srand( time(NULL) );

    Real r1, r2, sum;
    Real* rPtr1 = &r1, * rPtr2 = &r2, * rPtrSum = &sum;

    generateLongReal(rPtr1);
    generateLongReal(rPtr2);

    int isOverflow = addTwoLongReals(rPtr1, rPtr2, rPtrSum);
    int pointPos;
    if (isOverflow == 0)
    {
        pointPos = getPointPos(rPtrSum);
        printf("\n  ");
        displayAssignedLongReal(pointPos, rPtr1);
        printf("+ ");
        displayAssignedLongReal(pointPos, rPtr2);
        printf("= ");
        displayAssignedLongReal(pointPos, rPtrSum);
    }
    else
    {
        printf("\nError! addition overflow!\n");
    }

    printf("\n");
}

// **********************************************
// << Functions about struct of Real >>
// **********************************************

void generateLongReal(Real* rPtr)
{
#ifndef DEBUG_PROMOTION
    rPtr->length = 2 + rand() % (MAX_REAL_WIDTH - 1);
    rPtr->pointPos = 1 + rand() % (rPtr->length);
#else
    // test for addition promotion
    rPtr->length = 20;
    rPtr->pointPos = 11;
#endif

    char* cPtr = rPtr->digits;
    *cPtr = '1' + rand() % 9;
    for (cPtr++; cPtr < rPtr->digits + rPtr->length - 1; cPtr++)
    {
        *cPtr = '0' + rand() % 10;
    }
    for (; cPtr < rPtr->digits + MAX_REAL_WIDTH; cPtr++)
    {
        *cPtr = '\0';
    }

    rPtr->digits[rPtr->length - 1] = '1' + rand() % 9;
    rPtr->digits[rPtr->pointPos - 1] = '.';

    printf("Generated (%2d.%2d): ", rPtr->length, rPtr->length - rPtr->pointPos);
    displayFixedWidthNumber(rPtr->digits, MAX_REAL_WIDTH);

    return;
}


// **********************************************
// << Your source code starts here >>
//
int addTwoLongReals(const Real* rPtr1, const Real* rPtr2, Real* rPtrSum)
{
    int rightLength = ( rPtr1->length - rPtr1->pointPos > rPtr2->length - rPtr2->pointPos ) ? rPtr1->length - rPtr1->pointPos : rPtr2->length - rPtr2->pointPos ;
    shiftDigitsToRight( rPtr1->digits , MAX_REAL_WIDTH - rightLength - rPtr1->pointPos );
    shiftDigitsToRight( rPtr2->digits , MAX_REAL_WIDTH - rightLength - rPtr2->pointPos );
    int i , n[MAX_REAL_WIDTH] = {0} ;
    if ( rPtr1->digits[0] != '\0' && rPtr2->digits[0] != '\0' )
    {
        rPtrSum->length = MAX_REAL_WIDTH ;
        rPtrSum->pointPos = rPtrSum->length - rightLength ;
    }
    for (int  i = MAX_REAL_WIDTH - 1 ; i >= 0 ; i -- )
    {
        if ( i == MAX_REAL_WIDTH - rightLength - 1 )
        {
            rPtrSum->digits[i] = '.' ;
            continue;
        }
        if ( rPtr1->digits[i] == '\0' && rPtr2->digits[i] == '\0' )
        {
            rPtrSum->length = MAX_REAL_WIDTH - i - 1 ;
            rPtrSum->pointPos = rPtrSum->length - rightLength ;
            if ( n[i] != 0 )
            {
                rPtrSum->digits[i] = n[i] + '0' ;
                rPtrSum->length ++ ;
                rPtrSum->pointPos ++ ;
            }
            break;
        }
        if ( rPtr1->digits[i] == '\0' )
        {
            n[i] += rPtr2->digits[i] - '0' ;
        }
        else if ( rPtr2->digits[i] == '\0' )
        {
            n[i] += rPtr1->digits[i] - '0' ;
        }
        else
        {
            n[i] += rPtr1->digits[i] - '0' + rPtr2->digits[i] - '0' ;
        }
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
        rPtrSum->digits[i] = n[i] + '0' ;
    }
    if ( n[0] > 9 )
    {
        return 1;
    }
    else
    {
        for ( i = 0 ; i < MAX_REAL_WIDTH - rPtrSum->length ; i ++ )
        {
            rPtrSum->digits[i] = '\0' ;
        }
        printf("Sum Result(%2d.%2d): ", rPtrSum->length , rPtrSum->length - rPtrSum->pointPos );
        displayFixedWidthNumber(rPtrSum->digits, MAX_REAL_WIDTH);
        shiftDigitsToLeft( rPtrSum->digits , MAX_REAL_WIDTH - rPtrSum->length );
        int shiftLength1 = MAX_REAL_WIDTH - rPtr1->length - ( rightLength - ( rPtr1->length - rPtr1->pointPos ) ) ;
        shiftDigitsToLeft( rPtr1->digits , shiftLength1 );
        int shiftLength2 = MAX_REAL_WIDTH - rPtr2->length - ( rightLength - ( rPtr2->length - rPtr2->pointPos ) ) ;
        shiftDigitsToLeft( rPtr2->digits , shiftLength2 );
        return 0;
    }
}
//
// << Your source code stops here >>
// **********************************************


int getPointPos(Real* rPtr)
{
    return  rPtr->pointPos;
}

void displayAssignedLongReal(int pointPos, Real* rPtr)
{
    int i;
    for (i = 0; i < pointPos - rPtr->pointPos; i++)
    {
        printf(" ");
    }
    for (i = 0; i < rPtr->length; i++)
    {
        printf("%c", rPtr->digits[i]);
    }
    printf("\n");

    return;
}


// **********************************************
// << Functions about fixed length array >>
// **********************************************


void shiftDigitsToRight(const char* longNumber, int shiftLength)
{
    if (MAX_REAL_WIDTH - 1 < shiftLength || shiftLength < 0)
    {
        printf("Range error. Program terminated.\n");
        exit(-10);
    }
    if (shiftLength == 0)
    {
        return;
    }

    int i;
    char* cPtr = (char*)longNumber;
    for (i = MAX_REAL_WIDTH - 1; i - shiftLength >= 0; i--)
    {
        *(cPtr + i) = *(cPtr + i - shiftLength);
    }
    for (; i >= 0; i--)
    {
        *(cPtr + i) = '\0';
    }

    printf("shiftRight (%2d)  : ", shiftLength);
    displayFixedWidthNumber(longNumber, MAX_REAL_WIDTH);

    return;
}


void shiftDigitsToLeft(const char* longNumber, int shiftLength)
{
    if (MAX_REAL_WIDTH - 1 < shiftLength || shiftLength < 0)
    {
        printf("Range error. Program terminated.\n");
        exit(-10);
    }
    if (shiftLength == 0)
    {
        return;
    }

    int i;
    char* cPtr = (char*)longNumber;
    for (i = 0; i + shiftLength < MAX_REAL_WIDTH; i++)
    {
        *(cPtr + i) = *(cPtr + i + shiftLength);
    }
    for (; i < MAX_REAL_WIDTH; i++)
    {
        *(cPtr + i) = '\0';
    }

    printf("shiftLeft  (%2d)  : ", shiftLength);
    displayFixedWidthNumber(longNumber, MAX_REAL_WIDTH);

    return;
}


void displayFixedWidthNumber(const char* number, const int width)
{
    char* cPtr = NULL;
    for (cPtr = (char*)number; cPtr < number + width; cPtr++)
    {
        if (*cPtr == '\0')
        {
            printf("_");
        }
        else
        {
            printf("%c", *cPtr);
        }
    }
    printf("\n");

    return;
}