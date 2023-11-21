/*
 * Calculator-08: long real with float point, based on dynamic array
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

#define MAX_REAL_WIDTH   25

 // the pointer of digits point to the dynamic array
typedef struct {
    char* digits;
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
Real* addTwoLongReals(Real* rPtr1, Real* rPtr2);

// **********************************************
// << Functions about fixed length array >>
// **********************************************

// Shift the digits to right direction, re-allocate memory for rPtr->digits[]
void shiftDigitsToRight(Real* rPtr, int shiftLength);

// Shift the digits to left direction, re-allocate memory for rPtr->digits[]
void shiftDigitsToLeft(Real* rPtr, int shiftLength);

// Display the real number in a single line
void displayAssignedLongReal(int assignedLength, const Real* rPtr);

int main(void)
{

    printf("\n");
    printf(" Calculator-08 : sum two long real numbers with points\n");
    printf(" Data structure: a struct (Real): char *pointer (digits), integer (length), integer (pointPos)\n");
    printf(" Assumption    : two real struct variables are with different width (less than %d bit)\n", MAX_REAL_WIDTH);
    printf("               : their points position are also different, support addition promotion \n");
    printf(" Operation Req.: operate the struct variables by pointers\n");
    printf("               : operate the dynamic memory by pointers\n");
    printf("\n");

    int SEED;
    scanf("%d", &SEED);
    srand(SEED);

    Real* rPtr1 = generateLongReal();
    Real* rPtr2 = generateLongReal();
    Real* rPtrSum = addTwoLongReals(rPtr1, rPtr2);

    printf("\n  ");
    displayAssignedLongReal(rPtrSum->pointPos - rPtr1->pointPos, rPtr1);
    printf("+ ");
    displayAssignedLongReal(rPtrSum->pointPos - rPtr2->pointPos, rPtr2);
    printf("= ");
    displayAssignedLongReal(0, rPtrSum);
    printf("\n");

    destroyLongReal(rPtr1);
    destroyLongReal(rPtr2);
    destroyLongReal(rPtrSum);

    return 0;
}


Real* generateLongReal(void)
{
    Real* rPtr = (Real*)malloc(sizeof(Real));

    rPtr->length = 2 + rand() % (MAX_REAL_WIDTH - 1);
    rPtr->pointPos = 1 + rand() % (rPtr->length);

    // allocate memory for rPtr->digits array
    rPtr->digits = (char*)calloc(rPtr->length+1, sizeof(char));
    rPtr->digits[0] = '1' + rand() % 9;

    int i;
    for (i = 1; i < rPtr->length - 1; i++)
    {
        rPtr->digits[i] = '0' + rand() % 10;
    }
    rPtr->digits[rPtr->length - 1] = '1' + rand() % 9;
    rPtr->digits[rPtr->pointPos - 1] = '.';

    printf("Randomize(%2d.%02d): ", rPtr->length, rPtr->length - rPtr->pointPos);
    displayAssignedLongReal(0, rPtr);

    return rPtr;
}


void destroyLongReal(Real* rPtr)
{
    if (rPtr->digits != NULL)
    {
        free(rPtr->digits);
        rPtr->digits = NULL;
    }
    free(rPtr);

    return;
}

// **********************************************
// << Your source code starts here >>
//
Real* addTwoLongReals(Real* rPtr1, Real* rPtr2)
{
    int length1 = strlen(rPtr1->digits);
    int length2 = strlen(rPtr2->digits);
    int rightLength = (length1 - rPtr1->pointPos > length2 - rPtr2->pointPos)
        ? length1 - rPtr1->pointPos
        : length2 - rPtr2->pointPos;

    shiftDigitsToRight(rPtr1, rightLength);
    shiftDigitsToRight(rPtr2, rightLength);

    int i, carry = 0;
    int maxLength = (length1 > length2) ? length1 : length2;
    Real* rPtrSum = (Real*)malloc(sizeof(Real));
    rPtrSum->length = maxLength + 1;
    rPtrSum->pointPos = rPtrSum->length - rightLength;

    char* newDigits = (char*)calloc(rPtrSum->length, sizeof(char));

    for (i = rPtrSum->length - 1; i >= 0; i--)
    {
        int sum = carry;
        if (length1 > 0)
        {
            sum += rPtr1->digits[length1 - 1] - '0';
            length1--;
        }
        if (length2 > 0)
        {
            sum += rPtr2->digits[length2 - 1] - '0';
            length2--;
        }
        newDigits[i] = (sum % 10) + '0';
        carry = sum / 10;
    }

    if (carry > 0)
    {
        shiftDigitsToRight(rPtrSum, 1);
        rPtrSum->digits[rPtrSum->pointPos - 1] = carry + '0';
    }

    free(rPtr1->digits);
    free(rPtr2->digits);
    rPtr1->digits = NULL;
    rPtr2->digits = NULL;

    rPtrSum->digits = newDigits;

    printf("Sum Result(%2d.%2d): ", rPtrSum->length , rPtrSum->length - rPtrSum->pointPos );
    displayAssignedLongReal(0, rPtrSum);

    return rPtrSum;
}
//
// << Your source code stops here >>
// **********************************************

void displayAssignedLongReal(int shiftLength, const Real* rPtr)
{
    int i;
    for (i = 0; i < shiftLength; i++)
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

void shiftDigitsToRight(Real* rPtr, int shiftLength)
{
    if (shiftLength > MAX_REAL_WIDTH - 1 || shiftLength < 0)
    {
        printf("Range error. Program terminated.\n");
        exit(-10);
    }
    else if (shiftLength == 0)
    {
        return;
    }

    int length = rPtr->length + shiftLength;
    char* newDigits = (char*)calloc(length, sizeof(char));

    int i = length - 1;
    int j = rPtr->length - 1;
    for (; i - shiftLength >= 0; i--)
    {
        newDigits[i] = rPtr->digits[j];
        j--;
    }

    free(rPtr->digits);
    rPtr->digits = newDigits;
    rPtr->length += shiftLength;
    rPtr->pointPos += shiftLength;

    printf("shiftRight (%2d) : ", shiftLength);
    displayAssignedLongReal(shiftLength, rPtr);

    return;
}


void shiftDigitsToLeft(Real* rPtr, int shiftLength)
{
    if (shiftLength > MAX_REAL_WIDTH - 1 || shiftLength < 0)
    {
        printf("Range error. Program terminated.\n");
        exit(-20);
    }
    else if (shiftLength == 0)
    {
        return;
    }

    int length = rPtr->length - shiftLength;
    char* newDigits = (char*)calloc(length, sizeof(char));

    int i = 0;
    int j = shiftLength;
    for (; i < length; i++)
    {
        newDigits[i] = rPtr->digits[j];
        j++;
    }

    free(rPtr->digits);
    rPtr->digits = newDigits;
    rPtr->length -= shiftLength;
    rPtr->pointPos -= shiftLength;

    printf("shiftLeft  (%2d) : ", shiftLength);
    displayAssignedLongReal(0, rPtr);

    return;
}


