/*************************************************************************
	> File Name: 1.closestFib.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2021年03月10日 星期三 09时56分04秒
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


#define MAX_N 100000000
int n;
long long mark[MAX_N + 5];

void input() {
    cin >> n;
    return ;
}

long long fib(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (mark[n]) return mark[n];
    return (mark[n] = fib(n - 1) + fib(n - 2));
}

long long solve() {
    long long min_close = 0x3f3f3f3f, min_num = n;
    for (int i = 0; i <= n; i++) {
        long long diff = abs(n - fib(i));
        if (fib(i) > n && diff > min_close) break;
        if (diff < min_close)  {
            //cout << "原：min_close = " << min_close << ", min_num = " << min_num << ", ";
            min_close = diff, min_num = fib(i);
            //cout << "现：min_close = " << min_close << ", min_num = " << min_num << endl;
        } 
    }
    return min_num;
}

int main() {
    input();
    cout << solve() << endl;
    return 0;
}
