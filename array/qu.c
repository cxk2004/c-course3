
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
void alignHexString( char str[] )
{
    int len = strlen(str);
    int i;
    for (i = len; i < HEX_LEN ; i++) {
     str[i] = '0';   
    }
    printf("%s", str);
}

// To compare the two hex number,
// if str1 > str2 return 1, == return 0 , < return -1
int cmpHexString( char str1[], char str2[] )
{
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    if (len1 > len2) {
        return 1;
    } else if (len1 < len2) {
        return -1;
    } else {
        return strcmp(str1, str2);
    }
}

// Trans a~f to A~F,
// if string not the hex number return 0, else return 1
int isHexString( char str[] )
{
    int len = strlen(str);
    int i;
    for (i = 0; i < len; i++) {
        if (!isxdigit(str[i])) {
            return 0;
        }
        if (islower(str[i])) {
            str[i] = toupper(str[i]);
        }
    }
    return 1;
}

// Copy str2 to str1
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

// Sort Hex strings
void sortHexString( char str[][HEX_LEN] )
{
    int i, j;
    char temp[HEX_LEN];
    for (i = 0; i < HEX_NUM - 1; i++) {
        for (j = 0; j < HEX_NUM - i - 1; j++) {
            if (cmpHexString(str[j], str[j+1]) > 0) {
                strCopy(temp, str[j]);
                strCopy(str[j], str[j+1]);
                strCopy(str[j+1], temp);
            }
        }
    }
}

// Print Hex strings
void printHexString( char str[][HEX_LEN] )
{
    int i;
    for (i = 0; i < HEX_NUM; i++) {
        alignHexString(str[i]);
        printf("\n");
    }
}

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