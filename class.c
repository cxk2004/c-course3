#define MAX_NAME_LENGTH 20
#define STU_ARRAY_LENGTH 5
#include <stdio.h>
#include <stdlib.h>
//define a struct Day
typedef struct{
    int year;
    int month;
    int  day;
} Day;

typedef struct{
    int ID;//not applicable for string type
    int  age;
    char name[MAX_NAME_LENGTH];//string type
    char gender;//'f' or'm'
    Day birthday;//struct Day
} Student;

int main()
{
   Student sArray[STU_ARRAY_LENGTH];
   
   int i, j;
   char name[] = "I-love-C-language";
   int length = strlen(name);
   for( i =0;i<STU_ARRAY_LENGTH;i++)
   {
     sArray[i].ID = i+101;
     sArray[i].age = (i % 2 ==0)?18:19;
     sArray[i].gender = (i % 2 ==0)?'F':'M';
     sArray[i].birthday.year = 2003;
     sArray[i].birthday.month = 1+i;
     sArray[i].birthday.day = 1;
     for(j = 0;j<length;j++)
     {
       sArray[i].name[j] = name[(j+i)%length];
     }
   }
   printf("\nstudent info :\n");
   printf("  ID          Name           Gender   Age    Birthday\n");
   for(i=0;i<STU_ARRAY_LENGTH;i++)
   {

   
    printf("%5d    %20s    %c   %2d  [%4d-%2d-%2d]\n",sArray[i].ID,sArray[i].name,sArray[i].gender,sArray[i].age,sArray[i].birthday.year,sArray[i].birthday.month,sArray[i].birthday.day);
   
   }
   printf("\nstruct storage :\n");
   for(i=0;i<STU_ARRAY_LENGTH;i++)
   {
    printf("sArray[%d].ID address: %p\n", i, &sArray[i].ID);
        printf("sArray[%d].name address: %p\n", i, &sArray[i].name);
        printf("sArray[%d].gender address: %p\n", i, &sArray[i].gender);
        printf("sArray[%d].age address: %p\n", i, &sArray[i].age);
        printf("sArray[%d].year address: %p\n", i, &sArray[i].birthday.year);
        printf("sArray[%d].month address: %p\n", i, &sArray[i].birthday.month);
        printf("sArray[%d].day address: %p\n", i, &sArray[i].birthday.day);
   }
}
