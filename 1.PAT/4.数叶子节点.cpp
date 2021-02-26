/*************************************************************************
	> File Name: 4.数叶子节点.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2021年02月23日 星期二 10时54分02秒
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
int n, m;
int h[MAX_N + 5], e[MAX_N + 5], ne[MAX_N + 5], idx;
int cnt[MAX_N + 5];//存每一层的叶子节点的数量

void input() {
    cin >> n >> m;

}

int main() {
    input();
    solve();
    return 0;
}
