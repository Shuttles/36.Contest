/*************************************************************************
	> File Name: 4.数叶子节点.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2021年02月23日 星期二 10时54分02秒
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

#define MAX_N 100
int n, m;
int h[MAX_N + 5], e[MAX_N + 5], ne[MAX_N + 5], idx;
bool visited[MAX_N + 5];
int cnt[MAX_N + 5];//存每一层的叶子节点的数量
int max_depth;

void input() {
    cin >> n >> m;
    return;
}

void init() {
    memset(h, -1, sizeof(h));
    return ;
}

void add(int a, int b) {//添加一条从a到b的边
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
    return ;
}

void dfs(int u, int depth) {
    visited[u] = true;
    if (h[u] == -1) {
        cnt[depth] += 1;
        max_depth = max(max_depth, depth);
        return ;
    }

    for (int i = h[u]; i != -1; i = ne[i]) {
        if (visited[e[i]]) continue;
        dfs(e[i], depth + 1);
    }
    return ;
}

void solve() {
    init();
    for (int i = 0; i < m; i++) {
        int id, k;
        cin >> id >> k;
        while (k--) {
            int son;
            cin >> son;
            add(id, son);
        }
    }
    dfs(1, 0);

    cout << cnt[0];
    for (int i = 1; i <= max_depth; i++) {
        cout << " " << cnt[i];
    }
    cout << endl;
    return ;
}

int main() {
    input();
    solve();
    return 0;
}
