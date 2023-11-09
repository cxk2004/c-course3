#include <stdio.h>
#define HEX_LEN 17

void alignHexString( char str[] );

// To compare the two hex number,
// if str1 > str2 return 1, == return 0 , < return -1
int cmpHexString( char str1[], char str2[] );

// Trans a~f to A~F,
// if string is not the hex number return 0, else return 1
int isHexString( char str[] );
int stringLength(const char str[]);

int main( )
{
    char hex1[HEX_LEN] = {"\0"};
    char hex2[HEX_LEN] = {"\0"};

    printf("Please input the first Hex Number:");
    scanf("%16s", hex1);
    fflush(stdin);

    printf("Please input the second Hex Number:");
    scanf("%16s", hex2);
    fflush(stdin);

    if( isHexString( hex1 ) == 0 || isHexString( hex2 ) == 0)
    {
        printf("Not the hexadecimal number! Program terminated.\n");
        return -1;
    }

    alignHexString( hex1 );
    alignHexString( hex2 );

    //test output
    printf("Hex1 is %s\nHex2 is %s\n", hex1, hex2);

    switch ( cmpHexString(hex1,hex2) )
    {
        case 1:
            printf("Hex1 is bigger!\n");
            break;
        case 0:
            printf("The same.\n");
            break;
        case -1:
            printf("Hex2 is bigger!\n");
            break;
    }
    return 0;

}
int stringLength(const char str[])
{
    int length = 0;
    while (str[length]!='\0')

    {
        length++;
    }
    return length;
}
void alignHexString( char str[] )
{
      int length = 0;
    while (str[length] != '\0')
    {
        if (str[length] >= 'a' && str[length] <= 'z')
        {
            str[length] = str[length] - 'a' + 'A'; // Convert lowercase letters to uppercase
        }
        else if (!((str[length] >= '0' && str[length] <= '9') || (str[length] >= 'A' && str[length] <= 'F')))
        {
            printf("Invalid character '%c' detected!\n", str[length]);
            
            return;
        }
        length++;
    }

    if (length < HEX_LEN-1)
    {
        int numZeros = HEX_LEN -1  - length;
        int i, j;

        for (i = length; i >= 0; i--)
        {
            str[i + numZeros] = str[i];
        }

        for (i = 0; i < numZeros; i++)
        {
            str[i] = '0';
        }
    }

}
    // **********************************************
    // << Your source code starts here >>
    //

  

    
    //
    // << Your source code stops here >>
    // **********************************************



int cmpHexString( char str1[], char str2[])
{
    // **********************************************
    // << Your source code starts here >>
    int i = 0;
    while (str1[i]!='\0'&&str2[i]!='\0')
    {
        if(str1[i]>str2[i])
        {

        
        return 1;
        }
        else if(str1[i]<str2[i])
        {
            return -1;
        }
        i++;
    }
    if(str1[i]=='\0'&&str2[i]=='\0')
    {
        return 0;
    }
    else if(str1[i]=='\0')
    {
        return -1;
    }
    else
    {
        return 1;
    }
    //
    // << Your source code stops here >>
    // **********************************************

}

int isHexString( char str[] )
{
    // **********************************************
    // << Your source code starts here >>
    //
    int i=0;
    if(str[0]=='\0')
    while (str[i]!='\0')
    {
        if(!((str[i] >= '0' && str[i ] <='9')||(str[i]>='A'&&str[i] <='F' )))
        {
            return 0;

        }
        i++;
    }
    return 1;
    // << Your source code stops here >>
    // **********************************************
}