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

bool is_day(int x) {
    if (x >= 1 && x <= 7) return true;
    return false;
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

string hour(int n) {
    if (n > 9) {
        return to_string(n);
    } else {
        return string("0") + to_string(n);
    }
}

string minute(int n) {
    if (n > 9) {
        return to_string(n);
    } else {
        return string("0") + to_string(n);
    }
}

void solve() {
    int day_num, hour_num, minute_num;
    int cnt = 0;
    for (int i = 0; i < s1.size(); i++) {
        if (s1[i] != s2[i]) continue;
        if (cnt == 0 && is_day(s1[i] - 'A' + 1)) {
            cnt += 1;
            day_num = (s1[i] - 'A' + 1);
        } else if (cnt == 1 && is_hour(s1[i])) {
            cnt += 1;
            hour_num = get_hour_num(s1[i]);
        }
    }

    for (int i = 0; i <= s3.size(); i++) {
        if (s3[i] != s4[i]) continue;
        if (!is_letter(s3[i])) continue;
        minute_num = i;
        break;
    }
    cout << day[day_num] << " " << hour(hour_num) << ":" << minute(minute_num) << endl; 
    return ;
}


int main() {
    input();
    solve();
    return 0;
}
