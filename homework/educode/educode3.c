
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_REAL_WIDTH   25
#define POINT_POSITION   12

typedef struct {
    char digits[MAX_REAL_WIDTH];
    int  length;
} Real;

// Generate a random long real number
Real generateLongReal(void);

// Sum two long real numbers
Real addTwoLongReals(Real r1, Real r2);

// Judge whether the long real number is valid, 1 for true, and 0 for false
int isLongRealValid(Real r);

// Display the real number in a single line
void displayLongReal(Real r);

// Display the number in a fixed width
void displayFixedWidthNumber(char number[], const int width);

int main(void)
{

    printf("\n");
    printf(" Calculator-03 : sum two long real numbers with points\n");
    printf(" Data structure: a struct (Real) with members: char array (digits[]), integer length (length)\n");
    printf(" Assumption    : two real struct variables are with different width (less than %d digits)\n", MAX_REAL_WIDTH);
    printf("               : but their points position are same (No.%d bit)\n", POINT_POSITION);
    printf("               : not support for addition promotion\n");
    printf("\n");

    int SEED;
    scanf("%d", &SEED);
    srand(SEED);

    Real real1 = generateLongReal();
    Real real2 = generateLongReal();
    Real realSum = addTwoLongReals(real1, real2);
     printf("Sum Result(%2d.%2d): ", realSum.length, realSum.length - POINT_POSITION);
    displayFixedWidthNumber(realSum.digits, MAX_REAL_WIDTH);
    if (isLongRealValid(realSum) == 1)
    {
        printf("\n  ");
        displayLongReal(real1);
        printf("+ ");
        displayLongReal(real2);
        printf("= ");
        displayLongReal(realSum);
    }
    else
    {
        printf("\nError! addition overflow!\n");
    }

    printf("\n");
    return 0;
}


Real generateLongReal(void)
{
    Real r;

    int fractionLength = rand() % (MAX_REAL_WIDTH - POINT_POSITION + 1);
    r.length = POINT_POSITION + fractionLength;

    int i;
    r.digits[0] = '1' + rand() % 9;
    for (i = 1; i < r.length - 1; i++)
    {
        r.digits[i] = '0' + rand() % 10;
    }
    r.digits[r.length - 1] = '1' + rand() % 9;

    r.digits[POINT_POSITION - 1] = '.';

    // clear the rest of the memory
    for (i = r.length; i < MAX_REAL_WIDTH; i++)
    {
        r.digits[i] = '\0';
    }
    printf("Generated (%2d.%2d): ", r.length, r.length - POINT_POSITION);
    displayFixedWidthNumber(r.digits, MAX_REAL_WIDTH);
    
    return r;
}

// **********************************************
// << Your source code starts here >>
//
Real addTwoLongReals(Real real1, Real real2) {
    Real r;
    int i;
    int carry = 0;
    int sum = 0;
    int length = real1.length > real2.length ? real1.length : real2.length;

    // Initialize digits array with '0'
    for (i = 0; i < MAX_REAL_WIDTH; i++) {
        r.digits[i] = '0';
    }

    for (i = length - 1; i >= 0; i--) {
        if (real1.digits[i] == '.') {
            r.digits[i] = '.';
            continue;
        }

        int digit1 = i < real1.length ? real1.digits[i] - '0' : 0;
        int digit2 = i < real2.length ? real2.digits[i] - '0' : 0;
        sum = digit1 + digit2 + carry;

        if (sum >= 10) {
            carry = 1;
            sum -= 10;
        } else {
            carry = 0;
        }

        r.digits[i] = sum + '0';
    }

    // Set the length of the result Real variable
    r.length = length;

    // Check for overflow
    if (carry == 1) {
        printf("Error: Addition overflow!\n");
        exit(1);
    }

    // Null-terminate the digits array
    r.digits[r.length] = '\0';

    return r;
}
//
// << Your source code stops here >>
// **********************************************

void displayLongReal(Real r)
{
    int i;
    for (i = 0; i < r.length; i++)
    {
        printf("%c", r.digits[i]);
    }
    printf("\n");

    return;
}


int isLongRealValid(Real r)
{
    return (r.length > 0) ? 1 : 0;
}


void displayFixedWidthNumber(char number[], const int width)
{
   int i;
    for (i = 0; i < width && number[i] != '\0'; i++) {
        printf("%c", number[i]);
    }
    for (; i < width; i++) {
        printf("_");
    }
    printf("\n");
}


