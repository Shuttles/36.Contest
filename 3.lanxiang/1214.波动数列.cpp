/*************************************************************************
	> File Name: 1214.波动数列.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2021年04月12日 星期一 17时04分54秒
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


//dp[i][j] 只考虑前i项，目前总和除以n的余数是j的方案集合
//dp[i][j] = dp[i - 1][(j - i * a) % n] + dp[i - 1][(j + i * b) % n]
//dp[0][0] = 1, dp[0][i] = 0
//最后要求dp[n - 1][s % n]
#define MOD_NUM 100000007
#define MAX_N 1000

int n, s, a, b;
int dp[MAX_N + 5][MAX_N + 5];

void input() {
    cin >> n >> s >> a >> b;
    return ;
}

int get_mod(int a, int b) {//求a % b的正余数
    return (a % b + b) % b;
}

int solve() {
    dp[0][0] = 1;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n; j++) {//只需枚举0 ~ n-1
            dp[i][j] = (dp[i - 1][get_mod(j - i * a, n)] + dp[i - 1][get_mod(j + i * b, n)]) % MOD_NUM;
        }
    }
    return dp[n - 1][get_mod(s, n)];
}


int main() {
    input();
    cout << solve() << endl;
    return 0;
}
