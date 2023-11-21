/*
 * Calculator-07: long real with float point, calling function by pointers
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_REAL_WIDTH   25

typedef struct {
    char digits[MAX_REAL_WIDTH];
    int  pointPos;
    int  length;
} Real;

// **********************************************
// << Functions about struct of Real >>
// **********************************************

// Create a random long real number, allocate memory for Real
Real* generateLongReal(void);

// Release the memory for Real 
void destroyLongReal(Real* rPtr);

// Sum two long real numbers
Real* addTwoLongReals(const Real* rPtr1, const Real* rPtr2);

// Display the real number in a single line
void displayAssignedLongReal(int pointPos, Real* rPtr);

// Shift the digits to right direction
void shiftDigitsToRight(const char* longNumber, int shiftLength);

// Shift the digits to left direction
void shiftDigitsToLeft(const char* longNumber, int shiftLength);

// Display the number in a fixed width
void displayFixedWidthNumber(const char* number, const int width);

int main(void)
{

    printf("\n");
    printf(" Calculator-07 : sum two long real numbers with points\n");
    printf(" Data structure: a struct (Real): char array (digits[]), integer (length), integer (pointPos)\n");
    printf(" Assumption    : two real numbers are with different width (less than %d digits) and points\n", MAX_REAL_WIDTH);
    printf(" Operation Req.: operate the struct variables by pointers\n");
    printf("               : operate the char array by pointers\n");
    printf("\n");

    int SEED;
    scanf("%d", &SEED);
    srand(SEED);

    Real* rPtr1 = generateLongReal();
    Real* rPtr2 = generateLongReal();
    Real* rPtrSum = addTwoLongReals(rPtr1, rPtr2);

    if (rPtrSum->length > 0)
    {
        printf("\n  ");
        displayAssignedLongReal(rPtrSum->pointPos, rPtr1);
        printf("+ ");
        displayAssignedLongReal(rPtrSum->pointPos, rPtr2);
        printf("= ");
        displayAssignedLongReal(rPtrSum->pointPos, rPtrSum);
    }
    else
    {
        printf("\nError! addition overflow!\n");
    }
    printf("\n");

    destroyLongReal(rPtr1);
    destroyLongReal(rPtr2);
    destroyLongReal(rPtrSum);
}

// **********************************************
// << Functions about struct of Real >>
// **********************************************

Real* generateLongReal(void)
{
    Real* rPtr = (Real*)malloc(sizeof(Real));

    rPtr->length = 2 + rand() % (MAX_REAL_WIDTH - 1);
    rPtr->pointPos = 1 + rand() % (rPtr->length);

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

    printf("Randomize(%2d.%02d): ", rPtr->length, rPtr->length - rPtr->pointPos);
    displayFixedWidthNumber(rPtr->digits, MAX_REAL_WIDTH);

    return rPtr;
}

void destroyLongReal(Real* rPtr)
{
    free(rPtr);

    return;
}

// **********************************************
// << Your source code starts here >>
//
Real* addTwoLongReals(const Real* rPtr1, const Real* rPtr2)
{
    int rightLength = (rPtr1->length - rPtr1->pointPos > rPtr2->length - rPtr2->pointPos) ? rPtr1->length - rPtr1->pointPos : rPtr2->length - rPtr2->pointPos;
    shiftDigitsToRight(rPtr1->digits, MAX_REAL_WIDTH - rightLength - rPtr1->pointPos);
    shiftDigitsToRight(rPtr2->digits, MAX_REAL_WIDTH - rightLength - rPtr2->pointPos);
    int i, n[MAX_REAL_WIDTH] = { 0 };
    Real* rPtrSum = (Real*)malloc(sizeof(Real));
    if (rPtr1->digits[0] != '\0' && rPtr2->digits[0] != '\0')
    {
        rPtrSum->length = MAX_REAL_WIDTH;
        rPtrSum->pointPos = rPtrSum->length - rightLength;
    }
    for (i = MAX_REAL_WIDTH - 1; i >= 0; i--)
    {
        if (i == MAX_REAL_WIDTH - rightLength - 1)
        {
            rPtrSum->digits[i] = '.';
            continue;
        }
        if (rPtr1->digits[i] == '\0' && rPtr2->digits[i] == '\0')
        {
            rPtrSum->length = MAX_REAL_WIDTH - i - 1;
            rPtrSum->pointPos = rPtrSum->length - rightLength;
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
        printf("Error! addition overflow!\n");
        free(rPtrSum);
        return NULL;
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
        return rPtrSum;
    }
}
//
// << Your source code stops here >>
// **********************************************

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

    printf("shiftRight (%2d) : ", shiftLength);
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

    printf("shiftLeft  (%2d) : ", shiftLength);
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

