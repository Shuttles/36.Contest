/*************************************************************************
	> File Name: 99.激光炸弹.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2021年04月09日 星期五 21时32分03秒
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

#define MAX_X 5000
#define MAX_Y 5000
int n, r;
//int mmap[MAX_X + 5][MAX_Y + 5];
int s[MAX_X + 5][MAX_Y + 5];
int x_len, y_len;

void input() {
    cin >> n >> r;
    int x, y, w;
    for (int i = 0; i < n; i++) {
        cin >> x >> y >> w;
        x += 1, y += 1;
        if (s[x][y]) s[x][y] += w;
        else s[x][y] = w;
        x_len = max(x_len, x);
        y_len = max(y_len, y);
    }
    return ;
}

void init() {
    for (int i = 1; i <= x_len; i++) {
        for (int j = 1; j <= y_len; j++) {
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + s[i][j];
        }
    }

    return ;
}

int get_sum(int x1, int y1, int x2, int y2) {
    return (s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1]);
}

int solve() {
    init();
    int ans = 0;
    if (r > x_len && r > y_len) return s[x_len][y_len];
    if (r > x_len) {
        for (int i = 1; i <= y_len - r + 1; i++) {
            ans = max(ans, get_sum(1, i, x_len, i + r - 1));
        }
        return ans;
    }
    if (r > y_len) {
        for (int i = 1; i <= x_len - r + 1; i++) {
            ans = max(ans, get_sum(i, 1, i + r - 1, y_len));
        }
        return ans;
    }
    
    for (int i = 1; i <= x_len - r + 1; i++) {
        for (int j = 1; j <= y_len - r + 1; j++) {
            ans = max(ans, get_sum(i, j, i + r - 1, j + r - 1));
        }
    }
    return ans;
}


int main() {
    input();
    cout << solve() << endl;
    return 0;
}
