
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH   20
#define STU_ARRAY_LENGTH  5

typedef struct{
    int year;
    int month;
    int day;
} Day;

typedef struct{
    int ID;
    int age;
    char gender;
    char name[MAX_NAME_LENGTH];
    Day birthday;
} Student;

int main()
{
    Student sArray[STU_ARRAY_LENGTH];

    int i,j;
    char name[] = "I-love-C-language";
    int length = strlen(name);
    for ( i = 0; i < STU_ARRAY_LENGTH; i ++ )
    {
        sArray[i].ID = 101 + i;
        sArray[i].age = 18 + i % 2;
        sArray[i].gender = ( i % 2 ) ? 'M' : 'F';

        for ( j = 0; j < length; j ++ )
        {
            sArray[i].name[ (i + j)%length ] = name[j];
        }
        sArray[i].name[j] = '\0';
        for ( j ++ ; j < MAX_NAME_LENGTH; j ++ )
        {
            sArray[i].name[j] = '*';
        }

        sArray[i].birthday.year = 2003;
        sArray[i].birthday.month = 1 + i;
        sArray[i].birthday.day = 1;
    }

    printf("\nStudent info:\n");
    printf("  ID          Name       Gender Age    Birthday\n");
    for ( i = 0; i < STU_ARRAY_LENGTH; i ++ )
    {
        printf("%05d %20s   %c   %2d  [%4d-%2d-%2d]\n", sArray[i].ID,
           sArray[i].name, sArray[i].gender, sArray[i].age,
           sArray[i].birthday.year, sArray[i].birthday.month,
           sArray[i].birthday.day);
    }

    printf("\nStruct storage:\n");
    for ( i = 0; i < STU_ARRAY_LENGTH; i ++ )
    {
        printf("Int : <%p>  %4d  <%p> %4d \n",
               &sArray[i].ID, sArray[i].ID,
               &sArray[i].age, sArray[i].age);
        printf("Char: <%p>  %4c \n",
               &sArray[i].gender, sArray[i].gender);
        for ( j = 0; j + 1 < MAX_NAME_LENGTH; j += 2 )
        {
            printf("Char: <%p>  %4c  <%p> %4c \n",
                   &sArray[i].name[j], sArray[i].name[j],
                   &sArray[i].name[j+1], sArray[i].name[j+1]);

        }
        printf("Int : <%p>  %4d  <%p> %4d \n",
               &sArray[i].birthday.year, sArray[i].birthday.year,
               &sArray[i].birthday.month, sArray[i].birthday.month);
        printf("Int : <%p>  %4d \n",
               &sArray[i].birthday.day, sArray[i].birthday.day);
        printf("\n");
    }
    return 0;
}
