#include <stdio.h>
#include <stdlib.h>

#include "springdate.h"

int main(void)
{

    // Declare variables
    int referenceDay;

    // Display the program information
    printf("Spring Semester Calendar of Year %d, please input reference day in Feb(1-%d): \n",
        CURRENT_YEAR, getMonthLength(2));
    scanf_s("%d", &referenceDay);

    // Display the program information
    printf("%18s%s%d\n", " ", "Spring Semester Calendar of Year ", CURRENT_YEAR);

    // Print the header of table
    printf(" #W:%10s%10s%10s%10s%10s%10s%10s\n",
        "Mon.", "Tues.", "Wed.", "Thur.", "Fri.", "Sat.", "Sun.");

    if (referenceDay < 1 || referenceDay > getMonthLength(2))
    {
        printf("Error input. reference day is set to Feb 15.\n");
        referenceDay = 15;
    }

    // Calculate the first day and last day in the spring semester
    int sStartSeqOfYear = getNextMonday(getDaySeq(2, referenceDay));
    int sEndSeqOfYear = getThisSunday(getDaySeq(7, 1));

    // Navigate every day in this semester
    int daySeqOfYear, daySeqOfWeek, weekSeqOfSemester;
    for (daySeqOfYear = sStartSeqOfYear, daySeqOfWeek = 0, weekSeqOfSemester = 1;
        daySeqOfYear <= sEndSeqOfYear;
        daySeqOfYear++, daySeqOfWeek++, daySeqOfWeek %= 7)
    {
        // Before Monday, print the week sequence
        if (daySeqOfWeek == 0)
        {
            printf("[%02d]", weekSeqOfSemester);
        }

        // Print the month and day for the current day
            printOneDay(daySeqOfYear);
        // After Sunday, print a new line
        if (daySeqOfWeek == 6)
        {
            printf("\n");
            weekSeqOfSemester++;
        }
    }

    printf("\n");

    return 0;
}