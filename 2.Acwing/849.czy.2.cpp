/*************************************************************************
	> File Name: 849.czy.2.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2021年03月09日 星期二 15时32分13秒
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

#define MAX_N 500
#define MAX_M 100000
#define INF 0x3f3f3f3f

int n, m;
int g[MAX_N + 5][MAX_N + 5];
int dist[MAX_N + 5];
bool s[MAX_N + 5];

void init_g() {
    memset(g, 0x3f, sizeof(g));
    return ;
}

void input() {
    init_g();
    cin >> n >> m;
    while (m--) {
        int x, y, z;
        cin >> x >> y >> z;
        g[x][y] = min(g[x][y], z);
    }
    return ;
}


int dijkstra() {
    memset(dist, 0x3f, sizeof(dist));
    dist[1] = 0;

    for (int i = 1; i <= n; i++) {
        int temp = -1;
        for (int j = 1; j <= n; j++) {
            if (!s[j] && (temp == -1 || dist[j] < dist[temp])) temp = j;
        }
        s[temp] = true;

        for (int j = 1; j <= n; j++) {
            dist[j] = min(dist[j], dist[temp] + g[temp][j]);
        }
    }
    if (dist[n] == INF) return -1;
    return dist[n];
}


int solve() {
    int ans = dijkstra();
    return ans;
}


int main() {
    input();
    cout << solve() << endl;
    return 0;
}
