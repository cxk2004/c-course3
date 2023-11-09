/*
 * Calculator-04: long real with float point, based on string
 */

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

    printf("\n");
    printf(" Calculator-04 : sum two long real numbers with points\n");
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


