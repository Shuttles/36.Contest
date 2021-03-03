/*************************************************************************
	> File Name: 849.Dijkstra求最短路1.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2021年03月03日 星期三 22时09分49秒
 ************************************************************************/

//裸的dijkstra
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
#include <cstring>
using namespace std;

#define MAX_N 500
#define MAX_M 100000
#define INF 0x3f

int n, m;
int g[MAX_N + 5][MAX_N + 5];
int dist[MAX_N + 5];
bool s[MAX_N + 5];

void input() {
    cin >> n >> m;
    memset(g, INF, sizeof(g));
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a][b] = min(g[a][b], c);
    }
    return ;
}

int dijkstra() {
    memset(dist, INF, sizeof(dist));
    dist[1] = 0;

    for (int i = 1; i < n; i++) {
        int temp = -1;
        for (int j = 1; j <= n; j++) {
            if (!s[j] && (temp == -1 || dist[j] < dist[temp])) temp = j;
        }
        s[temp] = true;//加入集合s

        for (int j = 1; j <= n; j++) {
            dist[j] = min(dist[j], dist[temp] + g[temp][j]);
        }
    }

    if (dist[n] == 0x3f3f3f3f) return -1;
    return dist[n];
}

void solve() {
    int ans = dijkstra();
    cout << ans << endl;
    return ;
}




int main() {
    input();
    solve();
    return 0;
}
