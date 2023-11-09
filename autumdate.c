#include<stdio.h>
//判断是否为闰年
int isLeapYear(int year)
{
  return (year % 4==0&&year % 100 !=0||year%400!=0);
}
//获取某年某月的天数
int getDayOfMonth(int year, int month )
{
    int days[]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30,31};
    if(month ==2&&isLeapYear(year))
    {
        return days[month-1]+1;
    }
    else
    {
        return days[month-1];
    }
}
//获取某年某月某日是星期几
int getWeekday(int year,int month,int day)
{
    int weekday;
    if(month<3)
    {
        month +=12;
        year--;
    }
    weekday =(day+2*month+3*(month+1)/5+year+year/4-year/100+year/400)%7;
    return weekday;
}
void printfWeek(int year,int month, int weekStartDay)
{
    int day=weekStartDay;
    for(int i=0;i<7;i++)
    {
        if(day>getDayOfMonth(year,month))
        {
            if(month==12)
            {
                year++;
                month=0;
            }
            else
            {
                month++;
            }
            day-=getDayOfMonth(year,month-1);
        }
        printf("%02d%02d",month,day);
        day++;
    } 
}
void generateSchoolCalendar(int startYear,int endYear,int startMonth,
int startDay,int endMonth,int endDay)
{
    int year,month,day;
    year=startYear;
    month=9;
    day=1;
    int weekday=getWeekday(year,month,day);
    if(weekday>1)
    {
        day+=8-weekday;
    }
    while ((year<=endYear&&(year!=endYear||month<=endMonth||(month==endMonth&&day<=endDay))))
    {
        printfWeek(year,month,day);
        printf("\n");
        day+=7;
        weekday=getWeekday(year,month,day);
        if(weekday>1)
        {
            day+=8-weekday;
        }
        if(month==1&&day==1)
        {
            year++;
            month=9;
            day=1;
            weekday=getWeekday(year,month,day);
            if(weekday>1)
            {
                day+=8-weekday;
            }
        }
            if(year==endYear&&month==endMonth&&day)
            {
                break;
            }

        }
    }
    int main(void)
    {
        int endDay;
        printf("请输入1月份的某日:");
        scanf("%d",&endDay);
        if(endDay<=0||endDay>31)
        {
            printf("Error input");
            
        }
        else
        {
            generateSchoolCalendar(2023,2024,1,1,1,endDay);
            return 0;
            
        }
    }
    




