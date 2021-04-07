/*************************************************************************
	> File Name: 795.前缀和.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2021年04月07日 星期三 19时44分59秒
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

//s是前缀和数组, i~j的和就是s[j] - s[i - 1]
#define MAX_N 100000
int n, m;
int arr[MAX_N + 5];
int s[MAX_N + 5];


void input() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        s[i] = s[i - 1] + arr[i];
    }
    return ;
}

void output(int *num, int len) {
    for (int i = 1; i <= len; i++) {
        (i != 1) && cout << " ";
        cout << num[i];
    }
    cout << endl;
    return ;
}

void solve() {
    //output(arr, n);
    //output(s, n);
    while (m--) {
        int l, r;
        cin >> l >> r;
        cout << s[r] - s[l - 1] << endl;
    }
    return ;
}


int main() {
    input();
    solve();
    return 0;
}
