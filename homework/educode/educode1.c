
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define INT_WIDTH   20

// Generate a random long integer
void generateLongInt(char longInt[]);

// Sum two long integers, return whether it is overflow
int addTwoLongInts(char longInt1[], char longInt2[], char longIntSum[]);

// Display a long integer in a single line
void displayLongInt(char longInt[]);

int main(void)
{
    printf("\n");
    printf(" Calculator-01 : sum two long integer numbers\n");
    printf(" Data structure: char array\n");
    printf(" Assumption    : two intergers are in the same width (%d digit)\n", INT_WIDTH);
    printf("\n");

    
    int SEED;
    scanf("%d", &SEED);
    srand(SEED);


    char longInt1[INT_WIDTH] = { 0 };
    generateLongInt(longInt1);
    char longInt2[INT_WIDTH] = { 0 };
    generateLongInt(longInt2);

    char longIntSum[INT_WIDTH] = { 0 };
   
    int isOverflow = addTwoLongInts(longInt1, longInt2, longIntSum);
   
    if (isOverflow == 0)
    {
        printf("\n  ");;
        displayLongInt(longInt1);
        printf("+ ");
        displayLongInt(longInt2);
        printf("= ");
        displayLongInt(longIntSum);
    }
    else if (isOverflow == 1)
    {
        printf("\nError! addition overflow!\n");
    }

    printf("\n");
    return 0;
}

void generateLongInt(char longInt[])
{
    int i;
    longInt[0] = '1' + rand() % 9;
    for (i = 1; i < INT_WIDTH; i++)
    {
        longInt[i] += '0' + rand() % 10;
    }

    printf("Generated (%d digit): ", INT_WIDTH);
    displayLongInt(longInt);

    return;
}

void displayLongInt(char longInt[])
{
    int i;
    for (i = 0; i < INT_WIDTH; i++)
    {
        printf("%c", longInt[i]);
    }
    printf("\n");

    return;
}


// **********************************************
// << Your source code starts here >>
//
int addTwoLongInts(char longInt1[], char longInt2[], char longIntSum[])
{
    int i;
    int carry = 0;
    for (i = INT_WIDTH - 1; i >= 0; i--)
    {
        int sum = longInt1[i] - '0' + longInt2[i] - '0' + carry;
        if (sum >= 10)
        {
            carry = 1;
            sum -= 10;
        }
        else
        {
            carry = 0;
        }
        longIntSum[i] = sum + '0';
    }   
    printf("Sum Result(20 digit): ");
    displayLongInt(longIntSum);
    return carry;
}
//
// << Your source code stops here >>
// **********************************************


