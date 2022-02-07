/*************************************************************************
	> File Name: 898.triangleOfNum.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2022年02月07日 星期一 17时42分38秒
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


//状态1
//dp(i, j) 从底边走到(i, j)所能获得的最大值
//dp(i, j) = max(dp[i + 1][j], dp[i + 1][j + 1]) + val[i][j]
//ans = dp(1, 1)

//状态2
//dp(i, j)　从顶部走到(i, j)所能获得的最大值
//dp(i, j) = max(dp[i - 1][j], dp[i - 1][j - 1]) + val[i][j]
//ans = max(dp(n, j))

//状态1不用判断边界，且ans不用计算，故采用状态1

#define MAX_N 500

int n;
int dp[MAX_N + 5][MAX_N + 5];

void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> dp[i][j];
        }
    }
    return ;
}

int output() {
    for (int i = n - 1; i > 0; i--) {
        for (int j = 1; j <= i; j++) {
            dp[i][j] += max(dp[i + 1][j], dp[i + 1][j + 1]);
        }
    }
    return dp[1][1];
}



int main() {
    input();
    cout << output() << endl;
    return 0;
}
