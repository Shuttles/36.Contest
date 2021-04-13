/*************************************************************************
	> File Name: 1236.递增三元组.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2021年04月13日 星期二 15时40分53秒
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


//经典：利用前缀和来解决一个数组中有多少个数<x的问题！
#define MAX_N 100000
int n;
int a[MAX_N + 5], b[MAX_N + 5], c[MAX_N + 5];
int cnt_a[MAX_N + 5], s_a[MAX_N + 5], cnt_c[MAX_N + 5], s_c[MAX_N + 5];

void input() {
    cin >> n;
    int x;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        a[i] = x + 1;
        cnt_a[a[i]] += 1;
    }
    for (int i = 1; i <= n; i++) {
        cin >> x;
        b[i] = x + 1;
    }
    for (int i = 1; i <= n; i++) {
        cin >> x;
        c[i] = x + 1;
        cnt_c[c[i]] += 1;
    }
    return ;
}

void output() {
    cout << "cnt_a[] : ";
    for (int i = 1; i < 4; i++) {
        cout << cnt_a[i] << " ";
    }
    cout << endl;

    cout << "cnt_c[] : ";
    for (int i = 1; i < 5; i++) {
        cout << cnt_c[i] << " ";
    }
    cout << endl;

    cout << "s_a[] : ";
    for (int i = 1; i < 4; i++) {
        cout << s_a[i] << " ";
    }
    cout << endl;

    cout << "s_c[] : ";
    for (int i = 1; i < 5; i++) {
        cout << s_c[i] << " ";
    }
    cout << endl;
    return ;
}


void init() {
    for (int i = 1; i <= MAX_N + 1; i++) {
        s_a[i] = s_a[i - 1] + cnt_a[i];
        s_c[i] = s_c[i - 1] + cnt_c[i];
    }
    return ;
}


long long solve() {
    init();
    //output();
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += (long long)(s_a[b[i] - 1]) * (s_c[MAX_N + 1] - s_c[b[i]]);
    }
    return ans;
}


int main() {
    input();
    cout << solve() << endl;
    return 0;
}
