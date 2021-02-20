/*************************************************************************
	> File Name: 2.01背包.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2021年02月20日 星期六 22时20分07秒
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

//dp[i, j]　对前i件物品进行选择，背包容量为j时，获得的最大总价值
//dp[i, j] = max(dp[i - 1][j], dp[i - 1][j - v[i]] + w[i])
//dp[0, j] = 0, dp[i, 0] = 0;

#define MAX_N 1000
#define MAX_V 1000

int N, V;
int dp[MAX_V + 5];

void input() {
    cin >> N >> V;
    return ;
}

int solve() {
    for (int i = 1; i <= N; i++) {
        int v, w;
        cin >> v >> w;
        for (int j = V; j >= v; j--) {
            dp[j] = max(dp[j], dp[j - v] + w);
        }
    }
    return dp[V];
}


int main() {
    input();
    cout << solve() << endl;
    return 0;
}
