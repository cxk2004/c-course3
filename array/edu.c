
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
    int i = 0, j = 0;
    while ( str[i] != '\0' )
    {
        i++;
    }
    while ( i >= 0 )
    {
        str[HEX_LEN - 1 - j] = str[i];
        i--;
        j++;
    }
    while ( j < HEX_LEN )
    {
        str[HEX_LEN - 1 - j] = '0';
        j++;
    }
}


void sortHexString( char str[][HEX_LEN] )
{
    int i, j;
    char temp[HEX_LEN];
    for ( i = 0; i < HEX_NUM - 1; i++ )
    {
        for ( j = 0; j < HEX_NUM - 1 - i; j++ )
        {
            if ( cmpHexString( str[j], str[j + 1] ) == 1 )
            {
                strCopy( temp, str[j] );
                strCopy( str[j], str[j + 1] );
                strCopy( str[j + 1], temp );
            }
        }
    }   
}

int cmpHexString( char str1[], char str2[])
{
    int i = 0;
    while ( str1[i] == str2[i] )
    {
        i++;
    }
    if ( str1[i] > str2[i] )
    {
        return -1;
    }
    else if ( str1[i] < str2[i] )
    {
        return 1;
    }
    else
    {
        return 0;
    }   
}

int isHexString( char str[] )
{
    int i = 0;
    while ( str[i] != '\0' )
    {
        if ( str[i] >= '0' && str[i] <= '9' )
        {
            i++;
        }
        else if ( str[i] >= 'a' && str[i] <= 'f' )
        {
            str[i] = str[i]  + 'A' - 'a';
            i++;
        }
        else if ( str[i] >= 'A' && str[i] <= 'F' )
        {
            i++;
        }
        else
        {
            return 0;
        }
    }
    return 1;
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