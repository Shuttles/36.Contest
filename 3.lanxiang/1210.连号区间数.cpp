/*************************************************************************
	> File Name: 1210.连号区间数.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2021年04月13日 星期二 14时42分52秒
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

#define MAX_N 10000
#define INF 0x3f3f3f3f
int n;
int arr[MAX_N + 5];


void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    return ;
}

int solve() {
    int ans = 0;
    for (int i = 1; i <= n; i++) {//left end
        int max_num = 0, min_num = INF;
        for (int j = i; j <= n; j++) {//right end
            max_num = max(max_num, arr[j]);
            min_num = min(min_num, arr[j]);
            if (max_num - min_num == j - i) ans += 1;
        }
    }
    return ans;
}


int main() {
    input();
    cout << solve() << endl;
    return 0;
}
