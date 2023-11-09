#include <stdio.h>
#include <stdlib.h>

#include "springdate.h"

int  getMonthLength(int month)
{
	int length = 0;
	switch (month) {
	case 1: length = 31; break;
	case 2: length = (IS_LEAPYEAR == 0) ? 28 : 29; break;
	case 3: length = 31; break;
	case 4: length = 30; break;
	case 5: length = 31; break;
	case 6: length = 30; break;
	case 7: length = 31; break;
	case 8: length = 31; break;
	case 9: length = 30; break;
	case 10: length = 31; break;
	case 11: length = 30; break;
	case 12: length = 31; break;
	}
	return length;
}


int  getDaySeq(int month, int day)
{
	int dayseq = day;
	for (month; month > 1; month--) {
		dayseq += getMonthLength(month - 1);
	}
	return dayseq;
}


int  getNextMonday(int referenceDay)
{
	int SeqOfWeek = getDaySeqOfWeek(referenceDay);
	int difference = 7 - SeqOfWeek;
	return referenceDay + difference;
}



void printOneDay(int daySeqOfYear)
{
	printf("%4s%02d.%02d", " ", getMonth(daySeqOfYear), getDay(daySeqOfYear));
	if (getDaySeqOfWeek(daySeqOfYear) == 5) {
		printf("!");
	}
	else if (getDaySeqOfWeek(daySeqOfYear) == 6) {
		printf("*");
	}
	else {
		printf("$");
	}
	// input your source code here
}

int  getMonth(int daySeqOfYear)
{
	int month;
	for (month = 0; daySeqOfYear > 0; month++) {
		daySeqOfYear -= getMonthLength(month + 1);
	}
	return month;
}


int  getDay(int daySeqOfYear)
{
	int month = getMonth(daySeqOfYear);
	int length = 0;
	for (month = getMonth(daySeqOfYear); month > 1; month--) {
		length += getMonthLength(month - 1);
	}
	return daySeqOfYear - length;
}


int  getDaySeqOfWeek(int daySeqOfYear)
{
	// assume one week starts with Monday
	// 0,1,2,3,4,5,6 stands for Monday, Tuesday, ..., Sunday

	return  (daySeqOfYear + WEEKDAY_JAN1 - 1) % 7;
}


int  getThisSunday(int referenceDay)
{
	int SeqOfWeek = getDaySeqOfWeek(referenceDay);
	int difference = 6 - SeqOfWeek;
	return referenceDay + difference;
}