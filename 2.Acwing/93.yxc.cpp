/*************************************************************************
	> File Name: 93.组合数.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2021年04月03日 星期六 20时57分42秒
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

#define MAX_N 30
int n, m;
int ans[MAX_N + 5];

void input() {
    cin >> n >> m;
    return ;
}

void output(int len) {
    for (int i = 1; i <= len; i++) {
        (i - 1) && cout << " ";
        cout << ans[i];
    }
    cout << endl;
    return ;
}

void dfs(int depth, int start) {
    if ((depth - 1) + (n - start + 1) < m) return ;//剪枝，如果把后面所有数都选上，都不够m个
    if (depth > m) {
        output(m);
        return ;
    }

    for (int i = start; i <= n; i++) {
        ans[depth] = i;
        dfs(depth + 1, i + 1);
    }
    return ;
}

void solve() {
    dfs(1, 1);
    return ;
}




int main() {
    input();
    solve();
    return 0;
}
