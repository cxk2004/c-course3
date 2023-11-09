
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH   20
#define STU_ARRAY_SIZE    3
#define THIS_YEAR         2021

typedef struct{
    int year, month, day;
} Date;

typedef struct{
    int ID, age;
    char gender, name[MAX_NAME_LENGTH];
    Date birthday;
} Student;

// Display the information of student, or student array
void displayStudentList( Student sArray[]);
void displayStudent( Student s);
// Obtain the value of one student from keybroad
Student inputOneStudent( void );
// Find and return the oldest student in the array
Student getYoungestStudent( Student sArray[]);
// Attach one string in the end of student's name
Student catStudentName( Student s, const char catStr[] );
// Calculate the total days from 0-1-1 to the input date
int getTotalDays( Date d );

int main()
{
    Student sArray[STU_ARRAY_SIZE];
    printf("Please input %d students information:\n",
           STU_ARRAY_SIZE );
    int i;
    for ( i = 0; i < STU_ARRAY_SIZE; i ++ )
    {
        sArray[i] = inputOneStudent();
    }

    printf("\nStudent info:\n");
    displayStudentList( sArray );

    printf("\nThe youngest student:\n");
    Student s;
    s = getYoungestStudent( sArray );
    s = catStudentName( s, "*" );
    displayStudent( s );
    printf("\n");
    return 0;
}

void displayStudentList( Student sArray[])
{
    int i;
    for ( i = 0; i < STU_ARRAY_SIZE; i ++ )
    {
        displayStudent(sArray[i]);
    }
    return;
}

void displayStudent( Student s)
{
    printf(" %10s: %05d   %c  %2d  [%4d-%2d-%2d]\n",
       s.name, s.ID, s.gender, s.age, s.birthday.year,
       s.birthday.month, s.birthday.day);
    return;
}


Student getYoungestStudent( Student sArray[])
{
    int i;
    Student youngest = sArray[0];
    for(i=0;i<STU_ARRAY_SIZE;i++)
    {
        if(sArray[i].birthday.year>youngest.birthday.year)
        {
            youngest = sArray[i];

        }
        else if(sArray[i].birthday.year==youngest.birthday.year)
        {
            if (sArray[i].birthday.month>youngest.birthday.month)
            {
                youngest = sArray[i];
            }
            else if(sArray[i].birthday.month==youngest.birthday.month)
            {
                if(sArray[i].birthday.day>youngest
                .birthday.day)
                {
                    youngest = sArray[i];
                }
            }
        }
    }
    return youngest;
}

Student catStudentName( Student s, const char catStr[] )
{
    strcat(s.name,catStr);
    return s;
}

Student inputOneStudent( void )
{
    char errorMsg[] = "Invalid input. Program terminated. \n";

    Student s;
    printf("Please input the student ID: ");
    scanf("%d", &s.ID );
    if ( s.ID < 0 || s.ID > 1000000 )
    {
        printf("%s", errorMsg );
        exit (-10);
    }

    fflush(stdin);
    printf("Please input the student name: ");
    scanf("%[^\n]", s.name );
    getchar();

    printf("Please input the student gender (M=male, F=Female) : ");
    scanf("%c", &s.gender );
    if ( s.gender != 'M' && s.gender != 'F' )
    {
        printf("%s", errorMsg );
        exit (-20);
    }

    printf("Please input the student birthday (year month day): ");
    scanf("%d%d%d", &s.birthday.year, &s.birthday.month, &s.birthday.day );
    if ( s.birthday.year < 0 || s.birthday.month < 1
        || s.birthday.month > 12 || s.birthday.day < 1
        || s.birthday.day > 31 )
    {
        printf("%s", errorMsg );
        exit (-30);
    }

    s.age = THIS_YEAR - s.birthday.year;


    return s;
}


int getTotalDays( Date b )
{
    // do not support leap year in current version
    const int monthLength[] = {31, 28, 31, 30, 31, 30,
                               31, 31, 30, 31, 30, 31};
    int result = 0;
    result += 365 * b.year;
    result += monthLength[ b.month - 1 ];
    result += b.day;
    return result;
}