/*************************************************************************
	> File Name: 21.最深的根.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2021年03月03日 星期三 11时13分10秒
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

#define MAX_N 10000
//因为是无向图，所以边是点的两倍
#define MAX_M 20000
int n;
int father[MAX_N + 5];
int h[MAX_N + 5], e[MAX_M + 5], ne[MAX_M + 5], idx;

void init_unionset() {
    for (int i = 1; i <= n; i++) father[i] = i;
    return ;
}

int find(int x) {
    if (father[x] != x) father[x] = find(father[x]);
    return father[x];
}

int merge(int a, int b) {
    int fa = find(a), fb = find(b);
    if (fa == fb) return 0;
    else father[fa] = fb;
    return 1;
}

void init_tree() {
    memset(h, -1, sizeof(h));
    return ;
}

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
    return; 
}

void input() {
    cin >> n;
    return ;
}

int dfs(int u, int father) {
    //因为是无向图，会往父节点搜，所以记录一下父节点
    //返回值是当前节点到叶子节点的最大距离，也就是当前节点作为根节点的最大深度
    int depth = 0;
    for (int i = h[u]; ~i; i = ne[i]) {
        if (e[i] == father) continue;
        depth = max(depth, dfs(e[i], u) + 1);
    }
    return depth;
}



void solve() {
    init_unionset();
    init_tree();
    int cnt_connect = n;//连通分量的数量
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        add(a, b), add(b, a);
        cnt_connect -= (merge(a, b) ? 1 : 0);//如果连通失败，则说明ab原本就是连通的
    }

    if (cnt_connect > 1) {
        printf("Error: %d components\n", cnt_connect);
        return ;
    }

    
    vector<int> nodes;
    int max_depth = -1;
    for (int i = 1; i <= n; i++) {
        int depth = dfs(i, -1);
        if (depth < max_depth) continue;
        if (depth > max_depth) {
            max_depth = depth;
            nodes.clear();
            nodes.push_back(i);
        } else {
            nodes.push_back(i);
        }
    }

    for (auto iter : nodes) cout << iter << endl;
    return ;
}

int main() {
    input();
    solve();
    return 0;
}
