#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_WORD_NUM 200
#define MAX_WORD_LEN 30

// function to parse the message
// return the found number of words
int parseMessage(char message[]);


int main()
{

    char message[1000] ;
    gets(message);

    printf("Orignal msg is: %s \n\n", message);

    int wCounter = parseMessage(message);
    printf("\nFind total %d words.\n\n", wCounter);

    return 0;
}


// **********************************************
// << Your source code starts here >>
//
int parseMessage(char message[])
{
    int counter = 0;
    char *p = message;
    char *end;
    char token[MAX_WORD_LEN];

    while (*p != '\0')
    {
        while(*p == ' ' || *p == ',' || *p == '.') p++; 
        end = p; 
        while(*end != ' ' && *end != ',' && *end != '.' && *end != '\0') end++; 
        if (end > p)
        {
            strncpy(token, p, end - p);
            token[end - p] = '\0'; 
            printf("[%02d] %-21s", counter + 1, token);
            counter++;
            if(counter % 3 == 0)
            {
                printf("\n");
            }
        }
        p = end; 
    }

    
    if (counter % 3 != 0)
    {
        printf("\n");
    }
    printf("\b\b\n");
    return counter;
}
//
// << Your source code stops here >>
// **********************************************