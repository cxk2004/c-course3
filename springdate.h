#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED

// **************************************
// Constants used for this program
// **************************************
//
// Constant: the current year
#define CURRENT_YEAR    2023
//
// Constant: the sequence of weekday for Jan. 1
// 0,1,2,3,4,5,6 stands for Monday, Tuesday, ..., Sunday
#define WEEKDAY_JAN1    6
#define IS_LEAPYEAR   0


// **************************************
// Functions used in this program
// **************************************
//
// Functions about month and day

int  getMonthLength(int month);
int  getDaySeq(int month, int day);


// Functions for properties of one day
int  getMonth(int daySeqOfYear);
int  getDay(int daySeqOfYear);
int  getDaySeqOfWeek(int daySeqOfYear);
//
// Functions for day movement calculation
int  getNextMonday(int daySeqOfYear);
int  getThisSunday(int daySeqOfYear);
//
// Functions support school calendar display
void printOneDay(int daySeqOfYear);


#endif // DATE_H_INCLUDED