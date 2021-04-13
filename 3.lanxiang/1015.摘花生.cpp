/*************************************************************************
	> File Name: 1015.摘花生.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2021年04月12日 星期一 12时19分31秒
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
#include <cstring>
#include <vector>
using namespace std;

//dp[i][j] 代表从(1, 1)走到(i, j)的最大路径和
//dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + w[i][j]

#define MAX_N 100
int T;
int n, m;
int w[MAX_N + 5][MAX_N + 5];
int dp[MAX_N + 5][MAX_N + 5];



int main() {
    cin >> T;
    while (T--) {
        memset(dp, 0, sizeof(dp));
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> w[i][j];
            }
        }

        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + w[i][j];
            }
        }
        cout << dp[n][m] << endl;
    }
    return 0;
}
