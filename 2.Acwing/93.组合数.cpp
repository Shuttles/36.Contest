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

void dfs(int depth) {
    if (depth > m) {
        output(m);
        return ;
    }

    int start = 1;
    if (depth > 1) start = ans[depth - 1] + 1;//只朝着一个方向去搜索
    for (int i = start; i <= n; i++) {
        ans[depth] = i;
        dfs(depth + 1);
    }
    return ;
}

void solve() {
    dfs(1);
    return ;
}




int main() {
    input();
    solve();
    return 0;
}
