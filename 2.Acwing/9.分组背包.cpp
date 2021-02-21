/*************************************************************************
	> File Name: 9.分组背包.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2021年02月21日 星期日 11时48分18秒
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

//dp[i, j]　对前i组物品进行选择，背包容量为j　可以获得的最大总价值
//dp[i, j] = max(dp[i - 1][j - v[i][k]] + w[i][k]) v[i][k]<=j

#define MAX_N 100
#define MAX_V 100
#define MAX_S 100

int N, V;
int v[MAX_N + 5], w[MAX_N + 5];
int dp[MAX_N + 5][MAX_V + 5];

void input() {
    cin >> N >> V;
    return ;
}

int solve() {
    int s;
    for (int i = 1; i <= N; i++) {
        cin >> s;
        for (int k = 1; k <= s; k++)  cin >> v[k] >> w[k];
        for (int j = 1; j <= V; j++) {
            dp[i][j] = dp[i - 1][j];//第i组一个都不选
            for (int k = 1; k <= s; k++) {
                if (v[k] > j) continue;
                dp[i][j] = max(dp[i][j], dp[i - 1][j - v[k]] + w[k]);
            }
        }
    }
    
    return dp[N][V];
}


int main() {
    input();
    cout << solve() << endl;
    return 0;
}
