/*************************************************************************
	> File Name: 1205.买不到的数目.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2021年04月11日 星期日 21时00分56秒
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

int n, m;

void input() {
    cin >> n >> m;
    return ;
}

int solve() {
    return (n - 1) * (m - 1) - 1;
}


int main() {
    input();
    cout << solve() << endl;
    return 0;
}

