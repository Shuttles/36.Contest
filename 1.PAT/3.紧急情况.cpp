/*************************************************************************
	> File Name: 3.紧急情况.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2021年03月09日 星期二 22时09分19秒
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

int n, m, S, T;
int g[MAX_N + 5][MAX_N + 5];
int w[MAX_N + 5];
int dist[MAX_N + 5];
bool s[MAX_N + 5];
int cnt[MAX_N + 5];//cnt[i] 表示从起点走到i的最短路径的数量
int sum[MAX_N + 5];//sum[i] 表示从起点走到i的最大点权和

void input() {
    memset(g, 0x3f, sizeof(g));
    cin >> n >> m >> S >> T;
    for (int i = 0; i < n; i++) cin >> w[i];
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a][b] = g[b][a] = min(g[a][b], c);
    }
    return ;
}

void dijkstra() {
    memset(dist, 0x3f, sizeof(dist));
    dist[S] = 0, cnt[S] = 1, sum[S] = w[S];

    for (int i = 0; i < n; i++) {
        int temp = -1;
        for (int j = 0; j < n; j++) {
            if (!s[j] && (temp == -1 || dist[j] < dist[temp])) temp = j;
        }
        s[temp] = true;
        
        //下面就是改动部分
        for (int j = 0; j < n; j++) {
            if (dist[temp] + g[temp][j] < dist[j]) {
                dist[j] = dist[temp] + g[temp][j];
                cnt[j] = cnt[temp];
                sum[j] = sum[temp] + w[j];
            } else if (dist[temp] + g[temp][j] == dist[j]) {
                cnt[j] += cnt[temp];
                sum[j] = max(sum[j], sum[temp] + w[j]);
            }
        }
    }
    return ;
}

void solve() {
    dijkstra();
    cout << cnt[T] << " " << sum[T] << endl;
    return ;
}

int main() {
    input();
    solve();
    return 0;
}
