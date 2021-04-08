/*************************************************************************
	> File Name: 790.数的三次方根.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2021年04月08日 星期四 15时07分36秒
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


double n;

void input() {
    cin >> n;
    return ;
}

double binary_search() {
    double head = -10000, tail = 10000;
    while (tail - head > 1e-8) {
        double mid = (head + tail) / 2;
        if (mid * mid * mid >= n) tail = mid;
        else head = mid;
    }
    return head;
}

double solve() {
    double ans = binary_search();
    return ans;
}


int main() {
    input();
    printf("%.6lf\n", solve());
    return 0;
}
