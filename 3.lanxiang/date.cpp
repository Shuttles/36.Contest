/*************************************************************************
	> File Name: date.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2021年04月13日 星期二 21时00分28秒
 ************************************************************************/

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

//输入一个日期、ｎ，返回ｎ天后的日期
int year, month, day;

bool is_leap() {
    return (year % 400 == 0) || (year % 100 != 0 && year % 4 == 0);
}

bool is_end_of_month() {
    switch (month) {
        case 4:
        case 6:
        case 9:
        case 11: return day == 30;
        case 2:
            if (is_leap())
                return day == 29;
            else 
                return day == 28;
        default:
            return day == 31;
    }

}


void add_day() {
    if (is_end_of_month()) {//月末
        if (month == 12) {//年末
            day = 1, month = 1, year++;
        } else {
            day = 1, month++;
        }
    } else {
        day++;
    }
    return ;
}

void add_days(int days) {
    for (int i = 1; i <= days; i++) {
        add_day();
    }
    return ;
}


int main() {
    cin >> year >> month >> day;
    int n;
    cin >> n;
    add_days(n);
    cout << year << "-" << month << "-" << day << endl;
    return 0;
}
