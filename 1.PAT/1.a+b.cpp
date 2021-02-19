/*************************************************************************
	> File Name: 1.a+b.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2021年02月18日 星期四 10时39分16秒
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
#include <stdlib.h>
using namespace std;

int a, b, ans;
string s;

void input() {
    cin >> a >> b;
    return ;
}

string solve() {
    int cnt = 0, sign = 0;//0为正数,1为负数
    ans = a + b;
    //cout << "a + b = " << ans << endl;
    if (ans == 0) {
        return to_string(0);
    } else if (ans < 0) {
        sign = 1;
    } 
    ans = abs(ans);

    while (ans) {
        //处理逗号
        if (cnt == 3) { 
            s = ',' + s;
            cnt = 0;
        }

        int temp = ans % 10;
        s = to_string(temp) + s;
        //cout << "s = " << s << endl;
        ans /= 10;
        cnt++;
    }

    if (sign == 1) {
        s = "-" + s;
    }
    return s;
}


int main() {
    input();
    cout << solve() << endl;
    return 0;
}
