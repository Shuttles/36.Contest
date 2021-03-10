/*************************************************************************
	> File Name: 996.permutation.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2021年03月10日 星期三 20时59分46秒
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

//为了复习dfs而写的

#define MAX_N 10

int n;
int permutation[MAX_N + 5];
bool used[MAX_N + 5];

void input() {
    cin >> n;
    return ;
}

void output() {
    for (int i = 1; i <= n; i++) {
        (i != 1) && cout << " ";
        cout << permutation[i];
    }
    cout << endl;
    return ;
}

void dfs(int step) {
    if (step == n + 1) {
        output();
        return ;
    }

    for (int i = 1; i <= n; i++) {
        if (used[i]) continue;
        permutation[step] = i;
        used[i] = true;

        dfs(step + 1);
        used[i] = false;
    }
    return ;
}


void solve() {
    dfs(1);
    return ;
}

int main() {
    input();
    solve();
    return 0;
}
