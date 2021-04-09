/*************************************************************************
	> File Name: 796.子矩阵的和.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2021年04月09日 星期五 20时25分05秒
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

#define MAX_N 1000
#define MAX_M 1000
int n, m, q;
int val[MAX_N + 5][MAX_M + 5];
int s[MAX_N + 5][MAX_M + 5];

void input() {
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> val[i][j];
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + val[i][j];
        }
    }
    return ;
}




void solve() {
    int x1, y1, x2, y2;
    while (q--) {
        cin >> x1 >> y1 >> x2 >> y2;
        cout << s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1] << endl;
    }
    return ;
}


int main() {
    input();
    solve();
    return 0;
}
