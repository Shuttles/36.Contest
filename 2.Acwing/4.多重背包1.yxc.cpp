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

//yxc朴素做法：
//遍历一下求出需要几件的情况可以获得最大值！

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
        for (int j = V; j >= v; j--) {
            for (int k = 1; k <= s && k * v <= j; k++)  //由于是一维数组，所以天然包含了k = 0的情况！
                dp[j] = max(dp[j], dp[j - k * v] + k * w);
        }
    }
    return dp[V];
}


int main() {
    input();
    cout << solve() << endl;
    return 0;
}
