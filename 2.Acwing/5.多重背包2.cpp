/*************************************************************************
	> File Name: 4.多重背包1.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2021年02月21日 星期日 21时37分06秒
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

//光哥朴素做法：
//把问题转化成多个01背包即可！
//优化：二进制优化 可以把O(n)　降成O(logn)

#define MAX_N 1000
#define MAX_V 2000

int N, V;
int dp[MAX_V + 5];

void input() {
    cin >> N >> V;
    return ;
}

int solve() {
    int s, w, v;
    for (int i = 1; i <= N; i++) {
        cin >> v >> w >> s;
        for (int k = 1; s > 0; k *= 2) {//二进制优化
            if (s < k) k = s;
            s -= k;
            for (int j = V; j >= k * v; j--) {//一定是j >= k * v！！！
                dp[j] = max(dp[j], dp[j - k * v] + k * w);
            }
        }
    }
    return dp[V];
}


int main() {
    input();
    cout << solve() << endl;
    return 0;
}
