/*
 * Filename:    get-earliest-fall-semester.c
 * Author:      Wei Liu, liuwei@hust.edu.cn
 * Date:        2021-9-1
 * Description:  Print a serial of first week of school calander,
 *               and return the earliest one
 *
 */

#include <stdio.h>
#include <stdlib.h>


// **************************************
// Constants used in this program
// **************************************
//
#define YEAR_NUM            5
#define YEAR_MIN            2000
#define YEAR_MAX            2030
#define DATE_INFO_BRIEF     1
#define DATE_INFO_FULL      2

// **************************************
// Functions used in this program
// **************************************
//
// Functions on different year
int  isLeapYear(int year );
int  getDaySeqOnJan1(int year);
//
// Functions about month and day
int  getDaySeq(int year, int month, int day);
int  getWeekSeqOfYear(int year, int month, int day);
// 
// Functions for properties of one day
int  getMonth(int year, int daySeqOfYear);
int  getDay(int year, int daySeqOfYear);
int  getDaySeqOfWeek(int year, int daySeqOfYear);
//
// Functions for day movement calculation
int  getThisMonday(int year, int daySeqOfYear);
int  getThisSunday(int year, int daySeqOfYear);
//
// Functions support school calendar display 
void printOneDay(int year, int daySeqOfYear, int formatType);
void printOneWeek(int year, int weekSeqOfYear, int weekSeqShow);
//
// Functions support multiple year
void setYearArray(int yearArray[], int yearNum, int yearStart);


