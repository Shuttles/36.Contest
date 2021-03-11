/*************************************************************************
	> File Name: 60.AreTheyEqual.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2021年03月11日 星期四 17时15分27秒
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

int n;
string a, b;

void input() {
    cin >> n >> a >> b;
    return ;
}

void stdify(string str) {

}

void solve() {
    bool flag = false;
    stdify(a), stdify(b);
    str = " " + str;
    for (int i = 1; i <= n && i < a.size() && i < b.size(); i++) {
        if (a[i] != b[i]) break;
    }
    if (i == n + 1) {
        flag = true;
    } else if (i >= a.size())
}


int main() {
    input();
    solve();
    return 0;
}
