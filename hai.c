#include <stdio.h>

// 计算某个月的第一天是星期几
int calculateStartDay(int year, int month) {
    int a = (14 - month) / 12;
    int y = year - a;
    int m = month + 12 * a - 2;
    int start_day = (1 + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12) % 7;

    return start_day;
}

// 打印校历
void printCalendar(int year, int start_month, int end_month, int end_day) {
    int start_day = calculateStartDay(year, start_month);
    int days_in_month;
    int day = 1;
    int end_weekday;

    // 根据月份确定该月的天数
    if (start_month == 2) {
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
            days_in_month = 29;
        } else {
            days_in_month = 28;
        }
    } else if (start_month == 4 || start_month == 6 || start_month == 9 || start_month == 11) {
        days_in_month = 30;
    } else {
        days_in_month = 31;
    }

    // 打印校历标题
    printf("华中科技大学%d年秋季校历\n", year);
    printf("星期一 星期二 星期三 星期四 星期五 星期六 星期日\n");

    // 打印校历内容
    for (int i = 0; i < start_day; i++) {
        printf("     ");
    }

    while (start_month <= end_month) {
        while (day <= days_in_month) {
            printf("%2d   ", day);

            if ((start_day + day) % 7 == 0) {
                printf("\n");
            }

            day++;
        }

        start_month++;
        days_in_month = (start_month == 2) ? ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) ? 29 : 28 : (start_month == 4 || start_month == 6 || start_month == 9 || start_month == 11) ? 30 : 31;
    }

    // 计算学期结束的星期日
    end_weekday = (start_day + end_day - 1) % 7;
    for (int i = 0; i < (7 - end_weekday - 1); i++) {
        printf("     ");
    }
    printf("%2d\n", end_day);
}

int main() {
    int end_day;

    printf("请输入1月份的某日作为参考日：");
    scanf("%d", &end_day);

    // 打印2023年秋季校历
    printCalendar(2023, 9, 12, end_day);

    return 0;
}

