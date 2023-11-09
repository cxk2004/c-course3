
#include <stdio.h>

// **************************************
// Constants used for this program
// **************************************
//
//The number of hexadecimal numbers
#define HEX_NUM 5
//The max length of hexadecimal numbers
#define HEX_LEN 17

// **************************************
// Functions used for this program
// **************************************
//
// Align the hexadecimal numbers to the right
void alignHexString( char str[] );

// To compare the two hex number,
// if str1 > str2 return 1, == return 0 , < return -1
int cmpHexString( char str1[], char str2[] );

// Trans a~f to A~F,
// if string not the hex number return 0, else return 1
int isHexString( char str[] );

// Copy str2 to str1
int strCopy( char str1[], char str2[] );

// Sort Hex strings
void sortHexString( char str[][HEX_LEN] );

// Print Hex strings
void printHexString( char str[][HEX_LEN] );

int main( )
{
    char hex[HEX_NUM][HEX_LEN];
    int i;

    for(i = 0; i < HEX_NUM; i++ )
    {
        printf("Please input the %d Hex Number:", i + 1);
        scanf("%16s", hex[i]);
        fflush(stdin);

        if( !isHexString( hex[i] ) )
        {
            printf("Not the hexadecimal number! Program terminated.\n");
            return -1;
        }

        alignHexString( hex[i] );
    }

    printf("Before sorting:\n");
    printHexString( hex );

    sortHexString( hex );

    printf("After sorting:\n");
    printHexString( hex );

    return 0;

}

void alignHexString( char str[] )
{
    // **********************************************
    // << Your source code starts here >>
    //
    
    //
    // << Your source code stops here >>
    // **********************************************
}


void sortHexString( char str[][HEX_LEN] )
{
    // **********************************************
    // << Your source code starts here >>
    //

    //
    // << Your source code stops here >>
    // **********************************************
}

int cmpHexString( char str1[], char str2[])
{
    // **********************************************
    // << Your source code starts here >>
    //

    //
    // << Your source code stops here >>
    // **********************************************
}

int isHexString( char str[] )
{
    // **********************************************
    // << Your source code starts here >>
    //

    //
    // << Your source code stops here >>
    // **********************************************
}

int strCopy( char str1[], char str2[] )
{
    int i = 0, j = 0;
    while ( i < HEX_LEN && str2[j]!= '\0' )
	{
		str1[i++] = str2[j++];
	}
    if( i == HEX_LEN )
    {
        return -1;
    }

    str1[i] = '\0';

    return 1;

}

void printHexString( char str[][HEX_LEN] )
{
    int i;
    for ( i = 0; i < HEX_NUM; i ++ )
    {
        printf("%s\n", str[i]);
    }
}