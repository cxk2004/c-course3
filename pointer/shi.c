// 文字处理

// 【问题描述】
// 对于给定的一段文字，将其解析到一个字符串数组(二维字符数组)中，
// 输出长度最长的单词，出现频次最多的单词

// 【编写要求】
// 1. 完成下列3个函数
// 2. 尽可能使用指针表达字符或者字符串，体会指针的用法

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_NUM   200
#define MAX_WORD_LEN   1000

int parseMessage( char * message, char (*words)[MAX_WORD_LEN] );
int findLongestWord( char (*words)[MAX_WORD_LEN], int wordCounter );
void findHighFreqWord( char (*words)[MAX_WORD_LEN], int wordCounter,
         int *mostIndex, int *mostValue );
        
int main()
{
    char* message[] = {"C is a general-purpose, high-level language that was originally developed by Dennis M. Ritchie to develop the UNIX operating system at Bell Labs. ","C was originally first implemented on the DEC PDP-11 computer in 1972.","In 1978, Brian Kernighan and Dennis Ritchie produced the first publicly available description of C, now known as the K&R standard.","The UNIX operating system, the C compiler, and essentially all UNIX application programs have been written in C. ","C programming is a general-purpose, procedural, imperative computer programming language developed in 1972 by Dennis M. Ritchie at the Bell Telephone Laboratories to develop the UNIX operating system. C is the most widely used computer language. It keeps fluctuating at number one scale of popularity along with the Java programming language, which is also equally popular and most widely used among modern software programmers."};
    
    char words[MAX_WORD_NUM][MAX_WORD_LEN] = {0};

    int seed;
    scanf("%d",&seed);


    int wordCounter = parseMessage( message[seed], words );
    printf("Total %d words are found.\n", wordCounter );

    int indexLong = findLongestWord( words, wordCounter );
    printf("The longest word is %s\n",  words[ indexLong ] );

    int indexMost, valueMost;
    findHighFreqWord( words, wordCounter, &indexMost, &valueMost );
    printf("The most frequently word is %s, it appears %d times\n", 
            words[ indexMost ], valueMost );

    return 0;
}
int parseMessage( char * message, char (*words)[MAX_WORD_LEN] )
{
    // -----------------------------
    int i = 0, j, n = 0, counter = 0;

    for(i = 0; i < MAX_WORD_NUM && *(message + n) != '\0'; i++)
    {
        for(j = 0; j < MAX_WORD_LEN && *(message + n) != '\0'; j++)
        {
            if(*(message + n) != ' ' && *(message + n) != ',' && *(message + n) != '.')
            {
                *(*(words + i) + j) = *(message + n);
                n++;
                counter++;
            }

            else
            {
                if(counter != 0)
                {
                    *(*(words + i) + j + 1) = '\0';
                    n++;
                    counter = 0;
                    break;
                }

                else
                {
                    j--;
                    n++;
                }
            }
        }
    }
    return i - 1;
    // end of your source code
    // -----------------------------
}

int findLongestWord( char (*words)[MAX_WORD_LEN] , int wordCounter )
{
    // -----------------------------
    // start of your source code
    int i, j, counter, indexLong = 0, maxlength = 0;
    for(i = 0; i < wordCounter; i++)
    {
        counter = 0;
        for(j = 0; j < MAX_WORD_LEN && *(*(words + i) + j) != '\0'; j++)
        {
            counter++;
        }
        indexLong = (counter > maxlength) ? i : indexLong;
        maxlength = (counter > maxlength) ? counter : maxlength;
    }

    return indexLong;
    //
    // end of your source code
    // -----------------------------
}

void findHighFreqWord( char (*words)[MAX_WORD_LEN] , int wordCounter, int *mostIndex, int *mostValue )
{
    // -----------------------------
    // start of your source code
    *mostIndex = 0;
    *mostValue = 1;
    int i, j, n, counter;
    for(i = 0; i < wordCounter - 1; i++)
    {
        counter = 1;
        for(j = i + 1; j < wordCounter; j++)
        {
            for(n = 0; n < MAX_WORD_LEN; n++)
            {
                if( *(*(words + i) + n) != *(*(words + j) + n) )
                {
                    break;
                }

                if( *(*(words + i) + n) == '\0' && *(*(words + j) + n) == '\0')
                {
                    counter++;
                    break;
                }
            }
        }
        *mostIndex = (counter > *mostValue) ? i : *mostIndex;
        *mostValue = (counter > *mostValue) ? counter : *mostValue;
    }
}