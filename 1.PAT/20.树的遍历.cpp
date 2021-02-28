/*************************************************************************
	> File Name: 20.树的遍历.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2021年02月28日 星期日 20时48分31秒
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

#define MAX_N 40

int n;
int postorder[MAX_N + 5], inorder[MAX_N + 5];
unordered_map<int, int> l, r, ind_inorder;
int q[MAX_N + 5], head, tail;

void input() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> postorder[i];
    for (int i = 0; i < n; i++) {
        cin >> inorder[i];
        ind_inorder[inorder[i]] = i;//建立索引
    }
    return ;
}

int build(int il, int ir, int pl, int pr) {
    int root = postorder[pr];
    int ind = ind_inorder[root];
    if (il < ind) l[root] = build(il, ind - 1, pl, pl + (ind - 1 - il));//如果左子树存在
    if (ir > ind) r[root] = build(ind + 1, ir, pl + (ind - 1 - il) + 1, pr - 1);//如果右子树存在
    return root;
}

void bfs(int root) {
    head = tail = 0;
    q[tail++] = root;

    while (head < tail) {
        int temp = q[head++];
        if (l.count(temp)) q[tail++] = l[temp];
        if (r.count(temp)) q[tail++] = r[temp];
    }

    for (int i = 0; i < tail; i++) {
        i && cout << " ";
        cout << q[i];
    }
    cout << endl;
    return ;
}

void solve() {
    int root = build(0, n - 1, 0, n - 1);//建树，中序是从0~n-1，后序也是
    bfs(root);
    return ;
}


int main() {
    input();
    solve();
    return 0;
}
