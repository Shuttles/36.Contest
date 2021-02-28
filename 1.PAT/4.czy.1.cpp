/*************************************************************************
	> File Name: 4.czy.1.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2021年02月28日 星期日 16时48分13秒
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
int cnt[MAX_N + 5];
int max_depth = 0;

void input() {
    cin >> n >> m;
    return ;
}

void init() {
    memset(h, -1, sizeof(h));
    return ;
}

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
    return ;
}

void output() {
    for (int i = 1; i <= n; i++) {
        int j = h[i];
        cout << i << ": ";
        while (j != -1) {
            printf("%d ", e[j]);
            j = ne[j];
        }
        cout << endl;
    }
    return ;
}


void dfs(int u, int depth) {
    visited[u] = true;
    max_depth = max(max_depth, depth);
    if (h[u] == -1) {
        cnt[depth] += 1;
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
    for (int i = 1; i <= m; i++) {
        int id, k;
        cin >> id >> k;
        while (k--) {
            int son;
            cin >> son;
            add(id, son);
        }
    }

    dfs(1, 0);

    for (int i = 0; i <= max_depth; i++) {
        i && cout << " ";
        cout << cnt[i];
    }
    cout << endl;
    return ;
}




int main() {
    input();
    solve();
    return 0;
}
