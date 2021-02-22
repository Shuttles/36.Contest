/*************************************************************************
	> File Name: 7.最大自序和.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2021年02月22日 星期一 15时47分44秒
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

//dp[i] 表示以第i位作为结尾的最大子序和的值
//dp[i] = dp[i - 1] + num[i] (if dp[i - 1] > 0)
//      = num[i] (if dp[i - 1] <= 0)
//dp[0] = 0
//
//yxc做法：
//dp[i] = max(num[i], dp[i - 1] + num[i])
//其实本质上是一样的，但是从思维上来说，yxc的状态转移方程更好理解

#define MAX_N 100000
int n;
long long num[MAX_N + 5];
long long dp[MAX_N + 5];
int flag = 1;//如果所有数字均为负数，flag = 1

void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> num[i];
        if (num[i] >= 0) flag = 0;
    }
    return;
}

void output() {
    for (int i = 1; i <= n; i++) {
        cout << dp[i] << endl;
    }
    return ;
}

void solve() {
    dp[0] = -1;
    long long ans = INT32_MIN; 
    int first = 1, last = 1;
    for (int i = 1, start = i; i <= n; i++) {
        //dp[i] = max(num[i], dp[i - 1] + num[i]);原来的写法，后来为了求解子序列的第一个元素和最后一个元素，改变写法
        if (dp[i - 1] < 0) {
            dp[i] = num[i];
            start = i;//前面的子序列被抛弃了
        } else {
            dp[i] = dp[i - 1] + num[i];
        }
        if (dp[i] > ans) {
            ans = dp[i];
            first = start, last = i;
        }
    }


    if (flag) cout << 0 << " " << num[1] << " " << num[n] << endl;
    else cout << ans << " " << num[first] << " " << num[last] << endl;
    return ;
}


int main() {
    input();
    solve();
    return 0;
}
