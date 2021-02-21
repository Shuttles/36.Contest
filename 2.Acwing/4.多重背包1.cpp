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

#define MAX_N 100
#define MAX_V 100

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
        for (int k = 1; k <= s; k++) {
            for (int j = V; j >= v; j--) {
                dp[j] = max(dp[j], dp[j - v] + w);
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
