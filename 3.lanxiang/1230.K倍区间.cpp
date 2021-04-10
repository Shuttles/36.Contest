/*************************************************************************
	> File Name: 1230.K倍区间.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2021年04月10日 星期六 21时10分32秒
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

//方法1: 先枚举右端点，再枚举左端点　时间复杂度O(n^2)
//方法2: 优化掉里层循环(枚举左端点)，其实只需要知道r左边有几个s[l - 1]  和s[r]%k的余数相等即可，开个数组存一下即可！ O(n)
//        cnt[i]存的是 %k之后余数为i的s[l-1]的数量，是可以一边遍历一边维护的！
#define MAX_N 100000
int n, k;
int arr[MAX_N + 5];
long long s[MAX_N + 5];
int cnt[MAX_N + 5];

void input() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        s[i] = s[i - 1] + arr[i];
    }
    return ;
}

long long solve() {
    long long ans = 0;
    for (int r = 0; r <= n; r++) {//r必须是从0开始的！因为这是优化的数学需要！
        ans += cnt[s[r] % k];
        cnt[s[r] % k] += 1;
        /*
        for (int l = 1; l <= r; l++) {
            if ((s[r] - s[l - 1]) % k) continue;
            ans += 1;
        }*/
    }
    return ans;
}


int main() {
    input();
    cout << solve() << endl;
    return 0;
}
