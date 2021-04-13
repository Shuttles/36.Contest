/*************************************************************************
	> File Name: 2.01背包.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2021年04月12日 星期一 11时10分29秒
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

//dp[i][j] 代表对前i件物品，背包容量为j时可取的最大值
//dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - v[i]] + w[i])
//dp[0][j] = 0, dp[i][0] = 0
//最后要求的就是dp[n][V]

//优化：代码实现方面的优化，即可以把状态压缩到一维（注意此时状态定义本身是没有变的！）
#define MAX_N 1000
#define MAX_V 1000
int n, V;
int dp[MAX_V + 5];

void input() {
    cin >> n >> V;
    for (int i = 1; i <= n; i++) {
        int v, w;
        cin >> v >> w;
        for (int j = V; j >= v; j--) {
            //dp[i][j] = dp[i - 1][j];
            dp[j] = max(dp[j], dp[j - v] + w);
        }
    }
    return ;
}

int solve() {
    return dp[V];
}


int main() {
    input();
    cout << solve() << endl;
    return 0;
}
