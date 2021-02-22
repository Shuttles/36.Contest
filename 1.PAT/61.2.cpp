/*************************************************************************
	> File Name: 169.约会.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2021年02月22日 星期一 11时04分28秒
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

string s1, s2, s3, s4;
string day[8] = {
    string(""),
    string("MON"),
    string("TUE"),
    string("WED"),
    string("THU"),
    string("FRI"),
    string("SAT"),
    string("SUN"),
};

void input() {
    cin >> s1 >> s2 >> s3 >> s4;
    return ;
}

bool is_hour(char ch) {
    if (ch >= '0' && ch <= '9') return true;
    if (ch >= 'A' && ch <= 'N') return true;
    return false;
}

bool is_letter(char ch) {
    if (ch >= 'a' && ch <= 'z') return true;
    if (ch >= 'A' && ch <= 'Z') return true;
    return false;
}

int get_hour_num(char ch) {
    if (ch >= '0' && ch <= '9') {
        return (ch - '0');
    } else {
        return (ch - 'A' + 10);
    }
}

void solve() {
    int day_num, hour_num, minute_num;
    int k = 0;
    //获得日期
    while (1) {
        if (s1[k] == s2[k] && s1[k] >= 'A' && s1[k] <= 'G') break;
        k++;
    }
    day_num = s1[k] - 'A' + 1;

    //获得小时
    k++;//这个很重要！！
    while (1) {
        if (s1[k] == s2[k] && (is_hour(s1[k]))) break;
        k++;
    }
    hour_num = get_hour_num(s1[k]);

    //获得分钟
    for (int i = 0; i <= s3.size(); i++) {
        if (s3[i] != s4[i] || !is_letter(s3[i])) continue;
        minute_num = i;
        break;
    }
    cout << day[day_num] << " ";
    printf("%02d:", hour_num);
    printf("%02d\n", minute_num);
    return ;
}


int main() {
    input();
    solve();
    return 0;
}
