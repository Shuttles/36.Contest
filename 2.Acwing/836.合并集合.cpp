/*************************************************************************
	> File Name: 836.合并集合.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2021年03月02日 星期二 12时26分55秒
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

#define MAX_N 100000

int n, m;
int father[MAX_N + 5];


void init() {
    for (int i = 0; i <= n; i++) father[i] = i;
    return ;
}

void input() {
    cin >> n >> m;
    return ;
}

int find(int x) {//返回x所在的集合的代表元素即祖宗节点 
    if (father[x] != x) father[x] = find(father[x]);//路径压缩
    return father[x];
    //胡船长写法
    //return father[x] = (father[x] == x ? x : find(father[x]));
}

void merge(int a, int b) {
    int fa = find(a), fb = find(b);
    father[fa] = fb;
    return ;
}

void solve() {
    init();
    while (m--) {
        char op;
        int a, b;
        cin >> op >> a >> b;
        if (op == 'M') {
            merge(a, b);
        } else {
            if (find(a) == find(b)) cout << "Yes" << endl;
            else cout << "No" << endl; 
        }
    }
    return ;
}


int main() {
    input();
    solve();
    return 0;
}
