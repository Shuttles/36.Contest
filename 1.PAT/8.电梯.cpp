/*************************************************************************
	> File Name: 8.电梯.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2021年03月08日 星期一 21时57分31秒
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

#define MAX_N 100

int n;
int arr[MAX_N + 5];

void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    return ;
}

int solve() {
    int ans = n * 5;
    for (int i = 1; i <= n; i++) {
        int op = arr[i] - arr[i - 1];
        if (op > 0) {
            ans += op * 6;
        } else if (op < 0) {
            ans += (-op) * 4;
        } 
    }
    return ans;
}

int main() {
    input();
    cout << solve() << endl;
    return 0;
}
