/*************************************************************************
	> File Name: 789.数的范围.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2021年04月08日 星期四 15时19分05秒
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

//二分查找左端点和右端点即可
#define MAX_N 100000
int n, q;
int arr[MAX_N + 5];


void input() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    return ;
}

//000001111找第一个1
int binary_search_l(int l, int r, int target) {
    int head = l, tail = r + 1;
    while (head < tail) {
        int mid = (head + tail) >> 1;
        if (arr[mid] < target) head = mid + 1;
        else tail = mid;
    }
    return tail;
}

//111110000找最后一个1
int binary_search_r(int l, int r, int target) {
    int head = l - 1, tail = r;
    while (head < tail) {
        int mid = (head + tail + 1) >> 1;
        if (arr[mid] <= target) head = mid;
        else tail = mid - 1;
    }
    return head;
}

void solve() {
    int l, r;
    while (q--) {
        int x;
        cin >> x;
        l = binary_search_l(1, n, x);//左端点是>=x的第一个
        if (l == n + 1 || arr[l] - x) cout << "-1 -1" << endl;//如果找到了，还可能不是要找的数！
        else {
            r = binary_search_r(l, n, x);//右端点是<=x的最后一个
            cout << l - 1 << " " << r - 1 << endl;
        }
    }
    return ;
}



int main() {
    input();
    solve();
    return 0;
}
