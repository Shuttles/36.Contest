/*************************************************************************
	> File Name: 94.排列数.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2021年04月03日 星期六 20时49分39秒
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

#define MAX_N 9
int n;
int ans[MAX_N + 5];
bool used[MAX_N + 5];

void input() {
    cin >> n;
    return ;
}

void output(int len) {
    for (int i = 1; i <= len; i++) {
        (i != 1) && cout << " ";
        cout << ans[i];
    }
    cout << endl;
    return ;
} 

void dfs(int depth) {
    if (depth > n) {
        output(n);
        return ;
    }

    for (int i = 1; i <= n; i++) {
        if (used[i]) continue;
        used[i] = true;
        ans[depth] = i;
        dfs(depth + 1);
        used[i] = false;
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
