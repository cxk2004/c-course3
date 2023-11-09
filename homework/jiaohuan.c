
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 30

typedef struct {
    char content[N];  
    int length;            
} Str;
Str getRandString();
int isInStr(Str s, char a);
Str getStringIntersection(Str str1, Str str2);
Str getStringUnion(Str str1, Str str2);
int compareTwoStrByDistinctLetters(Str str1, Str str2);
int main()
{
    srand(time(NULL));
    Str str1 = getRandString();
    Str str2 = getRandString();
    Str intersection = getStringIntersection(str1, str2);
    Str unionStr = getStringUnion(str1, str2);
    int comparison = compareTwoStrByDistinctLetters(str1, str2);

    printf("Generate string1 as:   %-30s (length=%2d)\n", str1.content, str1.length);
    printf("Generate string2 as:   %-30s (length=%2d)\n", str2.content, str2.length);
    printf("Their intersection is: %-30s (length=%2d)\n", intersection.content, intersection.length);
    printf("Their union is:        %-30s (length=%2d)\n", unionStr.content, unionStr.length);
    printf("String1 has %2d distinct letters.\n", getStringUnion(str1, str1).length);
    printf("String2 has %2d distinct letters.\n", getStringUnion(str2, str2).length);
    if (comparison == 0)
    {
        printf("String1 and String2 has the same number of distinct letters.\n");
    } 
    else if (comparison < 0) 
    {
        printf("String1 has fewer distinct letters than String2.\n");
    } 
    else 
    {
        printf("String1 has more distinct letters than String2.\n");
    }

    return 0;
}
Str getRandString() 
{
    Str s;
    s.length = rand() % (N / 2) + 1;
    for (int i = 0; i < s.length; i++) 
    {
        s.content[i] = rand() % 26 + (rand() % 2 ? 'a' : 'A');
    }
    for (int i = s.length; i < N; i++) 
    {
        s.content[i] = '_';
    }
    return s;
}

int isInStr(Str s, char a)
{
    for (int i = 0; i < s.length; i++) 
    {
        if (s.content[i] == a) 
        {
            return 1;
        }
    }
    return 0;
}

Str getStringIntersection(Str str1, Str str2)
{
    Str s;
    s.length = 0;
    for (int i = 0; i < N; i++) 
    {
        s.content[i] = '_';
    }
    for (int i = 0; i < str1.length; i++) 
    {
        if (isInStr(str2, str1.content[i]) && !isInStr(s, str1.content[i])) 
        {
            s.content[s.length++] = str1.content[i];
        }
    }
    return s;
}

Str getStringUnion(Str str1, Str str2) 
{
    Str s;
    s.length = 0;
    for (int i = 0; i < N; i++) 
    {
        s.content[i] = '_';
    }
    for (int i = 0; i < str1.length; i++) 
    {
        if (!isInStr(s, str1.content[i])) 
        {
            s.content[s.length++] = str1.content[i];
        }
    }
    for (int i = 0; i < str2.length; i++) 
    {
        if (!isInStr(s, str2.content[i])) 
        {
            s.content[s.length++] = str2.content[i];
        }
    }
    return s;
}

int compareTwoStrByDistinctLetters(Str str1, Str str2) 
{
    Str union1 = getStringUnion(str1, str1);
    Str union2 = getStringUnion(str2, str2);
    if (union1.length < union2.length) 
    {
        return -1;
    } 
    else if (union1.length > union2.length) 
    {
        return 1;
    } 
    else 
    {
        return 0;
    }
}
