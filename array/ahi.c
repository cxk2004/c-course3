#include <stdio.h>
#include <string.h>

#define HEX_LEN 17

void alignHexString(char str[]);
void padZero(char str[], int length);

int main()
{
    char hex1[HEX_LEN + 1] = {"\0"};
    char hex2[HEX_LEN + 1] = {"\0"};

    printf("Please input the first Hex Number: ");
    scanf("%16s", hex1);

    printf("Please input the second Hex Number: ");
    scanf("%16s", hex2);

    alignHexString(hex1);
    alignHexString(hex2);

    printf("Hex1 is %s\nHex2 is %s\n", hex1, hex2);

    int cmp = strcmp(hex1, hex2);

    if (cmp > 0)
    {
        printf("Hex1 is bigger!\n");
    }
    else if (cmp < 0)
    {
        printf("Hex2 is bigger!\n");
    }
    else
    {
        printf("The same.\n");
    }

    return 0;
}

void alignHexString(char str[])
{
    int length = strlen(str);

    if (length < HEX_LEN)
    {
        padZero(str, HEX_LEN - length);
    }
}

void padZero(char str[], int length)
{
    char temp[HEX_LEN + 1] = {"\0"};
    int i;

    for (i = 0; i < length; i++)
    {
        temp[i] = '0';
    }

    strcat(temp, str);
    strcpy(str, temp);
}
