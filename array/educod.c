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
    int i;
    int length = 0;
    while ((*str) != '\0')
    {
        length++;
        str++;
    }
    return length;
    for(i=0;i<HEX_LEN-length;i++)
    {
        printf("0");
    }
    printf("%s\n",str);
       


}


void sortHexString( char str[][HEX_LEN] )
{
    // **********************************************
    // << Your source code starts here >>
    //
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
    //
    // << Your source code stops here >>
    // **********************************************
}

int cmpHexString( char str1[], char str2[])
{
    // **********************************************
    // << Your source code starts here >>
    //
     int i;
    for (i = 0; i < HEX_LEN - 1; i++)
    {
        if (str1[i] > str2[i])
        {
            return 1;
        }
        else if (str1[i] < str2[i])
        {
            return -1;
        }
    }
    return 0;

    //
    // << Your source code stops here >>
    // **********************************************
}

int isHexString( char str[] )
{
    // *********************************************
 int length = 0;
    while ((*str) != '\0')
    {
        length++;
        str++;
    }
    return length;
    int i;
    for (i = 0; i < length; i++) {
        if (!((str[i] >= '0' && str[i] <= '9') || (str[i] >= 'A' && str[i] <= 'F'))) {
            return 0;
        }
    }
    return 1;
    for(int k=0;k<length;k++)
    {
        if(str[k]>='a'&&str[k]<='f')
        {
            str[k]=str[k]-32;
        }
    }
    return 1;
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