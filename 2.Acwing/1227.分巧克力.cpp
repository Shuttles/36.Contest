/*************************************************************************
	> File Name: 1227.分巧克力.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2021年04月08日 星期四 21时18分35秒
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


//典型的二分答案
//1111110000找最后一个1
//1.枚举区间为1~max(H[i] || W[i])
//2.判断条件为：可否切出这么多个正方形巧克力

#define MAX_N 100000
int n, k;
int H[MAX_N + 5], W[MAX_N + 5];
int max_len = 0;

void input() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> H[i] >> W[i];
        max_len = max(max_len, H[i]);
        max_len = max(max_len, W[i]);
    }
    return ;
}


bool is_valid(int len) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        if (len > H[i] || len > W[i]) continue;
        int a = H[i] / len, b = W[i] / len;
        sum += (a * b);
        if (sum >= k) return true;
    }
    return false;
}

int binary_search(int l, int r) {
    int head = l - 1, tail = r;
    while (head < tail) {
        int mid = (head + tail + 1) >> 1;
        if (is_valid(mid)) head = mid;
        else tail = mid - 1;
    }
    return (head == l - 1 ? -1 : head);
}

int solve() {
    int ans = binary_search(1, max_len);
    return ans;
}

int main() {
    input();
    cout << solve() << endl;
    return 0;
}
