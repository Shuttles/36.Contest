/*************************************************************************
	> File Name: 58.霍格沃兹.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2021年02月20日 星期六 10时26分47秒
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

int a, b, c, d, e, f;

void input() {
    scanf("%d.%d.%d %d.%d.%d", &a, &b, &c, &d, &e, &f);
    return ;
}

void solve() {
    c += f, b += e, a += d;
    b += c / 29;
    c %= 29;
    a += b / 17;
    b %= 17;
    printf("%d.%d.%d\n", a, b, c);
    return;
}

int main() {
    input();
    solve();
    return 0;
}
