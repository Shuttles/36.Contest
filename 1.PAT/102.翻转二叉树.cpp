/*************************************************************************
	> File Name: 102.翻转二叉树.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2021年03月11日 星期四 21时21分07秒
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

#define MAX_N 10

int n;
int l[MAX_N + 5], r[MAX_N + 5];
bool has_father[MAX_N + 5];//用来求root

void input() {
    cin >> n;
    memset(l, -1, sizeof(l));
    memset(r, -1, sizeof(r));

    for (int i = 0; i < n; i++) {
        char lc, rc;
        cin >> lc >> rc;
        if (lc != '-') l[i] = lc - '0', has_father[l[i]] = true;
        if (rc != '-') r[i] = rc - '0', has_father[r[i]] = true; 
    }
    return ;
}

void dfs_reverse(int root) {
    if (root == -1) return ;

    dfs_reverse(l[root]);
    dfs_reverse(r[root]);
    swap(l[root], r[root]);
    return ;
}


void bfs(int root) {
    int q[MAX_N + 5], head, tail;
    head = tail = 0;
    q[tail++] = root;

    while (head < tail) {
        int temp = q[head++];
        if (l[temp] != -1) q[tail++] = l[temp];
        if (r[temp] != -1) q[tail++] = r[temp];
    }

    for (int i = 0; i < tail; i++) {
        i && cout << " ";
        cout << q[i];
    }
    cout << endl;
    return ;
}

void in_order(int root, int &cnt) {
    if (root == -1) return ;
    
    in_order(l[root], cnt);

    cout << root;
    if (cnt++ != n)  cout << " ";

    in_order(r[root], cnt);
    return ;
}

void solve() {
    int root = 0;
    while (has_father[root]) root++;//寻找root

    dfs_reverse(root);
    bfs(root);
    int cnt = 1;
    in_order(root, cnt);
    cout << endl;
    return ;
}

int main() {
    input();
    solve();
    return 0;
}