const int Month_NORMAL_YEAR [12] =
          {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int Month_LEAP_YEAR [12] =
          {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main( void )
{

    // Declare variables
    int inputYear, Years[YEAR_NUM];

    // Display the program information
    printf("Fall Calendar Comparision in %d years, please input the first year (%d-%d): \n", 
           YEAR_NUM, YEAR_MIN, YEAR_MAX - YEAR_NUM ); 
    scanf("%d" , &inputYear );
    
    if ( inputYear < YEAR_MIN || inputYear + YEAR_NUM > YEAR_MAX )
    {
        printf("Sorry, the input year is not supported.\n");
        return 1;
    }    

    // store the year data into array Years[]
    setYearArray ( Years, YEAR_NUM, inputYear );

    int i;
    int startDays[YEAR_NUM] = {0};
    for ( i = 0 ; i < YEAR_NUM; i ++ )
    {
        printf("\n%s%s%d\n", " ", "First week in Fall Calendar of Year ", Years[i] );
        printf(" #W:%10s%10s%10s%10s%10s%10s%10s\n", "Mon.","Tues.","Wed.","Thur.","Fri.","Sat.","Sun.");
        printOneWeek(Years[i], getWeekSeqOfYear( Years[i], 9, 4 ) , 1);
        startDays[i] = getThisMonday( Years[i], getDaySeq( Years[i], 9, 4 ) );
    }

    int min = 0;
    for ( i = 1 ; i < YEAR_NUM; i ++ )
    {
        min = ( startDays[i] < startDays[min] ) ? i : min;
    }

    printf("\n%s%s%d\n", " ", "Earliest Fall Semester is in Year ", Years[min]  );

    return 0;
}


int isLeapYear( int year )
{
    return ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0) ;
}


int getDaySeqOnJan1(int year)
{
    if ( year < 1900 )
    {
        printf("Error: this year is not supported. \n");
        return 0;
    }

    // given, 1900-1-1 is Monday
    int seqYear;
    int totalDays = 0;

    for ( seqYear = 1900; seqYear < year; seqYear ++ )
    {
        totalDays += ( isLeapYear(seqYear) == 1 ) ? 366 : 365;
    }

    return totalDays % 7;
}


int  getDaySeqOfWeek(int year, int daySeqOfYear)
{
    // assume one week starts with Monday
    // 0,1,2,3,4,5,6 stands for Monday, Tuesday, ..., Sunday

    return  ( daySeqOfYear + getDaySeqOnJan1(year) - 1 ) % 7;
}


int  getWeekSeqOfYear(int year, int month, int day)
{
    int days = getDaySeq(year, month, day) + getDaySeqOnJan1(year);

    if ( days % 7 == 0 )
    {
        return days / 7;
    }
    else
    {
        return days / 7 + 1;
    }
}


int  getThisMonday(int year, int referenceDay)
{
    int daySeqOfYear = referenceDay;
    int daySeqOfWeek = getDaySeqOfWeek(year, referenceDay);

    // Find the next Monday
    daySeqOfYear -= ( daySeqOfWeek == 0 ) ? 0 : daySeqOfWeek;

    return daySeqOfYear;
}


int  getThisSunday(int year, int referenceDay)
{

    int daySeqOfYear = referenceDay;
    int daySeqOfWeek = getDaySeqOfWeek(year, referenceDay);

    // Find the Sunday in this week
    daySeqOfYear += ( daySeqOfWeek == 6 ) ? 0 : 6 - daySeqOfWeek;

    return daySeqOfYear;
}


void printOneDay(int year, int daySeqOfYear, int formatType )
{
    int month = getMonth( year, daySeqOfYear );
    int day = getDay( year, daySeqOfYear );
    int daySeqOfWeek = getDaySeqOfWeek( year, daySeqOfYear );

    int isWeekend = (daySeqOfWeek == 6 || daySeqOfWeek == 5 );
    int isFullInfo = ( formatType == DATE_INFO_FULL ) ? 1 : 0;
    isFullInfo = ( month == 1 && day == 1 ) ? 1 : isFullInfo;

    // For the case of first day in calendar, and first day of one year, shows full info
    if ( isFullInfo )
    {
        if ( isWeekend ) 
        {
            printf("%3d.%02d.%02d!", year % 100, month, day );
        }
        else
        {
            printf("%4d.%02d.%02d", year % 100, month, day );
        }
        return ;
    }

    // Otherwise, print the date in brief format, only shows month for the first day
    int isMonthFirst = ( day == 1 );

    if ( isMonthFirst && isWeekend )
    {
        printf("%4s%02d.%02d!", " ", month, day);
    }
    else if ( isMonthFirst && !isWeekend )
    {
        printf("%5s%02d.%02d", " ", month, day);
    }
    else if ( !isMonthFirst && isWeekend )
    {
        printf("%7s%2d!", " ", day);
    }
    else if ( !isMonthFirst && !isWeekend )
    {
        printf("%8s%2d", " ", day);
    }

    return;
}


void printOneWeek(int year, int weekSeqOfYear, int weekSeqShow)
{

    // Before Monday, print the week sequence
    printf("[%02d]", weekSeqShow );

    // Declare variables to navigate the semester
    int sStartSeqOfYear = 7 * ( weekSeqOfYear - 1 ) - getDaySeqOnJan1(year) + 1;
    int sEndSeqOfYear = sStartSeqOfYear + 6; 
    int currentYearLength = ( isLeapYear( year ) == 1 ) ? 366 : 365;
    int daySeqOfYear = sStartSeqOfYear;

    // If this is the first week of semester, show full month and day for first day
    if ( weekSeqShow == 1 )
    {
        printOneDay( year, daySeqOfYear, DATE_INFO_FULL );      
        daySeqOfYear ++;
    }

    // Print the semester calendar
    for ( ;  daySeqOfYear <= sEndSeqOfYear ;  daySeqOfYear ++)
    {
        // Print the month and day for the current day
        if ( daySeqOfYear <= currentYearLength )
        {
            printOneDay( year, daySeqOfYear, DATE_INFO_BRIEF );
        } 
        else 
        {
            printOneDay( year + 1, daySeqOfYear - currentYearLength, DATE_INFO_BRIEF );
        }
    }

    // After Sunday, print a new line
    printf("\n");

}


// Requirement: finish the rest functions
// 
// **********************************************
// << Your source code starts here >>
//

void setYearArray(int yearArray[], int yearNum, int yearStart)
{
    
    int i;
    for(i = 0; i < yearNum; i++)
    {
        yearArray[i] = yearStart + i;
    }
    
}


int  getDaySeq( int year, int month, int day)
{
  int lengthJan = 31;
    int lengthFeb = ( isLeapYear(year) == 1 ) ? lengthJan + 29 : lengthJan + 28;
    int lengthMar = lengthFeb + 31;
    int lengthApr = lengthMar + 30;
    int lengthMay = lengthApr + 31;
    int lengthJun = lengthMay + 30;
    int lengthJul = lengthJun + 31;
    int lengthAug = lengthJul + 31;
    int lengthSep = lengthAug + 30;
    int lengthOct = lengthSep + 31;
    int lengthNov = lengthOct + 30;
    int lengthDec = lengthNov + 31;

    int daySeq = 0;

       switch(month)
    {
        case 1:
            daySeq = day;
            break;
        case 2:
            daySeq = lengthJan + day;
            break;
        case 3:
            daySeq = lengthFeb + day;
            break;
        case 4:
            daySeq = lengthMar + day;
            break;
        case 5:
            daySeq = lengthApr + day;
            break;
        case 6:
            daySeq = lengthMay + day;
            break;
        case 7:
            daySeq = lengthJun + day;
            break;
        case 8:
            daySeq = lengthJul + day;
            break;
        case 9:
            daySeq = lengthAug + day;
            break;
        case 10:
            daySeq = lengthSep + day;
            break;
        case 11:
            daySeq = lengthOct + day;
            break;
        case 12:
            daySeq = lengthNov + day;
            break;
    }
// **********************************************

    return daySeq; 
}


int  getMonth(int year, int daySeqOfYear)
{
   int lengthJan = 31;
    int lengthFeb = ( isLeapYear(year) == 1 ) ? lengthJan + 29 : lengthJan + 28;
    int lengthMar = lengthFeb + 31;
    int lengthApr = lengthMar + 30;
    int lengthMay = lengthApr + 31;
    int lengthJun = lengthMay + 30;
    int lengthJul = lengthJun + 31;
    int lengthAug = lengthJul + 31;
    int lengthSep = lengthAug + 30;
    int lengthOct = lengthSep + 31;
    int lengthNov = lengthOct + 30;
    int lengthDec = lengthNov + 31;

     

    int month = 0 ;

// **********************************************
// << Write your source code here >>
    if(daySeqOfYear <= lengthJan){
        month = 1;
    }
    else if(daySeqOfYear <= lengthFeb)
    {
        month = 2;
    }
    else if(daySeqOfYear <= lengthMar)
    {
        month = 3;
    }
    else if(daySeqOfYear <= lengthApr)
    {
        month = 4;
    }
    else if(daySeqOfYear <= lengthMay)
    {
        month = 5;
    }
    else if(daySeqOfYear <= lengthJun)
    {
        month = 6;
    }
    else if(daySeqOfYear <= lengthJul)
    {
        month = 7;
    }
    else if(daySeqOfYear <= lengthAug)
    {
        month = 8;
    }
    else if(daySeqOfYear <= lengthSep)
    {
        month = 9;
    }
    else if(daySeqOfYear <= lengthOct)
    {
        month = 10;
    }
    else if(daySeqOfYear <= lengthNov)
    {
        month = 11;
    }
    else if(daySeqOfYear <= lengthDec)
    {
        month = 12;
    }   
        

    return month;
}


int  getDay(int year, int daySeqOfYear)
{
  int lengthJan = 31;
    int lengthFeb = ( isLeapYear(year) == 1 ) ? lengthJan + 29 : lengthJan + 28;
    int lengthMar = lengthFeb + 31;
    int lengthApr = lengthMar + 30;
    int lengthMay = lengthApr + 31;
    int lengthJun = lengthMay + 30;
    int lengthJul = lengthJun + 31;
    int lengthAug = lengthJul + 31;
    int lengthSep = lengthAug + 30;
    int lengthOct = lengthSep + 31;
    int lengthNov = lengthOct + 30;
    int lengthDec = lengthNov + 31;

    int day = 0;
    if(daySeqOfYear <= lengthJan){
        day = daySeqOfYear;
    }
    else if(daySeqOfYear <= lengthFeb)
    {
        day = daySeqOfYear - lengthJan;
    }
    else if(daySeqOfYear <= lengthMar)
    {
        day = daySeqOfYear - lengthFeb;
    }
    else if(daySeqOfYear <= lengthApr)
    {
        day = daySeqOfYear - lengthMar;
    }
    else if(daySeqOfYear <= lengthMay)
    {
        day = daySeqOfYear - lengthApr;
    }
    else if(daySeqOfYear <= lengthJun)
    {
        day = daySeqOfYear - lengthMay;
    }
    else if(daySeqOfYear <= lengthJul)
    {
        day = daySeqOfYear - lengthJun;
    }
    else if(daySeqOfYear <= lengthAug)
    {
        day = daySeqOfYear - lengthJul;
    }
    else if(daySeqOfYear <= lengthSep)
    {
        day = daySeqOfYear - lengthAug;
    }
    else if(daySeqOfYear <= lengthOct)
    {
        day = daySeqOfYear - lengthSep;
    }
    else if(daySeqOfYear <= lengthNov)
    {
        day = daySeqOfYear - lengthOct;
    }
    else if(daySeqOfYear <= lengthDec)
    {
        day = daySeqOfYear - lengthNov;
    }

    return day;
}

//
// << Your source code stops here >>
// **********************************************



