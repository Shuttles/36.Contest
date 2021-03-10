/*************************************************************************
	> File Name: 3.treeLeftView.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2021年03月10日 星期三 18时41分15秒
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

#define MAX_N 20 

int n;
int inorder[MAX_N + 5], preorder[MAX_N + 5];
unordered_map<int, int> l, r, ind_inorder, level;
int q[MAX_N + 5], head, tail;

void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> inorder[i];
        ind_inorder[inorder[i]] = i;//建立索引
    }
    for (int i = 0; i < n; i++) cin >> preorder[i];
    return ;
}

int build(int il, int ir, int pl, int pr) {
    int root = preorder[pl];
    int ind = ind_inorder[root];
    if (il < ind) l[root] = build(il, ind - 1, pl + 1, pl + 1 + (ind - 1- il));
    if (ir > ind) r[root] = build(ind + 1, ir, pl + 1 + (ind - 1 - il) + 1, pr);
    return root;
}

void pre_order(int u, int depth) {//遍历一遍的目的是打上层数
    level[u] = depth;
    if (l.count(u)) pre_order(l[u], depth + 1);
    if (r.count(u)) pre_order(r[u], depth + 1);
    return ;
}

void output_level() {
    for (auto iter : level) {
        printf("%d在第", iter.first);
        printf("%d层\n", iter.second);
    }
    return ;
}

void bfs(int root) {
    head = tail = 0;
    q[tail++] = root;

    while (head < tail) {
        int temp = q[head++];
        if (l.count(temp)) q[tail++] = l[temp];
        if (r.count(temp)) q[tail++] = r[temp];
    }

    int cnt = -1;//当前输出到哪一层了
    for (int i = 0; i < tail; i++) {
        if (level[q[i]] == cnt) continue;
        i && cout << " ";
        cout << q[i];
        cnt++;
    }
    cout << endl;
    return ;
}

void solve() {
    int root = build(0, n - 1, 0, n - 1);
    pre_order(root, 0);
    //output_level();
    bfs(root);
    return ;
}

int main() {
    input();
    solve();
    return 0;
}
