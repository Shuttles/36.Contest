/*************************************************************************
	> File Name: 50.字符串减法.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2021年02月19日 星期五 15时13分31秒
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
#include <unordered_set>
#include <string>
#include <vector>
using namespace std;

string s1, s2;

void input() {
    getline(cin, s1);//因为这个字符串包含空格，所以不能直接cin>>
    getline(cin, s2);
    return ;
}

void solve() {
    unordered_set<char> hash;
    for (auto iter : s2) {
        hash.insert(iter);
    }
    
    string ans;
    for (auto iter : s1) {
        if (hash.count(iter)) continue;
        ans += iter;
    }
    cout << ans << endl;
    return ;
}

int main() {
    input();
    solve();
    return 0;
}
